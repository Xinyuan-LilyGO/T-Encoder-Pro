#include "screen.h"
/*********************************************************************************
 *                              SCREEN4
 *********************************************************************************/
static lv_obj_t * meter_speed;
lv_meter_indicator_t * indic_speed;
lv_meter_indicator_t * indic_knob_speed;

static lv_obj_t * meter_temp;
lv_meter_indicator_t * indic_temp;
lv_meter_indicator_t * indic_knob_temp;

int32_t speed_value = 0;
int32_t temp_value = 0;

void change_meter_event_cb(lv_event_t *e)
{
    /* get instance */
    lv_obj_t *tgt = lv_event_get_target(e);
    lv_event_code_t c = lv_event_get_code(e);
    lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);

    if (c == LV_EVENT_KEY && tgt == meter_speed) {
        char s = *((char *)lv_event_get_param(e));
        speed_value = indic_speed->end_value; // Get the current pointer position.

        if ((s == LV_KEY_RIGHT || s == LV_KEY_UP) && speed_value < indic_speed->scale->max) {
            speed_value++;
        } else if ((s == LV_KEY_LEFT || s == LV_KEY_DOWN) && speed_value > indic_speed->scale->min) {
            speed_value--;
        }
        lv_meter_set_indicator_end_value(meter_speed, indic_speed, speed_value);     // Update the pointer in the gauge 1.
        lv_meter_set_indicator_value(meter_speed, indic_knob_speed, speed_value);    // Update the pointer in the gauge 2.
        lv_label_set_text_fmt(label, "%d", speed_value);

        speed_value = lv_map(speed_value, 0, 100, 0, 255);
        lv_msg_send(MSG_METER_SPEED, &speed_value);
    }

    if (c == LV_EVENT_KEY && tgt == meter_temp) {
        char s = *((char *)lv_event_get_param(e));
        temp_value = indic_temp->end_value; // Get the current pointer position.

        if ((s == LV_KEY_RIGHT || s == LV_KEY_UP) && temp_value < indic_temp->scale->max) {
            temp_value++;
        } else if ((s == LV_KEY_LEFT || s == LV_KEY_DOWN) && temp_value > indic_temp->scale->min) {
            temp_value--;
        }
        lv_meter_set_indicator_end_value(meter_temp, indic_temp, temp_value);     // Update the pointer in the gauge 1.
        lv_meter_set_indicator_value(meter_temp, indic_knob_temp, temp_value); // Update the pointer in the gauge 2.
        lv_label_set_text_fmt(label, "%d°C", temp_value);
        lv_msg_send(MSG_METER_TEMPERTRUE, &temp_value);
    }
}

static void toggle_state_event_cb(lv_event_t *e) {
    lv_obj_t *instance = lv_event_get_target(e);
    lv_event_code_t c = lv_event_get_code(e);
    if (!lv_obj_has_flag(instance, LV_OBJ_FLAG_CHECKABLE)) {
        lv_obj_clear_flag(instance, LV_OBJ_FLAG_CHECKABLE);
        lv_group_set_editing(encode_group, false);
        printf("check false\n");
    } else {
        lv_obj_add_flag(instance, LV_OBJ_FLAG_CHECKABLE);
        lv_group_set_editing(encode_group, true);
        printf("check true\n");
    }
    printf("check\n");
}

