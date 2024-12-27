#include "ui.h"
#include "screen/screen.h"
#include "port/lv_port_disp.h"
#include "port/lv_port_indev.h"
#include "pin_config.h"
#include <WiFi.h>
#include <FastLED.h>
#include "EEPROM.h"
#include <ESP32Servo.h>
/*********************************************************************************
 *                              EXTERN
 *********************************************************************************/
extern Arduino_GFX *gfx;

extern uint16_t brightness_level;
extern bool touch_line_state;
extern uint16_t input_mode;
extern bool menu_label_align_to_tgt;
/*********************************************************************************
 *                              TYPEDEFS
 *********************************************************************************/
// wifi
const char* ssid = "xinyuandianzi";
const char* password = "AA15994823428";
const char *ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";
bool is_connect_wifi = false;
static struct tm timeinfo;
static uint32_t last_tick;
// ws2812
static CRGB ws2812_leds[WS2812B_LED_NUM];
// eeprom
uint8_t eeprom_buf[EEPROM_SIZE_MAX] = {0};
// servo motor
Servo myservo;

static bool ui_init = false;
/*********************************************************************************
 *                              FUNCTION
 *********************************************************************************/
void eeprom_write(int addr, uint8_t val)
{
    eeprom_buf[EEPROM_UPDATA_FLAG_ADDR] = EEPROM_UPDATA_FLAG_NUM;
    eeprom_buf[addr] = val;

    for(int i = 0; i < EEPROM_SIZE_MAX; i++){
        EEPROM.write(i, eeprom_buf[i]);
    }
    EEPROM.commit();
    for (int i = 0; i < EEPROM_SIZE_MAX; i++) {
        Serial.print(byte(EEPROM.read(i))); Serial.print(" ");
    }
    Serial.println("");
}

static void msg_subsribe_event(void * s, lv_msg_t * msg)
{
    LV_UNUSED(s);

    switch (msg->id)
    {
        case MSG_DISP_BRIGHTNESS:{
            static uint8_t prev_val = 0;
            uint16_t *v = (uint16_t *)lv_msg_get_payload(msg);
            if(prev_val != *v){
                prev_val = *v;
                uint8_t tmp = lv_map(*v, 1, 10, 50, 255);
                gfx->Display_Brightness(tmp);
                eeprom_write(EEPROM_DISPLAY_LIGHT_ADDR, prev_val);
            }
            break;
        }
        case MSG_TOUCH_LINE:{
            bool *v = (bool *)lv_msg_get_payload(msg);
            in_indev_touchpad_line_en(*v);
            eeprom_write(EEPROM_TOUCH_LINE_ADDR, byte(*v));
            break;
        }
        case MSG_INDEV_MODE:{
            uint16_t *v = (uint16_t *)lv_msg_get_payload(msg);
            eeprom_write(EEPROM_INDEV_MODE_ADDR, byte(*v));
            break;
        }
        case MSG_MENU_LABEL_ALIGN:{
            bool *v = (bool *)lv_msg_get_payload(msg);
            eeprom_write(EEPROM_MENU_LABEL_ADDR, byte(*v));
            break;
        }
        case MSG_WS2812_LIGHT:{
            int32_t *v = (int32_t *)lv_msg_get_payload(msg);
            printf("ws2812 light = %d\n", *v);
            FastLED.setBrightness(*v);
            FastLED.show();
            break;
        }
        case MSG_WS2812_COLOR:{
            uint8_t *v = (uint8_t *)lv_msg_get_payload(msg);
            CRGB c;
            c.red = v[0];
            c.green = v[1];
            c.blue = v[2];
            printf("r=0x%x, g=0x%x, b=0x%x\n",c.red, c.green, c.blue);
            for(int i = 0; i < WS2812B_LED_NUM; i++){
                uint32_t t = c.red << 16 | c.green << 8 | c.blue;
                ws2812_leds[i] = c;
            }
            // FastLED.show();
            break;
        }
        case MSG_METER_SPEED:{
            int32_t *v = (int32_t *)lv_msg_get_payload(msg);
            printf("ws2812 light = %d\n", *v);
            FastLED.setBrightness(*v);
            FastLED.show();
            break;
        }
        case MSG_METER_TEMPERTRUE:{
            int32_t *v = (int32_t *)lv_msg_get_payload(msg);
            printf("speed_value=%d\n", *v);
            break;
        }
        default:
            break;
    }
}

