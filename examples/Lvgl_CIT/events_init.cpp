/*
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-12-08 10:45:26
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-01-10 15:06:45
 * @License: GPL 3.0
 */
#include "custom.h"
#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

static void Home_list_1_item0_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Test_del == true)
            {
                setup_scr_Test(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Test, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
            guider_ui.Test_del = true;
        }

        CIT_UI.Window_Current_State = CIT_UI.Window_Current_State::Window_OLED_Brightness_Test;
        CIT_UI.Window_Initialization_Flag = false;

        break;
    }
    default:
        break;
    }
}

static void Home_list_1_item1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Test_del == true)
            {
                setup_scr_Test(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Test, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
            guider_ui.Test_del = true;
        }

        CIT_UI.Window_Current_State = CIT_UI.Window_Current_State::Window_OLED_Edge_Detection_Test;
        CIT_UI.Window_Initialization_Flag = false;
        break;
    }
    default:
        break;
    }
}

static void Home_list_1_item2_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Test_del == true)
            {
                setup_scr_Test(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Test, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
            guider_ui.Test_del = true;
        }

        CIT_UI.Window_Current_State = CIT_UI.Window_Current_State::Window_OLED_Contrast_Test;
        CIT_UI.Window_Initialization_Flag = false;
        break;
    }
    default:
        break;
    }
}

static void Home_list_1_item3_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Test_del == true)
            {
                setup_scr_Test(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Test, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
            guider_ui.Test_del = true;
        }

        CIT_UI.Window_Current_State = CIT_UI.Window_Current_State::Window_OLED_Display_Color_Test;
        CIT_UI.Window_Initialization_Flag = false;
        break;
    }
    default:
        break;
    }
}

static void Home_list_1_item4_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Test_del == true)
            {
                setup_scr_Test(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Test, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
            guider_ui.Test_del = true;
        }

        CIT_UI.Window_Current_State = CIT_UI.Window_Current_State::Window_Rotary_Encoder_WS2812B_Test;
        CIT_UI.Window_Initialization_Flag = false;
        break;
    }
    default:
        break;
    }
}

static void Home_list_1_item5_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        // Write the load screen code.
        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
        {
            if (guider_ui.Test_del == true)
            {
                setup_scr_Test(&guider_ui);
            }
            lv_scr_load_anim(guider_ui.Test, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
            guider_ui.Test_del = true;
        }

        CIT_UI.Window_Current_State = CIT_UI.Window_Current_State::Window_WIFI_STA_Test;
        CIT_UI.Window_Initialization_Flag = false;
        break;
    }
    default:
        break;
    }
}

void events_init_Home(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Home_list_1_item0, Home_list_1_item0_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Home_list_1_item1, Home_list_1_item1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Home_list_1_item2, Home_list_1_item2_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Home_list_1_item3, Home_list_1_item3_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Home_list_1_item4, Home_list_1_item4_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Home_list_1_item5, Home_list_1_item5_event_handler, LV_EVENT_ALL, NULL);
}

static void Test_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // Write the load screen code.
            lv_obj_t *act_scr = lv_scr_act();
            lv_disp_t *d = lv_obj_get_disp(act_scr);

            if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
            {
                if (guider_ui.Home_del == true)
                {
                    setup_scr_Home(&guider_ui);
                }
                lv_scr_load_anim(guider_ui.Home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, true);
                guider_ui.Home_del = true;
            }
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // Write the load screen code.
            lv_obj_t *act_scr = lv_scr_act();
            lv_disp_t *d = lv_obj_get_disp(act_scr);

            if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
            {
                if (guider_ui.Home_del == true)
                {
                    setup_scr_Home(&guider_ui);
                }
                lv_scr_load_anim(guider_ui.Home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, true);
                guider_ui.Home_del = true;
            }
            break;
        }
        }
        break;
    }
    default:
        break;
    }
}

