#include "screen.h"
/*********************************************************************************
 *                              SCREEN7
 *********************************************************************************/

lv_obj_t *colorwheel;
lv_obj_t *colorwheel_btn = NULL;
lv_color_t colorwheel_color;
uint8_t colorwheel_buf[3] = {0};

void colorwheel_focus_event(lv_event_t *e)
{
    lv_obj_t *instance = lv_event_get_target(e);
    if(e->code == LV_EVENT_CLICKED){
        if (!lv_obj_has_flag(instance, LV_OBJ_FLAG_CHECKABLE)) {
            lv_obj_clear_flag(instance, LV_OBJ_FLAG_CHECKABLE);
            lv_group_set_editing(encode_group, false);
        } else {
            lv_obj_add_flag(instance, LV_OBJ_FLAG_CHECKABLE);
            lv_group_set_editing(encode_group, true);
        }
    }
    else if(e->code == LV_EVENT_VALUE_CHANGED){
        colorwheel_color = lv_colorwheel_get_rgb(colorwheel);
        lv_obj_set_style_bg_color(colorwheel_btn, colorwheel_color, LV_PART_MAIN);

        lv_color32_t c32;
        c32.full = lv_color_to32(colorwheel_color);
        colorwheel_buf[0] = c32.ch.red;
        colorwheel_buf[1] = c32.ch.green;
        colorwheel_buf[2] = c32.ch.blue;
        lv_msg_send(MSG_WS2812_COLOR, &colorwheel_buf);
        // printf("full=0x%x, r=0x%x, g=0x%x, b=0x%x\n",c.full, c.ch.red, c.ch.green, c.ch.blue);
    }
}

void create7(lv_obj_t *parent) {
    back_btn_hidden(false);

    colorwheel_btn = lv_btn_create(parent);
    lv_obj_set_size(colorwheel_btn, 50, 50);
    lv_obj_set_style_border_width(colorwheel_btn, 0, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(colorwheel_btn, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(colorwheel_btn, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(colorwheel_btn, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    lv_obj_center(colorwheel_btn);

    colorwheel = lv_colorwheel_create(parent, true);
    lv_obj_set_size(colorwheel, 200, 200);
    lv_obj_center(colorwheel);
    // lv_colorwheel_set_rgb(colorwheel, colorwheel_color);
    lv_obj_set_style_outline_pad(colorwheel, 4, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(colorwheel, LV_RADIUS_CIRCLE, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(colorwheel, 2, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(colorwheel, lv_color_hex(0x8617fd), LV_STATE_FOCUS_KEY);
    lv_group_add_obj(encode_group, colorwheel);
    lv_obj_add_event_cb(colorwheel, colorwheel_focus_event, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(colorwheel, colorwheel_focus_event, LV_EVENT_VALUE_CHANGED, NULL);
}
void entry7(void) {  }
void exit7(void) {    }
void destroy7(void) { 
    back_btn_hidden(true);
}

scr_lifecycle_t scr_colorwheel = {
    .create = create7,
    .entry = entry7,
    .exit  = exit7,
    .destroy = destroy7,
};