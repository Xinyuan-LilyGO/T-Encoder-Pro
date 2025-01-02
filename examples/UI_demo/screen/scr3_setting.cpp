#include "screen.h"
/*********************************************************************************
 *                              EXTERN
 *********************************************************************************/
extern Arduino_GFX *gfx;
extern int encoder_direction;

extern void lv_indev_encode_en(bool flag);
extern void lv_indev_touchpad_en(bool flag);

extern bool menu_label_align_to_tgt;
/*********************************************************************************
 *                              SCREEN3
 *********************************************************************************/
#define INPUT_TOUCH_ENCODER 0
#define INPUT_ONLY_TOUCH    1
#define INPUT_ONLY_ENCODER  2

lv_obj_t *setting_obj;
lv_obj_t *setting_item1;
lv_obj_t *setting_item2;
lv_obj_t *setting_item3;
lv_obj_t *setting_item4;
lv_obj_t *setting_item5;
lv_obj_t *setting_item6;

uint16_t brightness_level = 10;
uint16_t input_mode = INPUT_TOUCH_ENCODER;
bool touch_line_state = false;


void setting_item_event(lv_event_t *e)
{
    int user_data = (int)e->user_data;

    if(e->code == LV_EVENT_CLICKED){
        
    }
}

void brightness_adjust(lv_event_t *e)
{
    lv_obj_t *slider = lv_event_get_target(e);
    lv_obj_t *label = (lv_obj_t *)e->user_data;

    if(e->code == LV_EVENT_VALUE_CHANGED){
        brightness_level = (int)lv_slider_get_value(slider);
        lv_label_set_text_fmt(label, "%d", brightness_level);
        lv_obj_center(label);
        lv_msg_send(MSG_DISP_BRIGHTNESS, &brightness_level);
    }
}

void touch_line_event(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    int user_data = (int)lv_event_get_user_data(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        switch (user_data)
        {
        case 2:
            touch_line_state = lv_obj_has_state(obj, LV_STATE_CHECKED);
            lv_msg_send(MSG_TOUCH_LINE, &touch_line_state);
            break;
        case 4:
            menu_label_align_to_tgt = lv_obj_has_state(obj, LV_STATE_CHECKED);
            lv_msg_send(MSG_MENU_LABEL_ALIGN, &menu_label_align_to_tgt);
            break;
        default:
            break;
        }
    }
}

void input_mode_event(lv_event_t *e)
{
    lv_obj_t *slider = lv_event_get_target(e);
    lv_obj_t *label = (lv_obj_t *)e->user_data;

    if(e->code == LV_EVENT_CLICKED){
        input_mode++;
        if(input_mode > INPUT_ONLY_ENCODER){
            input_mode = INPUT_TOUCH_ENCODER;
        }
        switch (input_mode){
            case INPUT_TOUCH_ENCODER: 
                lv_label_set_text(label, "T & E");
                lv_indev_encode_en(true);
                lv_indev_touchpad_en(true);
                break;
            case INPUT_ONLY_TOUCH:    
                lv_label_set_text(label, "Touch");
                lv_indev_encode_en(false);
                lv_indev_touchpad_en(true);
            break;
            case INPUT_ONLY_ENCODER:  
                lv_label_set_text(label, "Encoder");
                lv_indev_encode_en(true);
                lv_indev_touchpad_en(false);
            break;
            default:break;
        }
        lv_msg_send(MSG_INDEV_MODE, &input_mode);
    }
}

