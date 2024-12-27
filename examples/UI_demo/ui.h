/*********************************************************************************
 *                              include
 *********************************************************************************/
#pragma once
#include "lvgl.h"
#include "event/scr_mrg.h"
#include "assets/assets.h"
#include "port/lv_port_indev.h"

/*********************************************************************************
 *                               macro
 *********************************************************************************/
/** color schemes
    text: #1e1e00
    bg:   #fffee6
    c1:   #49a6fd
    c2:   #fefdb3
    c3:   #8617fd
*/
#define COLOR_BG      0xfffee6
#define COLOR_TEXT    0x1e1e00
#define COLOR_ACCENT1 0x49a6fd
#define COLOR_ACCENT2 0xe2e2df
#define COLOR_ACCENT3 0x8617fd

/*********************************************************************************
 *                            lvgl msg
 *********************************************************************************/
enum{
    // lvgl msg
    MSG_INDEV_TOUCH_X = 0,
    MSG_INDEV_TOUCH_Y,
    MSG_INDEV_ENCODER,
    MSG_DISP_BRIGHTNESS,
    MSG_TOUCH_LINE,
    MSG_INDEV_MODE,
    MSG_MENU_LABEL_ALIGN,
    // clock msg
    MSG_CLOCK_HOUR,
    MSG_CLOCK_MINUTE,
    MSG_CLOCK_SECOND,
    // ws2182 led msg
    MSG_WS2812_LIGHT,
    MSG_WS2812_COLOR,
    // meter msg
    MSG_METER_SPEED,
    MSG_METER_TEMPERTRUE,
    // WIFI msg
    MSG_WIFI_CONFIG,
};

/*********************************************************************************
 *                            eeprom layout
 *********************************************************************************/
#define EEPROM_UPDATA_FLAG_NUM 0xAA

enum{
    EEPROM_UPDATA_FLAG_ADDR = 0,
    EEPROM_DISPLAY_LIGHT_ADDR,
    EEPROM_TOUCH_LINE_ADDR,
    EEPROM_INDEV_MODE_ADDR,
    EEPROM_MENU_LABEL_ADDR,
    EEPROM_SIZE_MAX = 10,
};

/*********************************************************************************
 *                              variable
 *********************************************************************************/
enum{
    UI_SCR_ID_MENU = 0,
    UI_SCR_ID_1,
    UI_SCR_ID_2,
    UI_SCR_ID_3,
    UI_SCR_ID_4,
    UI_SCR_ID_5,
    UI_SCR_ID_6,
    UI_SCR_ID_7,
};

enum{
    UI_DATA_ID_1 = 0,
};

extern lv_coord_t lcd_width;
extern lv_coord_t lcd_height;
extern lv_group_t *encode_group;

/*********************************************************************************
 *                              function
 *********************************************************************************/
void ui_entry(void);
void back_btn_hidden(bool en);