/*
 * @Description: None
 * @Author: LILYGO_L
 * @Date: 2024-11-28 17:07:50
 * @LastEditTime: 2024-11-28 18:21:18
 * @License: GPL 3.0
 */
#include "ui.h"

void ui_init(lv_ui *ui)
{
    win_home_init(ui);
    lv_scr_load(ui->home);
}

void win_home_init(lv_ui *ui)
{
    // Write codes Home
    ui->home = lv_obj_create(NULL);
    lv_obj_set_size(ui->home, ui->win_width, ui->win_height);
    lv_obj_set_scrollbar_mode(ui->home, LV_SCROLLBAR_MODE_OFF);

    // Write style for Home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui->home_tileview = lv_tileview_create(ui->home);

    ui->home_tile_1 = lv_tileview_add_tile(ui->home_tileview, 0, 0, (lv_dir_t)(LV_DIR_LEFT | LV_DIR_RIGHT));

    lv_obj_t *btn = lv_button_create(ui->home_tile_1);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Scroll up or right");
    lv_obj_set_size(btn, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_center(btn);

    ui->home_tile_2 = lv_tileview_add_tile(ui->home_tileview, 1, 0, (lv_dir_t)(LV_DIR_LEFT | LV_DIR_RIGHT));
    lv_obj_t *list = lv_list_create(ui->home_tile_2);
    lv_obj_set_size(list, LV_PCT(100), LV_PCT(100));

    lv_list_add_button(list, NULL, "One");
    lv_list_add_button(list, NULL, "Two");
    lv_list_add_button(list, NULL, "Three");
    lv_list_add_button(list, NULL, "Four");
    lv_list_add_button(list, NULL, "Five");
    lv_list_add_button(list, NULL, "Six");
    lv_list_add_button(list, NULL, "Seven");
    lv_list_add_button(list, NULL, "Eight");
    lv_list_add_button(list, NULL, "Nine");
    lv_list_add_button(list, NULL, "Ten");

    // Update current screen layout.
    lv_obj_update_layout(ui->home);
}