static void Test_btnm_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t *obj = lv_event_get_target(e);
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        switch (id)
        {
        case 0:
        {
            switch (CIT_UI.Window_Current_State)
            {
            case CIT_UI.Window_Current_State::Window_OLED_Brightness_Test:
                CIT_UI.Window_OLED_Brightness_Test_Result = CIT_UI.Window_Test_Result::Test_Pass;
                break;
            case CIT_UI.Window_Current_State::Window_OLED_Edge_Detection_Test:
                CIT_UI.Window_OLED_Edge_Detection_Test_Result = CIT_UI.Window_Test_Result::Test_Pass;
                break;
            case CIT_UI.Window_Current_State::Window_OLED_Contrast_Test:
                CIT_UI.Window_OLED_Contrast_Test_Result = CIT_UI.Window_Test_Result::Test_Pass;
                break;
            case CIT_UI.Window_Current_State::Window_OLED_Display_Color_Test:
                CIT_UI.Window_OLED_Display_Color_Test_Result = CIT_UI.Window_Test_Result::Test_Pass;
                break;
            case CIT_UI.Window_Current_State::Window_Rotary_Encoder_WS2812B_Test:
                CIT_UI.Window_Rotary_Encoder_WS2812B_Test_Result = CIT_UI.Window_Test_Result::Test_Pass;
                break;
            case CIT_UI.Window_Current_State::Window_WIFI_STA_Test:
                CIT_UI.Window_WIFI_STA_Test_Result = CIT_UI.Window_Test_Result::Test_Pass;
                break;

            default:
                break;
            }

            // Write the load screen code.
            lv_obj_t *act_scr = lv_scr_act();
            lv_disp_t *d = lv_obj_get_disp(act_scr);
            if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
            {
                if (guider_ui.Home_del == true)
                {
                    setup_scr_Home(&guider_ui);
                }
                lv_scr_load_anim(guider_ui.Home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, true);
                guider_ui.Home_del = true;
            }
            break;
        }
        case 1:
        {
            switch (CIT_UI.Window_Current_State)
            {
            case CIT_UI.Window_Current_State::Window_OLED_Brightness_Test:
                CIT_UI.Window_OLED_Brightness_Test_Result = CIT_UI.Window_Test_Result::Test_Fail;
                break;
            case CIT_UI.Window_Current_State::Window_OLED_Edge_Detection_Test:
                CIT_UI.Window_OLED_Edge_Detection_Test_Result = CIT_UI.Window_Test_Result::Test_Fail;
                break;
            case CIT_UI.Window_Current_State::Window_OLED_Contrast_Test:
                CIT_UI.Window_OLED_Contrast_Test_Result = CIT_UI.Window_Test_Result::Test_Fail;
                break;
            case CIT_UI.Window_Current_State::Window_OLED_Display_Color_Test:
                CIT_UI.Window_OLED_Display_Color_Test_Result = CIT_UI.Window_Test_Result::Test_Fail;
                break;
            case CIT_UI.Window_Current_State::Window_Rotary_Encoder_WS2812B_Test:
                CIT_UI.Window_Rotary_Encoder_WS2812B_Test_Result = CIT_UI.Window_Test_Result::Test_Fail;
                break;
            case CIT_UI.Window_Current_State::Window_WIFI_STA_Test:
                CIT_UI.Window_WIFI_STA_Test_Result = CIT_UI.Window_Test_Result::Test_Fail;
                break;

            default:
                break;
            }

            // Write the load screen code.
            lv_obj_t *act_scr = lv_scr_act();
            lv_disp_t *d = lv_obj_get_disp(act_scr);
            if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
            {
                if (guider_ui.Home_del == true)
                {
                    setup_scr_Home(&guider_ui);
                }
                lv_scr_load_anim(guider_ui.Home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, true);
                guider_ui.Home_del = true;
            }
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void Test_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        switch (CIT_UI.Window_Current_State)
        {
        case CIT_UI.Window_Current_State::Window_OLED_Brightness_Test:
            CIT_UI.Window_Button_Start_Testing_Flag = true;
            break;
        case CIT_UI.Window_Current_State::Window_OLED_Edge_Detection_Test:
            CIT_UI.Window_Button_Start_Testing_Flag = true;
            break;
        case CIT_UI.Window_Current_State::Window_OLED_Contrast_Test:
            CIT_UI.Window_Button_Start_Testing_Flag = true;
            break;
        case CIT_UI.Window_Current_State::Window_OLED_Display_Color_Test:
            CIT_UI.Window_Button_Start_Testing_Flag = true;
            break;

        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_Test(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Test, Test_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->Test_btnm_1, Test_btnm_1_event_handler, LV_EVENT_ALL, NULL);

    switch (CIT_UI.Window_Current_State)
    {
    case CIT_UI.Window_Current_State::Window_OLED_Brightness_Test:
        lv_obj_add_event_cb(ui->Test_btn_1, Test_btn_1_event_handler, LV_EVENT_ALL, NULL);
        break;
    case CIT_UI.Window_Current_State::Window_OLED_Edge_Detection_Test:
        lv_obj_add_event_cb(ui->Test_btn_1, Test_btn_1_event_handler, LV_EVENT_ALL, NULL);
        break;
    case CIT_UI.Window_Current_State::Window_OLED_Contrast_Test:
        lv_obj_add_event_cb(ui->Test_btn_1, Test_btn_1_event_handler, LV_EVENT_ALL, NULL);
        break;
    case CIT_UI.Window_Current_State::Window_OLED_Display_Color_Test:
        lv_obj_add_event_cb(ui->Test_btn_1, Test_btn_1_event_handler, LV_EVENT_ALL, NULL);
        break;

    default:
        break;
    }
}

void events_init(lv_ui *ui)
{
}
