#pragma once
#include "ui.h"
#include <stdbool.h>
#include  "Arduino.h"
#include "Arduino_GFX_Library.h"

extern bool screen1_no_exit;

extern scr_lifecycle_t scr_menu; // menu
extern scr_lifecycle_t scr_clock; //
extern scr_lifecycle_t scr_home; // 
extern scr_lifecycle_t scr_setting; //
extern scr_lifecycle_t scr_meter; // power
extern scr_lifecycle_t scr_test; // test
extern scr_lifecycle_t scr_ws2812;
extern scr_lifecycle_t scr_colorwheel;

