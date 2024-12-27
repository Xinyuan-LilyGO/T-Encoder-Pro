#include "screen.h"
/*********************************************************************************
 *                              SCREEN6
 *********************************************************************************/
static lv_obj_t * slider_label;
int32_t slider_val = 0;

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[16];
    slider_val = (int)lv_slider_get_value(slider);
    lv_snprintf(buf, sizeof(buf), "ws2812:%d%%", slider_val);
    lv_label_set_text(slider_label, buf);
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

    slider_val = lv_map(slider_val, 0, 100, 0, 255);
    lv_msg_send(MSG_WS2812_LIGHT, &slider_val);
}

void create6(lv_obj_t *parent)
{
    back_btn_hidden(false);
    
    lv_obj_t * slider = lv_slider_create(parent);
    lv_obj_center(slider);
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    /*Create a label below the slider*/
    slider_label = lv_label_create(parent);
    lv_label_set_text(slider_label, "ws2812:0%");
    lv_slider_set_value(slider_label, slider_val, LV_ANIM_OFF);

    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
}
void entry6(void) {}
void exit6(void) {}
void destroy6(void) {
    back_btn_hidden(true);
}

scr_lifecycle_t scr_ws2812 = {
    .create = create6,
    .entry = entry6,
    .exit = exit6,
    .destroy = destroy6,
};