void create3(lv_obj_t *parent)
{
    back_btn_hidden(false);

    lv_obj_t *label = lv_label_create(parent);
    lv_label_set_text(label, "Setting");
    lv_obj_set_size(label, 280, 60);
    lv_obj_set_style_bg_opa(label, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_bg_color(label, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    lv_obj_set_style_text_color(label, lv_color_hex(COLOR_ACCENT1), LV_PART_MAIN);
    lv_obj_set_style_pad_top(label, 20, LV_PART_MAIN);
    lv_obj_set_style_outline_width(label, 2, LV_PART_MAIN);
    lv_obj_set_style_text_line_space(label, 10, LV_PART_MAIN);
    lv_obj_set_style_text_letter_space(label, 10, LV_PART_MAIN);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_26, LV_PART_MAIN);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);

    setting_obj = lv_list_create(parent);
    lv_obj_set_size(setting_obj, 300, 300);
    lv_obj_align(setting_obj, LV_ALIGN_CENTER, 0, 15);
    lv_obj_set_style_bg_color(setting_obj, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    lv_obj_set_style_pad_row(setting_obj, 2, LV_PART_MAIN);
    lv_obj_set_style_border_width(setting_obj, 0, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(setting_obj, 0, LV_PART_MAIN);

    // add item
    setting_item1 = lv_list_add_btn(setting_obj, LV_SYMBOL_SETTINGS, "Brightness");
    setting_item2 = lv_list_add_btn(setting_obj, LV_SYMBOL_SETTINGS, "Touch Line EN");
    setting_item3 = lv_list_add_btn(setting_obj, LV_SYMBOL_SETTINGS, "Input Mode");
    setting_item4 = lv_list_add_btn(setting_obj, LV_SYMBOL_SETTINGS, "Menu Label Align");
    // setting_item5 = lv_list_add_btn(setting_obj, LV_SYMBOL_SETTINGS, "Touch & Encoder test");
    // setting_item6 = lv_list_add_btn(setting_obj, LV_SYMBOL_SETTINGS, "WIFI STA test");

    // updata style
    for(int i = 0; i < lv_obj_get_child_cnt(setting_obj); i++){
        lv_obj_t *item = lv_obj_get_child(setting_obj, i);
        lv_obj_set_height(item, 45);
        lv_obj_set_style_bg_color(item, lv_color_hex(COLOR_BG), LV_PART_MAIN);
        lv_obj_set_style_text_font(item, &lv_font_montserrat_18, LV_PART_MAIN);
        lv_obj_set_style_text_color(item, lv_color_hex(COLOR_TEXT), LV_PART_MAIN);
        lv_obj_set_style_text_opa(item, LV_OPA_90, LV_PART_MAIN);
        lv_obj_remove_style(item, NULL, LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_color(item, lv_color_hex(COLOR_ACCENT1), LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_width(item, 2, LV_STATE_FOCUS_KEY);
        lv_obj_add_event_cb(item, setting_item_event, LV_EVENT_CLICKED, (void *)i);
        lv_group_remove_obj(item);
    }

    // setting 1
    lv_obj_t * slider = lv_slider_create(setting_item1);
    lv_obj_set_size(slider, 80, 20);
    lv_obj_set_style_opa(slider, 0, LV_PART_KNOB);
    lv_obj_set_style_bg_color(slider, lv_color_hex(COLOR_ACCENT1), LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(slider, lv_color_hex(COLOR_ACCENT2), LV_PART_MAIN);
    lv_slider_set_range(slider, 1, 10);
    lv_slider_set_value(slider, brightness_level, LV_ANIM_ON);
    lv_obj_align_to(slider, setting_item1, LV_ALIGN_OUT_LEFT_MID, 10, 0);
    lv_obj_remove_style(slider, NULL, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(slider, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(slider, lv_color_hex(COLOR_ACCENT3), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(slider, 2, LV_STATE_FOCUS_KEY);
    lv_obj_t * light = lv_label_create(slider);
    lv_label_set_text_fmt(light, "%d", brightness_level);
    lv_obj_set_style_text_font(light, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_set_style_text_color(light, lv_color_hex(COLOR_TEXT), LV_PART_MAIN);
    lv_obj_center(light);
    lv_obj_add_event_cb(slider, brightness_adjust, LV_EVENT_VALUE_CHANGED, (void *)light);

    // setting 2
    lv_obj_t * sw = lv_switch_create(setting_item2);
    lv_obj_set_height(sw, 20);
    lv_obj_remove_style(sw, NULL, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(sw, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(sw, lv_color_hex(COLOR_ACCENT3), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(sw, 2, LV_STATE_FOCUS_KEY);
    if(touch_line_state){
        lv_obj_add_state(sw, LV_STATE_CHECKED);
    } 
    lv_obj_add_event_cb(sw, touch_line_event, LV_EVENT_ALL, (void *)2);

    // setting 3
    lv_obj_t *roller = lv_btn_create(setting_item3);
    lv_obj_set_size(roller, 70, 20);
    lv_obj_set_style_border_width(roller, 0, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(roller, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(roller, lv_color_hex(COLOR_ACCENT1), LV_PART_MAIN);
    lv_obj_remove_style(roller, NULL, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(roller, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(roller, lv_color_hex(COLOR_ACCENT3), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(roller, 2, LV_STATE_FOCUS_KEY);
    lv_obj_t * mode = lv_label_create(roller);
    printf("input mode = %d\n", input_mode);
    switch (input_mode){
        case INPUT_TOUCH_ENCODER: 
            lv_label_set_text(mode, "T & E");
            lv_indev_encode_en(true);
            lv_indev_touchpad_en(true);
            break;
        case INPUT_ONLY_TOUCH:    
            lv_label_set_text(mode, "Touch");
            lv_indev_encode_en(false);
            lv_indev_touchpad_en(true);
        break;
        case INPUT_ONLY_ENCODER:  
            lv_label_set_text(mode, "Encoder");
            lv_indev_encode_en(true);
            lv_indev_touchpad_en(false);
        break;
        default:break;
    }
    lv_obj_set_style_text_font(mode, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_set_style_text_color(mode, lv_color_hex(COLOR_TEXT), LV_PART_MAIN);
    lv_obj_center(mode);
    lv_obj_add_event_cb(roller, input_mode_event, LV_EVENT_CLICKED, (void *)mode);

    // setting 4
    sw = lv_switch_create(setting_item4);
    lv_obj_set_width(sw, 40);
    lv_obj_set_height(sw, 20);
    lv_obj_remove_style(sw, NULL, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(sw, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(sw, lv_color_hex(COLOR_ACCENT3), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(sw, 2, LV_STATE_FOCUS_KEY);
    if(menu_label_align_to_tgt){
        lv_obj_add_state(sw, LV_STATE_CHECKED);
    } 
    lv_obj_add_event_cb(sw, touch_line_event, LV_EVENT_ALL, (void *)4);

}
void entry3(void) {}
void exit3(void) {}
void destroy3(void) {back_btn_hidden(true);}

scr_lifecycle_t scr_setting = {
    .create = create3,
    .entry = entry3,
    .exit = exit3,
    .destroy = destroy3,
};