void create4(lv_obj_t *parent)
{
    back_btn_hidden(false);

    lv_obj_t *label = lv_label_create(parent);
    lv_label_set_text(label, "Meter");
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

    meter_speed = lv_meter_create(parent);
    // lv_obj_center(meter_speed);
    // lv_obj_set_pos(meter_speed, lcd_width / 4, lcd_height / 4);
    lv_obj_set_size(meter_speed, lcd_width / 2 - 2, lcd_height / 2 - 2);
    lv_obj_set_style_border_width(meter_speed, 1, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(meter_speed, 0, LV_PART_MAIN);
    lv_obj_set_style_outline_width(meter_speed, 2, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(meter_speed, lv_color_hex(0x8617fd), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(meter_speed, LV_OPA_50, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_pad_all(meter_speed, 10, 0);
    lv_obj_set_style_text_font(meter_speed, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_set_style_bg_color(meter_speed, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    
    lv_obj_t *label2 = lv_label_create(meter_speed);
    lv_label_set_text(label2, "ws2812");
    lv_obj_align(label2, LV_ALIGN_BOTTOM_MID, 0, -20);

    lv_obj_t *speed_label = lv_label_create(meter_speed);
    lv_label_set_text_fmt(speed_label, "%d", speed_value);
    lv_obj_align(speed_label, LV_ALIGN_BOTTOM_MID, 0, -5);

    /*Add a scale first*/
    lv_meter_scale_t * scale = lv_meter_add_scale(meter_speed);
    lv_meter_set_scale_ticks(meter_speed, scale, 41, 2, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_major_ticks(meter_speed, scale, 8, 4, 15, lv_palette_main(LV_PALETTE_GREY), 15);
    lv_meter_set_scale_range(meter_speed, scale, 0, 100, 270, 135);

    /*Make the tick lines red at the end of the scale*/
    indic_speed = lv_meter_add_scale_lines(meter_speed, scale, lv_palette_main(LV_PALETTE_LIGHT_GREEN), lv_palette_main(LV_PALETTE_RED), false, 0);
    lv_meter_set_indicator_start_value(meter_speed, indic_speed, 0);
    lv_meter_set_indicator_end_value(meter_speed, indic_speed, speed_value);

    /*Add a needle line indicator*/
    indic_knob_speed = lv_meter_add_needle_line(meter_speed, scale, 2, lv_palette_main(LV_PALETTE_GREY), -10);
    lv_meter_set_indicator_value(meter_speed, indic_knob_speed, speed_value);

    lv_group_add_obj(encode_group, meter_speed);
    lv_obj_add_event_cb(meter_speed, toggle_state_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(meter_speed, change_meter_event_cb, LV_EVENT_KEY, (void *)speed_label);

    // ****************************************************************************************************
    meter_temp = lv_meter_create(parent);
    lv_obj_set_size(meter_temp, lcd_width / 2 - 2, lcd_height / 2 - 2);
    lv_obj_set_style_border_width(meter_temp, 1, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(meter_temp, 0, LV_PART_MAIN);
    lv_obj_set_style_outline_width(meter_temp, 2, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(meter_temp, lv_color_hex(0x8617fd), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(meter_temp, LV_OPA_50, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_bg_color(meter_temp, lv_color_hex(COLOR_BG), LV_PART_MAIN);
    lv_obj_set_style_pad_all(meter_temp, 2, 0);

    lv_obj_t * label1 = lv_label_create(meter_temp);
    lv_label_set_text(label1, "Temperature");
    lv_obj_align(label1, LV_ALIGN_BOTTOM_MID, 0, -120);

    lv_obj_t *temp_label = lv_label_create(meter_temp);
    lv_label_set_text_fmt(temp_label, "%d°C", temp_value);
    lv_obj_align(temp_label, LV_ALIGN_BOTTOM_MID, 0, -20);

    /* Add meter rules. */
    lv_meter_scale_t *scale_temp = lv_meter_add_scale(meter_temp);
    lv_meter_set_scale_ticks(meter_temp, scale_temp, 41, 5, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_range(meter_temp, scale_temp, 0, 100, 270, 135);
    /* Add gauge needle 1. */
    indic_temp = lv_meter_add_scale_lines(meter_temp, scale_temp, lv_palette_main(LV_PALETTE_LIGHT_BLUE), lv_palette_main(LV_PALETTE_RED), false, 0);
    lv_meter_set_indicator_start_value(meter_temp, indic_temp, 0);
    lv_meter_set_indicator_end_value(meter_temp, indic_temp, temp_value);
    /* Add gauge needle 2. */
    indic_knob_temp = lv_meter_add_needle_line(meter_temp, scale_temp, 2, lv_palette_main(LV_PALETTE_GREY), -20);
    lv_meter_set_indicator_value(meter_temp, indic_knob_temp, temp_value);

    lv_group_add_obj(encode_group, meter_temp);
    lv_obj_add_event_cb(meter_temp, toggle_state_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(meter_temp, change_meter_event_cb, LV_EVENT_KEY, (void *)temp_label);
}
void entry4(void) {
    uint16_t circle_radius = lcd_width / 4;

    lv_obj_set_pos(meter_speed, 0, circle_radius);
    lv_obj_set_pos(meter_temp, circle_radius *2, circle_radius);
}
void exit4(void) {}
void destroy4(void) {
    back_btn_hidden(true);
}

scr_lifecycle_t scr_meter = {
    .create = create4,
    .entry = entry4,
    .exit = exit4,
    .destroy = destroy4,
};