static void msg_send_event(lv_timer_t *t)
{
    if(screen1_no_exit == true && is_connect_wifi == true){
        if (!getLocalTime(&timeinfo)){
            Serial.println("Failed to obtain time");
            return;
        }
        Serial.println(&timeinfo, "%F %T %A"); // 格式化输出
        timeinfo.tm_hour = timeinfo.tm_hour % 12;
        lv_msg_send(MSG_CLOCK_HOUR, &timeinfo.tm_hour);
        lv_msg_send(MSG_CLOCK_MINUTE, &timeinfo.tm_min);
        lv_msg_send(MSG_CLOCK_SECOND, &timeinfo.tm_sec);
    }
    // eeprom_write(-1, 0);

    static int cnt = 0;
    cnt++;
    if((cnt > 4) && (ui_init == false)) {
        ui_init = true;
        ui_entry();
    }
}

void wifi_init(void)
{
    WiFi.begin(ssid, password);
    wl_status_t wifi_state = WiFi.status();
    last_tick = millis();
    while (wifi_state != WL_CONNECTED){
        delay(500);
        Serial.print(".");
        wifi_state = WiFi.status();
        if(wifi_state == WL_CONNECTED){
            is_connect_wifi = true;
            Serial.println("WiFi connected!");
            configTime(8 * 3600, 0, ntpServer1, ntpServer2);
            break;
        }
        if (millis() - last_tick > 5000) {
            Serial.println("WiFi connected falied!");
            last_tick = millis();
            break;
        }
    }
}

void eeproom_init(void)
{
    if (!EEPROM.begin(EEPROM_SIZE_MAX)) {
        Serial.println("failed to initialise EEPROM"); delay(1000000);
    }
    Serial.println(" bytes read from Flash . Values are:");

    for (int i = 0; i < EEPROM_SIZE_MAX; i++) {
        eeprom_buf[i] = EEPROM.read(i);
        Serial.print(byte(EEPROM.read(i))); Serial.print(" ");
    }

    uint8_t frist_read = eeprom_buf[EEPROM_UPDATA_FLAG_ADDR];
    Serial.printf(" read = %d\n", frist_read);
    if(frist_read == EEPROM_UPDATA_FLAG_NUM){
        brightness_level = eeprom_buf[EEPROM_DISPLAY_LIGHT_ADDR];
        touch_line_state = eeprom_buf[EEPROM_TOUCH_LINE_ADDR];
        input_mode = eeprom_buf[EEPROM_INDEV_MODE_ADDR];
        menu_label_align_to_tgt = eeprom_buf[EEPROM_MENU_LABEL_ADDR];

        in_indev_touchpad_line_en(touch_line_state);
        uint8_t tmp = lv_map(brightness_level, 1, 10, 50, 255);
        gfx->Display_Brightness(tmp);
    }else{
        lv_memset_00(eeprom_buf, EEPROM_SIZE_MAX);
        eeprom_buf[EEPROM_UPDATA_FLAG_ADDR]= EEPROM_UPDATA_FLAG_NUM;
        eeprom_buf[EEPROM_DISPLAY_LIGHT_ADDR]= 10;
        eeprom_buf[EEPROM_TOUCH_LINE_ADDR]= 0;
        eeprom_buf[EEPROM_INDEV_MODE_ADDR]= 0;
        eeprom_buf[EEPROM_MENU_LABEL_ADDR]= 0;
        for(int i = EEPROM_UPDATA_FLAG_ADDR; i < EEPROM_SIZE_MAX; i++){
            EEPROM.write(i, eeprom_buf[i]);
        }
        EEPROM.commit();
    }
}

