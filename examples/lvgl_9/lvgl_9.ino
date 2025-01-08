#include <lvgl.h>
#include "Arduino_GFX_Library.h"
#include "pin_config.h"
#include "ui.h"
#include "TouchDrvCHSC5816.hpp"

/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// DXQ120MYB2416A
Arduino_DataBus *bus = new Arduino_ESP32QSPI(
    SCREEN_CS /* CS */, SCREEN_SCLK /* SCK */, SCREEN_SDIO0 /* SDIO0 */,
    SCREEN_SDIO1 /* SDIO1 */, SCREEN_SDIO2 /* SDIO2 */, SCREEN_SDIO3 /* SDIO3 */);

Arduino_GFX *gfx = new Arduino_SH8601(bus, SCREEN_RST /* RST */, 0 /* rotation */,
                                      false /* IPS */, SCREEN_WIDTH, SCREEN_HEIGHT);
                                      
lv_ui system_ui;

TouchDrvCHSC5816 touch;
TouchDrvInterface *pTouch;

void CHSC5816_Initialization(void)
{
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
}

/* LVGL calls it when a rendered image needs to copied to the display*/
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    uint32_t w = lv_area_get_width(area);
    uint32_t h = lv_area_get_height(area);

    gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)px_map, w, h);

    /*Call it to tell LVGL you are ready*/
    lv_display_flush_ready(disp);
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data)
{
    int16_t Touch_x[2], Touch_y[2];
    uint8_t touchpad = touch.getPoint(Touch_x, Touch_y);

    if (touchpad > 0)
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = Touch_x[0];
        data->point.y = Touch_y[0];

        // Serial.print("Data x ");
        // Serial.printf("%d\n", x[0]);

        // Serial.print("Data y ");
        // Serial.printf("%d\n", y[0]);
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
}

/*use Arduinos millis() as tick source*/
static uint32_t my_tick(void)
{
    return millis();
}

void lvgl_init(void)
{
    lv_init();

    /*Set a tick source so that LVGL will know how much time elapsed. */
    lv_tick_set_cb(my_tick);

    lv_display_t *disp;
    /*Else create a display yourself*/
    disp = lv_display_create(SCREEN_WIDTH, SCREEN_HEIGHT);
    lv_display_set_flush_cb(disp, my_disp_flush);
    lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

    /*Initialize the (dummy) input device driver*/
    lv_indev_t *indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER); /*Touchpad should have POINTER type*/
    lv_indev_set_read_cb(indev, my_touchpad_read);
}

void setup()
{
    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.begin(115200);
    Serial.println(LVGL_Arduino);

    pinMode(SCREEN_EN, OUTPUT);
    digitalWrite(SCREEN_EN, HIGH);

    CHSC5816_Initialization();

    gfx->begin(40000000);
    gfx->fillScreen(BLACK);

    for (int i = 0; i <= 255; i++)
    {
        gfx->Display_Brightness(i);
        delay(3);
    }

    lvgl_init();
    ui_init(&system_ui);
}

void loop()
{
    lv_timer_handler();
    delay(5); /* let this time pass */
}
