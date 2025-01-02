#include "screen.h"
#include <WiFi.h>
/*********************************************************************************
 *                              EXTERN
 *********************************************************************************/
extern bool is_connect_wifi;

/*********************************************************************************
 *                              SCREEN2
 *********************************************************************************/
static void slider_event_cb(lv_event_t * e);
static lv_obj_t * slider_label;

static volatile bool smartConfigStart      = false;
static lv_timer_t   *wifi_timer            = NULL;
static uint32_t      wifi_timer_counter    = 0;
static uint32_t      wifi_connnect_timeout = 60;

static void wifi_config_event_handler(lv_event_t *e)
{
    lv_event_code_t code  = lv_event_get_code(e);
    lv_obj_t       *btn   = (lv_obj_t *)lv_event_get_target(e);
    lv_obj_t       *label = (lv_obj_t *)lv_event_get_user_data(e);
    if (code == LV_EVENT_CLICKED) {
        if (smartConfigStart) {
            lv_label_set_text(label, "Config Start");
            if (wifi_timer) {
                lv_timer_del(wifi_timer);
                wifi_timer = NULL;
            }
            WiFi.stopSmartConfig();
            lv_obj_clear_state(btn, LV_STATE_CHECKED);
            Serial.println("return smart Config has Start;");
            smartConfigStart = false;
            return;
        }
        WiFi.disconnect();
        smartConfigStart = true;
        WiFi.beginSmartConfig();
        lv_label_set_text(label, "Config Stop");
        lv_obj_add_state(btn, LV_STATE_CHECKED);

        wifi_timer = lv_timer_create([](lv_timer_t *t) {
            lv_obj_t *btn     = (lv_obj_t *)t->user_data;
            lv_obj_t *label   = lv_obj_get_child(btn, 0);
            bool      destory = false;
            wifi_timer_counter++;
            if (wifi_timer_counter > wifi_connnect_timeout && !WiFi.isConnected()) {
                Serial.println("Connect timeout!");
                destory = true;
                lv_label_set_text(label, "Time Out");
            }
            if (WiFi.isConnected()) {
                Serial.println("WiFi has connected!");
                Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
                Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
                destory   = true;
                String IP = WiFi.localIP().toString();
                lv_label_set_text(label, IP.c_str());
                is_connect_wifi = true;
            }
            if (destory) {
                WiFi.stopSmartConfig();
                smartConfigStart = false;
                lv_timer_del(wifi_timer);
                wifi_timer         = NULL;
                wifi_timer_counter = 0;
                lv_obj_clear_state(btn, LV_STATE_CHECKED);
            }
            // Every seconds check conected
        },
                                     1000, btn);
    }
}

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[8];
    lv_snprintf(buf, sizeof(buf), "%d%%", (int)lv_slider_get_value(slider));
    lv_label_set_text(slider_label, buf);
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
}

void create2(lv_obj_t *parent)
{
    back_btn_hidden(false);

    lv_obj_t *img = lv_img_create(parent);
    lv_img_set_src(img, &QR_code);
    lv_obj_align(img, LV_ALIGN_CENTER, 0, -10);

    lv_obj_t *btn = lv_btn_create(parent);
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Config WiFi");
    lv_obj_center(label);
    lv_obj_set_width(btn, 120);
    // lv_obj_set_style_text_font(label, &lv_font_montserrat_24, 0);
    lv_obj_set_style_text_color(label, lv_color_white(), LV_PART_MAIN);
    lv_obj_add_event_cb(btn, wifi_config_event_handler, LV_EVENT_CLICKED, label);

    lv_obj_align_to(btn, img, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
}
void entry2(void) {}
void exit2(void) { }
void destroy2(void) {
    back_btn_hidden(true);
}

scr_lifecycle_t scr_home = {
    .create = create2,
    .entry = entry2,
    .exit = exit2,
    .destroy = destroy2,
};