int calculatePWM(int pos)
{   
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
    }
    return 0;
}


TaskHandle_t servo_handle;
int touch_state;
int pos;
void servo_task(void *param)
{
    while (1)
    {
        if(touch_state == LOW){
            for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
                myservo.write(pos);              // tell servo to go to position in variable 'pos'
                delay(15);                       // waits 15 ms for the servo to reach the position
                if(pos == 180) {
                    vTaskSuspend(servo_handle);
                    Serial.println("servo suspend");
                }
            }
        }else{
            for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
                myservo.write(pos);    // tell servo to go to position in variable 'pos'
                delay(15);             // waits 15ms for the servo to reach the position
                if(pos == 0) {
                    vTaskSuspend(servo_handle);
                    Serial.println("servo suspend");
                }
            }
        }
    }
}

void touch_btn_irq_event(void)
{
    touch_state = digitalRead(TOUCH_KEY_PRESS_PIN);
    vTaskResume(servo_handle);
    Serial.printf("Touch curr %s\n", touch_state == LOW ? "LOW" : "HIGH");
}

void setup()
{
    Serial.begin(115200);

    delay(3000);

    pinMode(TOUCH_KEY_PRESS_PIN, INPUT); // Touch Btn
    ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(SERVO_MOTORS, 1000, 2000);
    attachInterrupt(TOUCH_KEY_PRESS_PIN, touch_btn_irq_event, CHANGE);

    wifi_init();

    lv_init();

    lv_port_disp_init();

    lv_port_indev_init();
    
    // ui_entry();

    eeproom_init();

    lv_timer_create(msg_send_event, 1000, NULL);
    
    // ws2812
    FastLED.addLeds<WS2812B, WS2812B_DATA, GRB>(ws2812_leds, WS2812B_LED_NUM); // GRB ordering is typical
    for(int i = 0; i < WS2812B_LED_NUM; i++){
        ws2812_leds[i] = 0x8617fd;
    }
    FastLED.setBrightness(0);
    FastLED.show();
    
    // lvgl msg
    lv_msg_subsribe(MSG_DISP_BRIGHTNESS, msg_subsribe_event, NULL);
    lv_msg_subsribe(MSG_TOUCH_LINE, msg_subsribe_event, NULL);
    lv_msg_subsribe(MSG_INDEV_MODE, msg_subsribe_event, NULL);
    lv_msg_subsribe(MSG_MENU_LABEL_ALIGN, msg_subsribe_event, NULL);
    lv_msg_subsribe(MSG_WS2812_LIGHT, msg_subsribe_event, NULL);
    lv_msg_subsribe(MSG_WS2812_COLOR, msg_subsribe_event, NULL);
    lv_msg_subsribe(MSG_METER_SPEED, msg_subsribe_event, NULL);
    lv_msg_subsribe(MSG_METER_TEMPERTRUE, msg_subsribe_event, NULL);

    xTaskCreate(servo_task, "servo_task", 1024 * 3, NULL, 2, &servo_handle);


    lv_obj_t *img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &electronic_tag);
    lv_obj_center(img);
}

int16_t angle = 0;
int16_t ws2812_cnt=0;
void ws2812_eff1(void)
{
    if(FastLED.getBrightness() == 0) {
        return;
    }

    ws2812_cnt++;
    if(ws2812_cnt > 5){
        ws2812_cnt = 0;
        angle += 1;
        for(int i = 0; i < WS2812B_LED_NUM; i++){
            int16_t a = lv_trigo_sin(angle + i*5);
            CRGB c;
            c.red = lv_map(a, -32767, 32767, 0, 255);
            // c.green = lv_map(a, -32767, 32767, 0, 255);
            // c.blue = lv_map(a, -32767, 32767, 0, 255);
            ws2812_leds[i] = c;
        }
        FastLED.show();
    }
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay(1);

    ws2812_eff1();
}
