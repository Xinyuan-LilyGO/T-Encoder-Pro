
#include "screen.h"
/*********************************************************************************
 *                              SCREEN1
 *********************************************************************************/
#define menu_btn_img1 img_clock
#define menu_btn_img2 img_meter
#define menu_btn_img3 img_setting
#define menu_btn_img4 img_home
#define menu_btn_img5 img_colorwheel
#define menu_btn_img6 img_test
#define menu_btn_img7 img_email

lv_obj_t *menu_btn1; // img_calc
lv_obj_t *menu_btn2; // img_power
lv_obj_t *menu_btn3; // img_setting
lv_obj_t *menu_btn4; // img_compass
lv_obj_t *menu_btn5; // img_tool
lv_obj_t *menu_btn6; // img_email
lv_obj_t *menu_btn7; // img_colorwheel
lv_obj_t *menu_label;

bool menu_label_align_to_tgt = false;

void menu_btn_event(lv_event_t *e)
{
    lv_obj_t *tgt = e->target;
    int argv = (int)e->user_data;
    char *menu_name[] = { "clock", "meter", "setting", "home",
    "colorwheel", "test", "email"};

    if(e->code == LV_EVENT_CLICKED){
        switch (argv){
            case 1: scr_mgr_switch(UI_SCR_ID_1, true); break; // 1 - 
            case 2: scr_mgr_switch(UI_SCR_ID_2, true); break; // 2 - 
            case 3: scr_mgr_switch(UI_SCR_ID_3, true); break; // 3 - 
            case 4: scr_mgr_switch(UI_SCR_ID_4, true); break; // 4 - 
            case 5: scr_mgr_switch(UI_SCR_ID_5, true); break; // 5 - 
            case 6: scr_mgr_switch(UI_SCR_ID_6, true); break; // 6 - 
            case 7: scr_mgr_switch(UI_SCR_ID_7, true); break; // 7 - 
            default: break;
        }
    }

    if(e->code == LV_EVENT_FOCUSED){
        lv_label_set_text_fmt(menu_label, "%s", menu_name[argv-1]);
        if(menu_label_align_to_tgt){
            lv_obj_set_style_text_font(menu_label, &lv_font_montserrat_14, LV_PART_MAIN);
            lv_obj_align_to(menu_label, tgt, LV_ALIGN_OUT_BOTTOM_MID, 0, 8);
        }
    }

#if 0
    if(tgt == menu_btn1){
        printf("img_calc\n");
    }else if(tgt == menu_btn2){
        printf("img_power\n");
    }else if(tgt == menu_btn3){
        printf("img_setting\n");
    }else if(tgt == menu_btn4){
        printf("img_compass\n");
    }else if(tgt == menu_btn5){
        printf("img_tool\n");
    }else if(tgt == menu_btn6){
        printf("img_email\n");
    }else if(tgt == menu_btn7){
        printf("img_colorwheel\n");
    }

    printf("event:%d, data=%d\n", e->code, argv);
#endif
}

void main_scr_btn_create(lv_obj_t **obj, lv_obj_t *parent, const void *img_dsc, int argv)
{
    lv_img_dsc_t *img = (lv_img_dsc_t *)img_dsc;
    *obj = lv_btn_create(parent);
    lv_obj_set_size(*obj, img->header.w, img->header.h);
    lv_obj_set_style_radius(*obj, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(*obj, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    lv_obj_set_style_bg_img_src(*obj, img_dsc, 0);
    lv_obj_set_style_bg_img_opa(*obj, LV_OPA_50, LV_STATE_PRESSED | LV_PART_MAIN);
    lv_obj_set_style_opa(*obj, LV_OPA_80, LV_STATE_PRESSED);
    lv_obj_set_style_clip_corner(*obj, true, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(*obj, 0, LV_PART_MAIN);
    lv_obj_set_style_outline_width(*obj, 5, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(*obj, lv_color_hex(COLOR_ACCENT3), LV_STATE_FOCUS_KEY);
    lv_obj_add_event_cb(*obj, menu_btn_event, LV_EVENT_CLICKED, (void *)argv);
    lv_obj_add_event_cb(*obj, menu_btn_event, LV_EVENT_FOCUSED, (void *)argv);
}

void create0(lv_obj_t *parent)
{
    main_scr_btn_create(&menu_btn4, parent, &menu_btn_img4, 4);
    main_scr_btn_create(&menu_btn1, parent, &menu_btn_img1, 1);
    main_scr_btn_create(&menu_btn2, parent, &menu_btn_img2, 2);
    main_scr_btn_create(&menu_btn5, parent, &menu_btn_img5, 5);
    main_scr_btn_create(&menu_btn7, parent, &menu_btn_img7, 7);
    main_scr_btn_create(&menu_btn6, parent, &menu_btn_img6, 6);
    main_scr_btn_create(&menu_btn3, parent, &menu_btn_img3, 3);

    lv_obj_t * line = lv_line_create(parent);
    lv_obj_set_style_line_color(line, lv_palette_lighten(LV_PALETTE_GREY, 1), LV_PART_MAIN);
    lv_obj_set_style_line_width(line, 6, LV_PART_MAIN);
    lv_obj_set_style_line_rounded(line, 10, LV_PART_MAIN);
    static lv_point_t p[] = {{0, 0}, {80, 0}};
    lv_line_set_points(line, p, 2);
    lv_obj_set_pos(line, 160, 365);
    
    menu_label = lv_label_create(parent);
    lv_obj_set_width(menu_label, 100);
    lv_label_set_text(menu_label, "");
    lv_obj_set_style_text_align(menu_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_style_text_color(menu_label, lv_color_hex(COLOR_ACCENT3), LV_PART_MAIN);
    lv_obj_set_style_text_font(menu_label, &lv_font_montserrat_18, LV_PART_MAIN);
    lv_obj_align_to(menu_label, line, LV_ALIGN_OUT_TOP_MID, 0, -5);
}
void entry0(void) {
    // layout
    lv_coord_t img_w = img_clock.header.w;
    lv_coord_t offs = (lcd_width - (img_w * 3)) / 4;
    lv_coord_t c = lcd_width/2 - img_w/2; // screen center
    lv_coord_t x = (img_w + offs) * 0.5;
    lv_coord_t y = (img_w + offs) * 0.87;

    lv_obj_center(menu_btn4);
    lv_obj_align_to(menu_btn3, menu_btn4, LV_ALIGN_OUT_LEFT_MID, -offs, 0);
    lv_obj_align_to(menu_btn5, menu_btn4, LV_ALIGN_OUT_RIGHT_MID, offs, 0);
    lv_obj_set_pos(menu_btn1,  c - x, c - y);
    lv_obj_set_pos(menu_btn2,  c + x, c - y);
    lv_obj_set_pos(menu_btn6,  c - x, c + y);
    lv_obj_set_pos(menu_btn7,  c + x, c + y);
}
void exit0(void) {}
void destroy0(void) {}

scr_lifecycle_t scr_menu = {
    .create = create0,
    .entry = entry0,
    .exit = exit0,
    .destroy = destroy0,
};