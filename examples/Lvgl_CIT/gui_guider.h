/*
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-12-08 10:45:26
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2023-12-09 15:55:48
 * @License: GPL 3.0
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

    typedef struct
    {
        lv_obj_t *Home;
        bool Home_del;
        lv_obj_t *Home_cont_1;
        lv_obj_t *Home_label_1;
        lv_obj_t *Home_list_1;
        lv_obj_t *Home_list_1_item0;
        lv_obj_t *Home_list_1_item1;
        lv_obj_t *Home_list_1_item2;
        lv_obj_t *Home_list_1_item3;
        lv_obj_t *Home_list_1_item4;
        lv_obj_t *Home_list_1_item5;
        lv_obj_t *Test;
        bool Test_del;
        lv_obj_t *Test_btnm_1;
        lv_obj_t *Test_btn_1;
        lv_obj_t *Test_btn_1_label;
        lv_obj_t *Test_tabview_1;
        lv_obj_t *Test_tabview_1_tab_1;
        lv_obj_t *Test_tabview_1_tab_1_label;
        lv_obj_t *Test_tabview_1_tab_2;
        lv_obj_t *Test_tabview_1_tab_2_label;
        lv_obj_t *Test_sw_1;
        lv_obj_t *Test_label_1;
        lv_obj_t *Test_label_2;
        lv_obj_t *Test_slider_1;
    } lv_ui;

    void ui_init_style(lv_style_t *style);
    void init_scr_del_flag(lv_ui *ui);
    void setup_ui(lv_ui *ui);
    extern lv_ui guider_ui;

    void setup_scr_Home(lv_ui *ui);
    void setup_scr_Test(lv_ui *ui);

    LV_FONT_DECLARE(lv_font_arial_10)
    LV_FONT_DECLARE(lv_font_arial_12)
    LV_FONT_DECLARE(lv_font_arial_14)
    LV_FONT_DECLARE(lv_font_cunia_30)

#ifdef __cplusplus
}
#endif
#endif
