/*
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-12-08 10:45:26
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2023-12-08 12:57:07
 * @License: GPL 3.0
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

void ui_init_style(lv_style_t *style)
{
    if (style->prop_cnt > 1)
        lv_style_reset(style);
    else
        lv_style_init(style);
}

void init_scr_del_flag(lv_ui *ui)
{
    ui->Home_del = true;
    ui->Test_del = true;
}

void setup_ui(lv_ui *ui)
{
    init_scr_del_flag(ui);
    setup_scr_Home(ui);
    lv_scr_load(ui->Home);
}
