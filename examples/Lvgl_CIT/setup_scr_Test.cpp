/*
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-12-08 10:45:26
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2023-12-08 16:07:39
 * @License: GPL 3.0
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"

void setup_scr_Test(lv_ui *ui)
{
    // Write codes Test
    ui->Test = lv_obj_create(NULL);
    lv_obj_set_size(ui->Test, 128, 128);
    lv_obj_set_scrollbar_mode(ui->Test, LV_SCROLLBAR_MODE_OFF);

    // Write style for Test, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Test, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Test, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Test_btnm_1
    ui->Test_btnm_1 = lv_btnmatrix_create(ui->Test);
    static const char *Test_btnm_1_text_map[] = {
        "Pass",
        "Fail",
        "",
    };
    lv_btnmatrix_set_map(ui->Test_btnm_1, Test_btnm_1_text_map);
    lv_obj_set_pos(ui->Test_btnm_1, 0, CIT_UI.LCD_Height - (CIT_UI.LCD_Height / 5.12));
    lv_obj_set_size(ui->Test_btnm_1, CIT_UI.LCD_Width, CIT_UI.LCD_Height / 5.12);
    lv_obj_set_scrollbar_mode(ui->Test_btnm_1, LV_SCROLLBAR_MODE_OFF);

    // Write style for Test_btnm_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Test_btnm_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Test_btnm_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Test_btnm_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Test_btnm_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Test_btnm_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui->Test_btnm_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Test_btnm_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Test_btnm_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Test_btnm_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Test_btnm_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Test_btnm_1, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Test_btnm_1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Test_btnm_1, lv_color_hex(0xc9c9c9), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Test_btnm_1, lv_color_hex(0xffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Test_btnm_1, &lv_font_arial_14, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Test_btnm_1, 4, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Test_btnm_1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Test_btnm_1, lv_color_hex(0x2195f6), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Test_btnm_1, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);

    // Update current screen layout.
    lv_obj_update_layout(ui->Test);

    // Init events for screen.
    events_init_Test(ui);
}
