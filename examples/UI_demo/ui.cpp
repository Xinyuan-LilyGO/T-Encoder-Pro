
#include "ui.h"
#include "Arduino.h"
#include "screen/screen.h"

lv_coord_t lcd_width = -1;
lv_coord_t lcd_height = -1;
lv_group_t *encode_group;
lv_obj_t * back_btn;
lv_obj_t * back_info;

void back_btn_event(lv_event_t *e)
{
    if(e->code == LV_EVENT_CLICKED) {
        scr_mgr_switch(UI_SCR_ID_MENU, true);
    }

    if(e->code == LV_EVENT_FOCUSED){
        lv_obj_set_style_opa(back_btn, LV_OPA_100, LV_PART_MAIN);
        // lv_label_set_text(back_info, "back");
    }else if(e->code == LV_EVENT_DEFOCUSED){
        // lv_obj_set_style_opa(back_btn, LV_OPA_80, LV_PART_MAIN);
        lv_label_set_text(back_info, "");
    }
}

void back_btn_hidden(bool en)
{
    if(en == true){
        lv_obj_add_flag(back_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(back_info, LV_OBJ_FLAG_HIDDEN);
    }
    else{
        lv_obj_clear_flag(back_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(back_info, LV_OBJ_FLAG_HIDDEN);
    }
}

/*********************************************************************************
 *                              UI ENTRY
 *********************************************************************************/
void ui_entry(void)
{
    lv_disp_t *disp = lv_disp_get_default();
    lcd_width = lv_disp_get_hor_res(disp);
    lcd_height = lv_disp_get_ver_res(disp);
    encode_group = lv_group_get_default();

    back_btn = lv_btn_create(lv_layer_top());
    lv_obj_set_size(back_btn, 86, 6);
    lv_obj_set_style_border_width(back_btn, 0, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(back_btn, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(back_btn, 0, LV_PART_MAIN);
    lv_obj_set_style_outline_width(back_btn, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(back_btn, lv_color_hex(COLOR_ACCENT1), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_bg_color(back_btn, lv_palette_lighten(LV_PALETTE_GREY, 1), LV_PART_MAIN);
    lv_obj_set_ext_click_area(back_btn, 20);
    lv_obj_add_event_cb(back_btn, back_btn_event, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(back_btn, back_btn_event, LV_EVENT_FOCUSED, NULL);
    lv_obj_add_event_cb(back_btn, back_btn_event, LV_EVENT_DEFOCUSED, NULL);
    lv_obj_align(back_btn, LV_ALIGN_BOTTOM_MID, 5, -22);
    lv_obj_add_flag(back_btn, LV_OBJ_FLAG_HIDDEN);

    back_info = lv_label_create(lv_layer_top());
    lv_obj_set_width(back_info, 100);
    lv_label_set_text(back_info, "");
    lv_obj_set_style_text_align(back_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_info, lv_color_hex(COLOR_ACCENT1), LV_PART_MAIN);
    lv_obj_align_to(back_info, back_btn, LV_ALIGN_OUT_TOP_MID, 0, -5);

    // screen
    scr_mgr_init();
    scr_mgr_register(UI_SCR_ID_MENU, &scr_menu);    // menu
    scr_mgr_register(UI_SCR_ID_1, &scr_clock);      // 1 - clock
    scr_mgr_register(UI_SCR_ID_2, &scr_meter);      // 2 - meter
    scr_mgr_register(UI_SCR_ID_3, &scr_setting);    // 3 - setting
    scr_mgr_register(UI_SCR_ID_4, &scr_home);       // 4 - home
    scr_mgr_register(UI_SCR_ID_5, &scr_colorwheel); // 5 - colorwheel
    scr_mgr_register(UI_SCR_ID_6, &scr_test);       // 6 - test
    scr_mgr_register(UI_SCR_ID_7, &scr_ws2812);     // 7 - email

    scr_mgr_set_anim(LV_SCR_LOAD_ANIM_NONE, LV_SCR_LOAD_ANIM_NONE, LV_SCR_LOAD_ANIM_NONE);
    scr_mgr_switch(UI_SCR_ID_MENU, true); // set root screen
}