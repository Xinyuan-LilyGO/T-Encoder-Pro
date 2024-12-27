#include "screen.h"

/*********************************************************************************
 *                              EXTERN
 *********************************************************************************/
extern Arduino_GFX *gfx;
extern int encoder_direction;

/*********************************************************************************
 *                              SCREEN5
 *********************************************************************************/
lv_obj_t *list_obj;
lv_obj_t *list_item1;
lv_obj_t *list_item2;
lv_obj_t *list_item3;
lv_obj_t *list_item4;
lv_obj_t *list_item5;
lv_obj_t *list_item6;
lv_obj_t *item_obj;

void back_screen5(lv_event_t *e)
{
    if(e->code == LV_EVENT_CLICKED){
        scr_mgr_switch(UI_SCR_ID_6, true);
        lv_obj_del(item_obj);
    }
}

lv_obj_t *item_head_create(lv_obj_t *parent, const char *head_text)
{
    lv_obj_t *head1_info = lv_label_create(parent);
    lv_label_set_text(head1_info, head_text);
    lv_obj_set_size(head1_info, 280, 60);
    lv_obj_set_style_bg_opa(head1_info, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_bg_color(head1_info, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    lv_obj_set_style_text_color(head1_info, lv_color_hex(COLOR_ACCENT1), LV_PART_MAIN);
    lv_obj_set_style_pad_top(head1_info, 25, LV_PART_MAIN);
    lv_obj_set_style_text_line_space(head1_info, 10, LV_PART_MAIN);
    lv_obj_set_style_text_letter_space(head1_info, 5, LV_PART_MAIN);
    lv_obj_set_style_text_font(head1_info, &lv_font_montserrat_18, LV_PART_MAIN);
    lv_obj_set_style_text_align(head1_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_align(head1_info, LV_ALIGN_TOP_MID, 0, 15);
    return head1_info;
}

lv_obj_t *item_prompt_info_create(lv_obj_t *parent, const char *prompt_text)
{
    lv_obj_t *label = lv_label_create(parent);
    lv_label_set_text(label, prompt_text);
    lv_obj_set_size(label, 320, 200);
    lv_obj_set_style_radius(label, 10, LV_PART_MAIN);
    lv_obj_set_style_outline_width(label, 2, LV_PART_MAIN);
    lv_obj_set_style_pad_top(label, 25, LV_PART_MAIN);
    lv_obj_set_style_pad_left(label, 10, LV_PART_MAIN);
    lv_obj_set_style_pad_right(label, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(label, LV_OPA_70, LV_PART_MAIN);
    lv_obj_set_style_bg_color(label, lv_color_hex(COLOR_ACCENT1), LV_PART_MAIN);
    lv_obj_set_style_text_line_space(label, 8, LV_PART_MAIN);
    // lv_obj_set_style_text_letter_space(label, 2, LV_PART_MAIN);
    lv_obj_set_style_text_opa(label, LV_OPA_100, LV_PART_MAIN);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_18, LV_PART_MAIN);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, -14);
    return label;
}

lv_obj_t *item_btn_create(lv_obj_t *parent, const char *text, lv_event_cb_t event_cb)
{
    lv_obj_t *btn = lv_btn_create(item_obj);
    lv_obj_set_size(btn, 80, 50);
    lv_obj_set_style_bg_color(btn, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    lv_obj_set_style_border_width(btn, 0, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(btn, 0, LV_PART_MAIN);
    lv_obj_set_style_outline_width(btn, 2, LV_PART_MAIN);
    lv_obj_set_style_outline_color(btn, lv_palette_lighten(LV_PALETTE_GREY, 1), LV_PART_MAIN);
    lv_obj_remove_style(btn, NULL, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(btn, 2, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(btn, lv_color_hex(COLOR_ACCENT1), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_text_color(btn, lv_color_hex(COLOR_ACCENT1), LV_PART_MAIN);
    lv_obj_add_event_cb(btn, event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, text);    
    lv_obj_center(label);
    return btn;
}

void test1_adjust_brightness(lv_event_t *e)
{
    if(e->code == LV_EVENT_CLICKED){
        for (int i = 255; i > 0; i--) {
            gfx->Display_Brightness(i);
            delay(4);
        }
        delay(500);
        for (int i = 0; i <= 255; i++) {
            gfx->Display_Brightness(i);
            delay(4);
        }
        delay(500);
    }
}

void item_test_scr_create1(void)
{
    lv_obj_t *head = item_head_create(item_obj, "Detection");

    lv_obj_t *label = item_prompt_info_create(item_obj, "  Click the Start button to execute the screen brightness test program;"
                                    "  The screen goes from light to dark, from dark to light;  Process 3 seconds.");

    lv_obj_t *btn = item_btn_create(item_obj, "Back", back_screen5);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, -55, -50);

    lv_obj_t *btn1 = item_btn_create(item_obj, "Start", test1_adjust_brightness);
    lv_obj_align(btn1, LV_ALIGN_BOTTOM_MID, 55, -50);
}

void test2_edge_detection(lv_event_t *e)
{
    if(e->code == LV_EVENT_CLICKED){
        gfx->fillScreen(WHITE);
        gfx->setCursor(100, lcd_width / 2);
        gfx->setTextColor(ORANGE);
        gfx->setTextSize(3);
        gfx->printf("r=(390/2)-2");
        gfx->drawCircle(lcd_width / 2, lcd_height / 2, lcd_width / 2 - 2, RED);
        delay(3000);
        lv_scr_load(item_obj);
    }
}

void item_test_scr_create2(void)
{   
    lv_obj_t *head = item_head_create(item_obj, "Edge Detection");

    lv_obj_t *label = item_prompt_info_create(item_obj, "Underline the edges of the screen; This process takes 3 seconds");

    lv_obj_t *btn = item_btn_create(item_obj, "Back", back_screen5);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, -55, -50);

    lv_obj_t *btn1 = item_btn_create(item_obj, "Start", test2_edge_detection);
    lv_obj_align(btn1, LV_ALIGN_BOTTOM_MID, 55, -50); 
}

void test3_contrast(lv_event_t *e)
{
    if(e->code == LV_EVENT_CLICKED){
        gfx->fillScreen(RED);
        gfx->setCursor(10, lcd_height / 2);
        gfx->setTextColor(WHITE);
        gfx->setTextSize(2);

        gfx->printf("OLED Contrast: Contrast Off");
        gfx->SetContrast(SH8601_ContrastOff);
        delay(2000);

        gfx->setCursor(10, lcd_height / 2);
        gfx->fillScreen(RED);
        gfx->printf("OLED Contrast: Low Contrast");
        gfx->SetContrast(SH8601_LowContrast);
        delay(2000);

        gfx->setCursor(10, lcd_height / 2);
        gfx->fillScreen(RED);
        gfx->printf("OLED Contrast: Medium Contrast");
        gfx->SetContrast(SH8601_MediumContrast);
        delay(2000);

        gfx->setCursor(10, lcd_height / 2);
        gfx->fillScreen(RED);
        gfx->printf("OLED Contrast: High Contrast");
        gfx->SetContrast(SH8601_HighContrast);
        delay(2000);

        gfx->SetContrast(SH8601_ContrastOff);
        lv_scr_load(item_obj);
    }
}

void item_test_scr_create3(void)
{
    lv_obj_t *head = item_head_create(item_obj, "Contrast");

    lv_obj_t *label = item_prompt_info_create(item_obj, "Test the contrast of the screen; This process takes 8 seconds");

    lv_obj_t *btn = item_btn_create(item_obj, "Back", back_screen5);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, -55, -50);

    lv_obj_t *btn1 = item_btn_create(item_obj, "Start", test3_contrast);
    lv_obj_align(btn1, LV_ALIGN_BOTTOM_MID, 55, -50);   
}

void test4_display_color(lv_event_t *e)
{
    if(e->code == LV_EVENT_CLICKED){
        gfx->fillScreen(BLACK); delay(1000);
        gfx->fillScreen(NAVY); delay(1000);
        gfx->fillScreen(DARKGREEN); delay(1000);
        gfx->fillScreen(DARKCYAN); delay(1000);
        gfx->fillScreen(MAROON); delay(1000);
        gfx->fillScreen(PURPLE); delay(1000);
        gfx->fillScreen(OLIVE); delay(1000);
        gfx->fillScreen(LIGHTGREY); delay(1000);
        gfx->fillScreen(DARKGREY); delay(1000);
        gfx->fillScreen(BLUE); delay(1000);
        gfx->fillScreen(GREEN); delay(1000);
        gfx->fillScreen(CYAN); delay(1000);
        gfx->fillScreen(RED); delay(1000);
        gfx->fillScreen(MAGENTA); delay(1000);
        gfx->fillScreen(YELLOW); delay(1000);
        gfx->fillScreen(WHITE); delay(1000);
        gfx->fillScreen(ORANGE); delay(1000);
        gfx->fillScreen(GREENYELLOW); delay(1000);
        gfx->fillScreen(PINK); delay(1000);
        lv_scr_load(item_obj);
    }
}

void item_test_scr_create4(void)
{   
    lv_obj_t *head = item_head_create(item_obj, "Color");

    lv_obj_t *label = item_prompt_info_create(item_obj, "Test screen display color; This process takes 19 seconds");

    lv_obj_t *btn = item_btn_create(item_obj, "Back", back_screen5);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, -55, -50);

    lv_obj_t *btn1 = item_btn_create(item_obj, "Start", test4_display_color);
    lv_obj_align(btn1, LV_ALIGN_BOTTOM_MID, 55, -50);    
}

void test5_touch_encoder(lv_event_t * e)
{
    lv_obj_t * label = lv_event_get_target(e);
    lv_msg_t * m = lv_event_get_msg(e);

    int data = (int)lv_msg_get_user_data(m);
    const int32_t * v = (int32_t *)lv_msg_get_payload(m);

    switch (data)
    {
        case MSG_INDEV_ENCODER: lv_label_set_text_fmt(label, "encoder: %d", *v); break;
        case MSG_INDEV_TOUCH_X: lv_label_set_text_fmt(label, "touch_x: %d", *v); break;
        case MSG_INDEV_TOUCH_Y: lv_label_set_text_fmt(label, "touch_y: %d", *v); break;
        default: break;
    }
}

void item_test_scr_create5(void)
{
    lv_obj_t *head = item_head_create(item_obj, "Touch & Encoder");

    lv_obj_t *touch_x = lv_label_create(item_obj);
    lv_obj_add_event_cb(touch_x, test5_touch_encoder, LV_EVENT_MSG_RECEIVED, NULL);
    lv_label_set_text(touch_x, "touch_x: 0");
    lv_obj_set_style_text_font(touch_x, &lv_font_montserrat_18, LV_PART_MAIN);
    lv_obj_align(touch_x, LV_ALIGN_CENTER, 0, -40);
    lv_obj_set_style_text_align(touch_x, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN);
    lv_msg_subsribe_obj(MSG_INDEV_TOUCH_X, touch_x, (void *)MSG_INDEV_TOUCH_X);

    lv_obj_t *touch_y = lv_label_create(item_obj);
    lv_obj_add_event_cb(touch_y, test5_touch_encoder, LV_EVENT_MSG_RECEIVED, NULL);
    lv_label_set_text(touch_y, "touch_y: 0");
    lv_obj_set_style_text_font(touch_y, &lv_font_montserrat_18, LV_PART_MAIN);
    lv_obj_align(touch_y, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_align(touch_y, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN);
    lv_msg_subsribe_obj(MSG_INDEV_TOUCH_Y, touch_y, (void *)MSG_INDEV_TOUCH_Y);

    lv_obj_t *encoder = lv_label_create(item_obj);
    lv_obj_add_event_cb(encoder, test5_touch_encoder, LV_EVENT_MSG_RECEIVED, NULL);
    lv_label_set_text(encoder, "encoder: 0");
    lv_obj_set_style_text_font(encoder, &lv_font_montserrat_18, LV_PART_MAIN);
    lv_obj_align(encoder, LV_ALIGN_CENTER, 0, 40);
    lv_obj_set_style_text_align(encoder, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN);
    lv_msg_subsribe_obj(MSG_INDEV_ENCODER, encoder, (void *)MSG_INDEV_ENCODER);

    lv_obj_t *btn = item_btn_create(item_obj, "Back", back_screen5);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, -50);
}

void item_test_scr_create6(void)
{
    lv_obj_t *head = item_head_create(item_obj, "WIFI");

    lv_obj_t *label = item_prompt_info_create(item_obj, "NULL");

    lv_obj_t *btn = item_btn_create(item_obj, "Back", back_screen5);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, -55, -50);

    lv_obj_t *btn1 = item_btn_create(item_obj, "Start", back_screen5);
    lv_obj_align(btn1, LV_ALIGN_BOTTOM_MID, 55, -50);   
}

void list_item_event(lv_event_t *e)
{
    int user_data = (int)e->user_data;

    if(e->code == LV_EVENT_CLICKED){
        // test item obj
        item_obj = lv_obj_create(NULL);
        lv_obj_set_size(item_obj, lv_pct(100), lv_pct(100));
        lv_obj_set_style_bg_color(item_obj, lv_color_hex(COLOR_BG), LV_PART_MAIN);
        lv_obj_set_scrollbar_mode(item_obj, LV_SCROLLBAR_MODE_OFF);

        switch (user_data) {
            case 0: item_test_scr_create1(); break;
            case 1: item_test_scr_create2(); break;
            case 2: item_test_scr_create3(); break;
            case 3: item_test_scr_create4(); break;
            case 4: item_test_scr_create5(); break;
            case 5: item_test_scr_create6(); break;
            default: break;
        }
        lv_scr_load(item_obj);
        back_btn_hidden(true);
        // defocused lise_item
        for(int i = 0; i < lv_obj_get_child_cnt(list_obj); i++){
            lv_group_remove_obj(lv_obj_get_child(list_obj, i));
        }
    }
}

void create5(lv_obj_t *parent)
{
    back_btn_hidden(false);

    lv_obj_t *label = lv_label_create(parent);
    lv_label_set_text(label, "Test");
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

    list_obj = lv_list_create(parent);
    lv_obj_set_size(list_obj, 300, 300);
    lv_obj_align(list_obj, LV_ALIGN_CENTER, 0, 15);
    lv_obj_set_style_bg_color(list_obj, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    lv_obj_set_style_pad_row(list_obj, 2, LV_PART_MAIN);
    lv_obj_set_style_border_width(list_obj, 0, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(list_obj, 0, LV_PART_MAIN);

    // add item
    list_item1 = lv_list_add_btn(list_obj, LV_SYMBOL_PLAY, "OLED brightness test");
    list_item2 = lv_list_add_btn(list_obj, LV_SYMBOL_PLAY, "Edge detection test");
    list_item3 = lv_list_add_btn(list_obj, LV_SYMBOL_PLAY, "OLED contrast test");
    list_item4 = lv_list_add_btn(list_obj, LV_SYMBOL_PLAY, "OLED display color test");
    list_item5 = lv_list_add_btn(list_obj, LV_SYMBOL_PLAY, "Touch & Encoder test");
    list_item6 = lv_list_add_btn(list_obj, LV_SYMBOL_PLAY, "WIFI STA test");

    // updata style 
    for(int i = 0; i < lv_obj_get_child_cnt(list_obj); i++){
        lv_obj_t *item = lv_obj_get_child(list_obj, i);
        lv_obj_set_height(item, 45);
        lv_obj_set_style_bg_color(item, lv_color_hex(COLOR_BG), LV_PART_MAIN);
        lv_obj_set_style_text_font(item, &lv_font_montserrat_18, LV_PART_MAIN);
        lv_obj_set_style_text_color(item, lv_color_hex(COLOR_TEXT), LV_PART_MAIN);
        lv_obj_set_style_text_opa(item, LV_OPA_90, LV_PART_MAIN);
        lv_obj_remove_style(item, NULL, LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_color(item, lv_color_hex(COLOR_ACCENT1), LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_width(item, 2, LV_STATE_FOCUS_KEY);
        lv_obj_add_event_cb(item, list_item_event, LV_EVENT_CLICKED, (void *)i);
    }
}
void entry5(void) {}
void exit5(void) {}
void destroy5(void) {
    back_btn_hidden(true);
}

scr_lifecycle_t scr_test = {
    .create = create5,
    .entry = entry5,
    .exit = exit5,
    .destroy = destroy5,
};