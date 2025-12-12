/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "lvgl.h"
#include "pin_config.h"
#include  "Arduino.h"
#include "TouchDrvCHSC5816.hpp"
#include "Arduino_DriveBus_Library.h"
#include "pin_config.h"
#include "ui.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void touchpad_init(void);
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static bool touchpad_is_pressed(void);
static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y);

static void encoder_init(void);
static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static void encoder_handler(void);

volatile bool encoder_enabled = true;
volatile bool touchpad_enabled = true;
/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;
lv_indev_t * indev_encoder;

static int32_t encoder_diff;
static lv_indev_state_t encoder_state;
int touch_x = 0;
int touch_y = 0;
int encoder_direction = 0;

#if defined DXQ120MYB2416A

TouchDrvCHSC5816 touch;
TouchDrvInterface *pTouch;

#elif defined TFD12MASBCTB4_V0_07

std::shared_ptr<Arduino_IIC_DriveBus> IIC_Bus =
    std::make_shared<Arduino_HWIIC>(IIC_SDA, IIC_SCL, &Wire);

void Arduino_IIC_Touch_Interrupt(void);

std::unique_ptr<Arduino_IIC> CST816D(new Arduino_CST816x(IIC_Bus, CST816D_DEVICE_ADDRESS,
                                                         TOUCH_RST, TOUCH_INT, Arduino_IIC_Touch_Interrupt));

void Arduino_IIC_Touch_Interrupt(void)
{
    CST816D->IIC_Interrupt_Flag = true;
}
#else
#error "Unknown macro definition. Please select the correct macro definition."
#endif


/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
    /**
     * Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    static lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad if you have*/
    touchpad_init();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    indev_touchpad = lv_indev_drv_register(&indev_drv);

    /*------------------
     * Encoder
     * -----------------*/

    static lv_indev_drv_t indev_drv1;
    /*Initialize your encoder if you have*/
    encoder_init();

    /*Register a encoder input device*/
    lv_indev_drv_init(&indev_drv1);
    indev_drv1.type = LV_INDEV_TYPE_ENCODER;
    indev_drv1.read_cb = encoder_read;
    indev_encoder = lv_indev_drv_register(&indev_drv1);
    lv_group_t *group = lv_group_create();
    lv_indev_set_group(indev_encoder, group);
    lv_group_set_default(group);

    /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     *add objects to the group with `lv_group_add_obj(group, obj)`
     *and assign this input device to group to navigate in it:
     *`lv_indev_set_group(indev_encoder, group);`*/
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Touchpad
 * -----------------*/
