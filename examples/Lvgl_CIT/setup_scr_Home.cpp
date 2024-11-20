/*
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-12-08 10:45:26
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-01-31 13:45:19
 * @License: GPL 3.0
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"

void setup_scr_Home(lv_ui *ui)
{
    CIT_UI.Window_Current_State = CIT_UI.Window_Current_State::Window_Home;

    // Write codes Home
    ui->Home = lv_obj_create(NULL);
    lv_obj_set_size(ui->Home, CIT_UI.LCD_Width, CIT_UI.LCD_Height);
    lv_obj_set_scrollbar_mode(ui->Home, LV_SCROLLBAR_MODE_OFF);

    // Write style for Home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Home_cont_1
    ui->Home_cont_1 = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_1, 0, 0);
    lv_obj_set_size(ui->Home_cont_1, CIT_UI.LCD_Width, CIT_UI.LCD_Height / 6.4);
    lv_obj_set_scrollbar_mode(ui->Home_cont_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Home_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_1, lv_color_hex(0xff7f58), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Home_label_1
    ui->Home_label_1 = lv_label_create(ui->Home_cont_1);
    lv_label_set_text(ui->Home_label_1, "CIT");
    lv_label_set_long_mode(ui->Home_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_1, 140, 25);
    lv_obj_set_size(ui->Home_label_1, 100, 50);
    lv_obj_set_scrollbar_mode(ui->Home_label_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Home_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_1, &lv_font_cunia_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Home_list_1
    ui->Home_list_1 = lv_list_create(ui->Home);
    switch (CIT_UI.Window_OLED_Brightness_Test_Result)
    {
    case CIT_UI.Window_Test_Result::Test_NULL:
        ui->Home_list_1_item0 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_WARNING, "1.OLED brightness test");
        break;
    case CIT_UI.Window_Test_Result::Test_Pass:
        ui->Home_list_1_item0 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_OK, "1.OLED brightness test");
        break;
    case CIT_UI.Window_Test_Result::Test_Fail:
        ui->Home_list_1_item0 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_CLOSE, "1.OLED brightness test");
        break;

    default:
        break;
    }
    switch (CIT_UI.Window_OLED_Edge_Detection_Test_Result)
    {
    case CIT_UI.Window_Test_Result::Test_NULL:
        ui->Home_list_1_item1 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_WARNING, "2.OLED edge detection test");
        break;
    case CIT_UI.Window_Test_Result::Test_Pass:
        ui->Home_list_1_item1 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_OK, "2.OLED edge detection test");
        break;
    case CIT_UI.Window_Test_Result::Test_Fail:
        ui->Home_list_1_item1 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_CLOSE, "2.OLED edge detection test");
        break;

    default:
        break;
    }
    switch (CIT_UI.Window_OLED_Contrast_Test_Result)
    {
    case CIT_UI.Window_Test_Result::Test_NULL:
        ui->Home_list_1_item2 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_WARNING, "3.OLED contrast test");
        break;
    case CIT_UI.Window_Test_Result::Test_Pass:
        ui->Home_list_1_item2 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_OK, "3.OLED contrast test");
        break;
    case CIT_UI.Window_Test_Result::Test_Fail:
        ui->Home_list_1_item2 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_CLOSE, "3.OLED contrast test");
        break;

    default:
        break;
    }
    switch (CIT_UI.Window_OLED_Display_Color_Test_Result)
    {
    case CIT_UI.Window_Test_Result::Test_NULL:
        ui->Home_list_1_item3 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_WARNING, "4.OLED display color test");
        break;
    case CIT_UI.Window_Test_Result::Test_Pass:
        ui->Home_list_1_item3 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_OK, "4.OLED display color test");
        break;
    case CIT_UI.Window_Test_Result::Test_Fail:
        ui->Home_list_1_item3 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_CLOSE, "4.OLED display colortest");
        break;

    default:
        break;
    }
    switch (CIT_UI.Window_Rotary_Encoder_WS2812B_Test_Result)
    {
    case CIT_UI.Window_Test_Result::Test_NULL:
        ui->Home_list_1_item4 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_RIGHT, "5.Rotary encoder Buzzer test");
        break;
    case CIT_UI.Window_Test_Result::Test_Pass:
        ui->Home_list_1_item4 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_RIGHT, "5.Rotary encoder Buzzer test");
        break;
    case CIT_UI.Window_Test_Result::Test_Fail:
        ui->Home_list_1_item4 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_RIGHT, "5.Rotary encoder Buzzer test");
        break;

    default:
        break;
    }
    switch (CIT_UI.Window_WIFI_STA_Test_Result)
    {
    case CIT_UI.Window_Test_Result::Test_NULL:
        ui->Home_list_1_item5 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_RIGHT, "6.WIFI STA test");
        break;
    case CIT_UI.Window_Test_Result::Test_Pass:
        ui->Home_list_1_item5 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_RIGHT, "6.WIFI STA test");
        break;
    case CIT_UI.Window_Test_Result::Test_Fail:
        ui->Home_list_1_item5 = lv_list_add_btn(ui->Home_list_1, LV_SYMBOL_RIGHT, "6.WIFI STA test");
        break;

    default:
        break;
    }

    lv_obj_set_pos(ui->Home_list_1, 0, CIT_UI.LCD_Height / 6.4);
    lv_obj_set_size(ui->Home_list_1, CIT_UI.LCD_Width, CIT_UI.LCD_Height - (CIT_UI.LCD_Height / 6.4));
    lv_obj_set_scrollbar_mode(ui->Home_list_1, LV_SCROLLBAR_MODE_OFF);

    // Write style state: LV_STATE_DEFAULT for &style_Home_list_1_main_main_default
    static lv_style_t style_Home_list_1_main_main_default;
    ui_init_style(&style_Home_list_1_main_main_default);

    lv_style_set_pad_top(&style_Home_list_1_main_main_default, 5);
    lv_style_set_pad_left(&style_Home_list_1_main_main_default, 5);
    lv_style_set_pad_right(&style_Home_list_1_main_main_default, 5);
    lv_style_set_pad_bottom(&style_Home_list_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_Home_list_1_main_main_default, 255);
    lv_style_set_bg_color(&style_Home_list_1_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_width(&style_Home_list_1_main_main_default, 1);
    lv_style_set_border_opa(&style_Home_list_1_main_main_default, 255);
    lv_style_set_border_color(&style_Home_list_1_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_radius(&style_Home_list_1_main_main_default, 3);
    lv_style_set_shadow_width(&style_Home_list_1_main_main_default, 0);
    lv_obj_add_style(ui->Home_list_1, &style_Home_list_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for &style_Home_list_1_main_scrollbar_default
    static lv_style_t style_Home_list_1_main_scrollbar_default;
    ui_init_style(&style_Home_list_1_main_scrollbar_default);

    lv_style_set_radius(&style_Home_list_1_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_Home_list_1_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_Home_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_obj_add_style(ui->Home_list_1, &style_Home_list_1_main_scrollbar_default, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for &style_Home_list_1_extra_btns_main_default
    static lv_style_t style_Home_list_1_extra_btns_main_default;
    ui_init_style(&style_Home_list_1_extra_btns_main_default);

    lv_style_set_pad_top(&style_Home_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_Home_list_1_extra_btns_main_default, 50);
    lv_style_set_pad_right(&style_Home_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_Home_list_1_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_Home_list_1_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_Home_list_1_extra_btns_main_default, lv_color_hex(0x0D3055));
    // lv_style_set_text_font(&style_Home_list_1_extra_btns_main_default, &lv_font_arial_14);
    lv_style_set_radius(&style_Home_list_1_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_Home_list_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_Home_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_obj_add_style(ui->Home_list_1_item0, &style_Home_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Home_list_1_item1, &style_Home_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Home_list_1_item2, &style_Home_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Home_list_1_item3, &style_Home_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Home_list_1_item4, &style_Home_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Home_list_1_item5, &style_Home_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for &style_Home_list_1_extra_texts_main_default
    static lv_style_t style_Home_list_1_extra_texts_main_default;
    ui_init_style(&style_Home_list_1_extra_texts_main_default);

    lv_style_set_pad_top(&style_Home_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_Home_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_Home_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_Home_list_1_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_Home_list_1_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_Home_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_Home_list_1_extra_texts_main_default, &lv_font_arial_14);
    lv_style_set_radius(&style_Home_list_1_extra_texts_main_default, 3);
    lv_style_set_bg_opa(&style_Home_list_1_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_Home_list_1_extra_texts_main_default, lv_color_hex(0xffffff));

    // Update current screen layout.
    lv_obj_update_layout(ui->Home);

    // Init events for screen.
    events_init_Home(ui);
}
