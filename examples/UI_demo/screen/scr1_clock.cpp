
#include "screen.h"
/*********************************************************************************
 *                              SCREEN1
 *********************************************************************************/
static lv_obj_t * meter;
lv_meter_indicator_t * indic_min;
lv_meter_indicator_t * indic_hour;
lv_meter_indicator_t * indic_sec;

bool timer_anim_is_create = false;
bool screen1_no_exit = false;

void clock_event(lv_event_t *e)
{
    if(!screen1_no_exit){
        return;
    }

    lv_obj_t * meter = lv_event_get_target(e);
    lv_msg_t * m = lv_event_get_msg(e);
    int data = (int)lv_msg_get_user_data(m);
    const int32_t *v = (int32_t *)lv_msg_get_payload(m);

    switch (data)
    {
        case MSG_CLOCK_HOUR:  lv_meter_set_indicator_end_value(meter, indic_hour, *v); /* printf("hour:%d\n", *v);*/ break;
        case MSG_CLOCK_MINUTE: lv_meter_set_indicator_end_value(meter, indic_min, *v); /* printf("minu:%d\n", *v);*/ break;
        case MSG_CLOCK_SECOND: lv_meter_set_indicator_end_value(meter, indic_sec, *v); /* printf("seco:%d\n", *v);*/ break;
        default: break;
    }
}

void create1(lv_obj_t *parent)
{
    back_btn_hidden(false);
    screen1_no_exit = true;
    
    meter = lv_meter_create(parent);
    lv_obj_set_size(meter, lcd_width, lcd_width);
    lv_obj_center(meter);
    lv_obj_set_style_border_width(meter, 0, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(meter, 0, LV_PART_MAIN);
    lv_obj_set_style_outline_width(meter, 5, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(meter, lv_color_hex(COLOR_ACCENT3), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_text_font(meter, &lv_font_montserrat_26, LV_PART_MAIN);
    // lv_group_add_obj(encode_group, meter);
    lv_obj_set_style_bg_color(meter, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    lv_obj_add_event_cb(meter, clock_event, LV_EVENT_MSG_RECEIVED, NULL);
    lv_msg_subsribe_obj(MSG_CLOCK_HOUR,   meter, (void *)MSG_CLOCK_HOUR);
    lv_msg_subsribe_obj(MSG_CLOCK_MINUTE, meter, (void *)MSG_CLOCK_MINUTE);
    lv_msg_subsribe_obj(MSG_CLOCK_SECOND, meter, (void *)MSG_CLOCK_SECOND);

    /*Create a scale for the minutes*/
    /*61 ticks in a 360 degrees range (the last and the first line overlaps)*/
    lv_meter_scale_t * scale_min = lv_meter_add_scale(meter);
    lv_meter_set_scale_ticks(meter, scale_min, 61, 1, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_range(meter, scale_min, 0, 60, 360, 270);

    /*Create another scale for the hours. It's only visual and contains only major ticks*/
    lv_meter_scale_t * scale_hour = lv_meter_add_scale(meter);
    lv_meter_set_scale_ticks(meter, scale_hour, 12, 0, 0, lv_palette_main(LV_PALETTE_GREY));               /*12 ticks*/
    lv_meter_set_scale_major_ticks(meter, scale_hour, 1, 2, 20, lv_color_black(), 23);    /*Every tick is major*/
    lv_meter_set_scale_range(meter, scale_hour, 1, 12, 330, 300);       /*[1..12] values in an almost full circle*/

    /*Add a the hands from images*/
    indic_sec = lv_meter_add_needle_img(meter, scale_min, &img_hand_sec, 5, 5);
    indic_min = lv_meter_add_needle_img(meter, scale_min, &img_hand_min, 5, 5);
    indic_hour = lv_meter_add_needle_img(meter, scale_hour, &img_hand_hour, 5, 5);
    
    if(!timer_anim_is_create){
        timer_anim_is_create = true;
        // lv_timer_create(clock_anim_timer, 1000, NULL);
    }
}

void entry1(void) {}
void exit1(void) {}

void destroy1(void) {
    back_btn_hidden(true);
    screen1_no_exit = false;
}

scr_lifecycle_t scr_clock = {
    .create = create1,
    .entry = entry1,
    .exit = exit1,
    .destroy = destroy1,
};