bool touch_line_en = false;
static lv_point_t line_x_points[] = { {0, 0}, {0, 0} };
static lv_point_t line_y_points[] = { {0, 0}, {0, 0} };
lv_obj_t *line_x;
lv_obj_t *line_y;
void touch_line(lv_indev_data_t *data)
{
    if (data->state == true) {
        // printf("x=%d\t y=%d\n", mouse_data.point.x, mouse_data.point.y);
        line_x_points[0].x = data->point.x;
        line_x_points[0].y = 0;
        line_x_points[1].x = data->point.x;
        line_x_points[1].y = LCD_WIDTH;
        lv_line_set_points(line_x, line_x_points, 2);
        line_y_points[0].x = 0;
        line_y_points[0].y = data->point.y;
        line_y_points[1].x = LCD_WIDTH;
        line_y_points[1].y = data->point.y;
        lv_line_set_points(line_y, line_y_points, 2);
        lv_obj_clear_flag(line_x, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(line_y, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(line_x, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(line_y, LV_OBJ_FLAG_HIDDEN);
    }
}

void lv_indev_encode_en(bool en){
    encoder_enabled = en;
}

void lv_indev_touchpad_en(bool en){
    touchpad_enabled = en;
}

void in_indev_touchpad_line_en(bool en){
    touch_line_en = en;
}
/*Initialize your touchpad*/
static void touchpad_init(void)
{
#if defined DXQ120MYB2416A
    /*Your code comes here*/
    TouchDrvCHSC5816 *pd1 = static_cast<TouchDrvCHSC5816 *>(pTouch);

    touch.setPins(TOUCH_RST, TOUCH_INT);
    if (!touch.begin(Wire, CHSC5816_SLAVE_ADDRESS, IIC_SDA, IIC_SCL))
    {
        Serial.println("Failed to find CHSC5816 - check your wiring!");
        while (1)
        {
            delay(1000);
        }
    }
    Serial.println("Init CHSC5816 Touch device success!");
#elif defined TFD12MASBCTB4_V0_07
    if (CST816D->begin() == false)
    {
        Serial.println("CST816D initialization fail");
    }
    else
    {
        Serial.println("CST816D initialization successfully");

        // 中断模式为检测到触摸时，发出低脉冲
        CST816D->IIC_Write_Device_State(CST816D->Arduino_IIC_Touch::Device::TOUCH_DEVICE_INTERRUPT_MODE,
                                        CST816D->Arduino_IIC_Touch::Device_Mode::TOUCH_DEVICE_INTERRUPT_PERIODIC);
    }
#else
#error "Unknown macro definition. Please select the correct macro definition."
#endif

    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 1);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_line_rounded(&style_line, false);
    /*Create a line and apply the new style*/
    line_x = lv_line_create(lv_layer_sys());
    // lv_line_set_points(line_x, line_x_points, 2);     /*Set the points*/
    lv_obj_add_style(line_x, &style_line, 0);
    line_y = lv_line_create(lv_layer_sys());
    // lv_line_set_points(line_x, line_x_points, 2);     /*Set the points*/
    lv_obj_add_style(line_y, &style_line, 0);
    lv_obj_add_flag(line_x, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(line_y, LV_OBJ_FLAG_HIDDEN);
}

/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
#if defined DXQ120MYB2416A
    if(touchpad_enabled){
        int16_t x[2], y[2];
        uint8_t touchpad = touch.getPoint(x, y);

        if (touchpad > 0) {
            data->state = LV_INDEV_STATE_PR;

            data->point.x = x[0];
            data->point.y = y[0];

            touch_x = data->point.x;
            touch_y = data->point.y;

            // Serial.print("x=");Serial.print(data->point.x);
            // Serial.print(", y=");Serial.println(data->point.y);
        }
        else {
            data->state = LV_INDEV_STATE_REL;
        }

        if(touch_line_en)
            touch_line(data);
    }
    lv_msg_send(MSG_INDEV_TOUCH_X, &touch_x);
    lv_msg_send(MSG_INDEV_TOUCH_Y, &touch_y);

#elif defined TFD12MASBCTB4_V0_07
    if(touchpad_enabled){
        if (CST816D->IIC_Read_Device_Value(CST816D->Arduino_IIC_Touch::Value_Information::TOUCH_FINGER_NUMBER) > 0)
        {

            data->state = LV_INDEV_STATE_PR;

            /*Set the coordinates*/
            data->point.x = (uint32_t)CST816D->IIC_Read_Device_Value(CST816D->Arduino_IIC_Touch::Value_Information::TOUCH_COORDINATE_X);
            data->point.y = (uint32_t)CST816D->IIC_Read_Device_Value(CST816D->Arduino_IIC_Touch::Value_Information::TOUCH_COORDINATE_Y);

            touch_x = data->point.x;
            touch_y = data->point.y;
            // Serial.print("Data x ");
            // Serial.printf("%d\n", x[0]);

            // Serial.print("Data y ");
            // Serial.printf("%d\n", y[0]);
        }
        else
        {
            data->state = LV_INDEV_STATE_REL;
        }
        if(touch_line_en)
            touch_line(data);
    }
    lv_msg_send(MSG_INDEV_TOUCH_X, &touch_x);
    lv_msg_send(MSG_INDEV_TOUCH_Y, &touch_y);
#else
#error "Unknown macro definition. Please select the correct macro definition."
#endif
    
}

/*Return true is the touchpad is pressed*/
static bool touchpad_is_pressed(void)
{
    /*Your code comes here*/

    return false;
}

/*Get the x and y coordinates if the touchpad is pressed*/
static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y)
{
    /*Your code comes here*/

    (*x) = 0;
    (*y) = 0;
}

/*------------------
 * Encoder
 * -----------------*/

/*Initialize your keypad*/
static void encoder_init(void)
{
    /*Your code comes here*/
    pinMode(ENCODE_A_PIN, INPUT);
    pinMode(ENCODE_B_PIN, INPUT);
    pinMode(ENCODE_K_PIN, INPUT);
    attachInterrupt(ENCODE_A_PIN, encoder_handler, CHANGE);
}

/*Will be called by the library to read the encoder*/
static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    if(encoder_enabled){
        if(encoder_diff == 1){
            data->enc_diff = 1;
            encoder_state = LV_INDEV_STATE_REL;
        }else if(encoder_diff == -1){
            data->enc_diff = -1;
            encoder_state = LV_INDEV_STATE_REL;
        }
        encoder_diff = 0;

        if (digitalRead(ENCODE_K_PIN) == LOW) {
            encoder_state = LV_INDEV_STATE_PR;
        } else if (digitalRead(ENCODE_K_PIN) == HIGH) { 
            encoder_state = LV_INDEV_STATE_REL;
        }
        data->state = encoder_state;
    }
    lv_msg_send(MSG_INDEV_ENCODER, &encoder_direction);
}

/*Call this function in an interrupt to process encoder events (turn, press)*/
static void encoder_handler(void)
{
    /*Your code comes here*/
    int alv = digitalRead(ENCODE_A_PIN);
    int blv = digitalRead(ENCODE_B_PIN);
    
    if(alv != blv){
        encoder_direction++;
        encoder_diff = 1;
    }else if(alv == blv) {
        encoder_direction--;
        encoder_diff = -1;
    }
    // Serial.printf("A:%d, B:%d, S:%d\n",alv, blv, encoder_direction);
    // encoder_diff += 0;
    // encoder_state = LV_INDEV_STATE_REL;
}

#endif