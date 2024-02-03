/**
 * @file lv_analogclock.h
 *
 */

#ifndef LV_ANALOGCLOCK_H
#define LV_ANALOGCLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../../lvgl.h"

#if LV_USE_ANALOGCLOCK != 0

/*Testing of dependencies*/
#if LV_DRAW_COMPLEX == 0
#error "lv_analogclock: Complex drawing is required. Enable it in lv_conf.h (LV_DRAW_COMPLEX 1)"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    lv_color_t tick_color;
    uint16_t tick_cnt;
    uint16_t tick_length;
    uint16_t tick_width;

    lv_color_t tick_major_color;
    uint16_t tick_major_nth;
    uint16_t tick_major_length;
    uint16_t tick_major_width;

    bool hide_label;
    int16_t label_gap;
    int16_t label_color;

    int32_t min;
    int32_t max;
    int16_t r_mod;
    uint16_t angle_range;
    int16_t rotation;
} lv_analogclock_scale_t;

enum {
    LV_analogclock_INDICATOR_TYPE_NEEDLE_IMG,
    LV_analogclock_INDICATOR_TYPE_NEEDLE_LINE,
    LV_analogclock_INDICATOR_TYPE_SCALE_LINES,
    LV_analogclock_INDICATOR_TYPE_ARC,
};
typedef uint8_t lv_analogclock_indicator_type_t;

typedef struct {
    lv_analogclock_scale_t * scale;
    lv_analogclock_indicator_type_t type;
    lv_opa_t opa;
    int32_t start_value;
    int32_t end_value;
    union {
        struct {
            const void * src;
            lv_point_t pivot;
        } needle_img;
        struct {
            uint16_t width;
            int16_t r_mod;
            lv_color_t color;
        } needle_line;
        struct {
            uint16_t width;
            const void * src;
            lv_color_t color;
            int16_t r_mod;
        } arc;
        struct {
            int16_t width_mod;
            lv_color_t color_start;
            lv_color_t color_end;
            uint8_t local_grad  : 1;
        } scale_lines;
    } type_data;
} lv_analogclock_indicator_t;

/*Data of line analogclock*/
typedef struct {
    lv_obj_t obj;
    lv_ll_t scale_ll;
    lv_analogclock_scale_t * scale;
    lv_ll_t indicator_ll;
    bool hide_point;
    lv_analogclock_indicator_t * hour_indic;
    lv_analogclock_indicator_t * min_indic;
    lv_analogclock_indicator_t * sec_indic;
} lv_analogclock_t;

extern const lv_obj_class_t lv_analogclock_class;

/**
 * `type` field in `lv_obj_draw_part_dsc_t` if `class_p = lv_analogclock_class`
 * Used in `LV_EVENT_DRAW_PART_BEGIN` and `LV_EVENT_DRAW_PART_END`
 */
typedef enum {
    LV_analogclock_DRAW_PART_ARC,             /**< The arc indicator*/
    LV_analogclock_DRAW_PART_NEEDLE_LINE,     /**< The needle lines*/
    LV_analogclock_DRAW_PART_NEEDLE_IMG,      /**< The needle images*/
    LV_analogclock_DRAW_PART_TICK,            /**< The tick lines and labels*/
} lv_analogclock_draw_part_type_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a analogclock object
 * @param parent pointer to an object, it will be the parent of the new bar.
 * @return pointer to the created analogclock
 */
lv_obj_t * lv_analogclock_create(lv_obj_t * parent);

/*=====================
 * Add scale
 *====================*/

/**
 * Add a new scale to the analogclock.
 * @param obj   pointer to a analogclock object
 * @return      the new scale
 * @note        Indicators can be attached to scales.
 */
lv_analogclock_scale_t * lv_analogclock_add_scale(lv_obj_t * obj);

/*=====================
 * Add scale
 *====================*/
/**
 * Set the properties of the ticks of a scale
 * @param obj       pointer to a analogclock object
 * @param scale     pointer to scale (added to `analogclock`)
 * @param cnt       number of tick lines
 * @param width     width of tick lines
 * @param len       length of tick lines
 * @param color     color of tick lines
 */
void lv_analogclock_set_ticks(lv_obj_t * obj, uint16_t width, uint16_t len, lv_color_t color);

/**
 * Make some "normal" ticks major ticks and set their attributes.
 * Texts with the current value are also added to the major ticks.
 * @param obj           pointer to a analogclock object
 * @param scale         pointer to scale (added to `analogclock`)
 * @param nth           make every Nth normal tick major tick. (start from the first on the left)
 * @param width         width of the major ticks
 * @param len           length of the major ticks
 * @param color         color of the major ticks
 * @param label_gap     gap between the major ticks and the labels
 */
void lv_analogclock_set_major_ticks(lv_obj_t * obj, uint16_t width, uint16_t len, lv_color_t color, int16_t label_gap);


/**
 * Set the value and angular range of a scale.
 * @param obj           pointer to a analogclock object
 * @param scale         pointer to scale (added to `analogclock`)
 * @param min           the minimum value
 * @param max           the maximal value
 * @param angle_range   the angular range of the scale
 * @param rotation      the angular offset from the 3 o'clock position (clock-wise)
 */
void lv_analogclock_set_scale_range(lv_obj_t * obj, lv_analogclock_scale_t * scale, int32_t min, int32_t max,
                                    uint32_t angle_range,
                                    uint32_t rotation);

/*=====================
 * Hide digits / centerpoint
 *====================*/

/**
 * Hide the digits or not
 * @param obj           pointer to a analogclock object
 * @param hide_digits   set whether has digits
 */
void lv_analogclock_hide_digits(lv_obj_t * obj, bool hide_digits);

/**
 * Hide the center point or not
 * @param obj           pointer to a analogclock object
 * @param hide_point    set whether has center point
 */
void lv_analogclock_hide_point(lv_obj_t * obj, bool hide_point);

/*=====================
 * Add indicator
 *====================*/

/**
 * Add a needle line indicator the scale
 * @param obj           pointer to a analogclock object
 * @param scale         pointer to scale (added to `analogclock`)
 * @param width         width of the line
 * @param color         color of the line
 * @param r_mod         the radius modifier (added to the scale's radius) to get the lines length
 * @return              the new indicator
 */
lv_analogclock_indicator_t * lv_analogclock_add_needle_line(lv_obj_t * obj, lv_analogclock_scale_t * scale,
                                                            uint16_t width,
                                                            lv_color_t color, int16_t r_mod);
void lv_analogclock_set_hour_needle_line(lv_obj_t * obj, uint16_t width,
                                         lv_color_t color, int16_t r_mod);
void lv_analogclock_set_min_needle_line(lv_obj_t * obj, uint16_t width,
                                        lv_color_t color, int16_t r_mod);
void lv_analogclock_set_sec_needle_line(lv_obj_t * obj, uint16_t width,
                                        lv_color_t color, int16_t r_mod);

/**
 * Add a needle image indicator the scale
 * @param obj           pointer to a analogclock object
 * @param scale         pointer to scale (added to `analogclock`)
 * @param src           the image source of the indicator. path or pointer to ::lv_img_dsc_t
 * @param pivot_x       the X pivot point of the needle
 * @param pivot_y       the Y pivot point of the needle
 * @return              the new indicator
 * @note                the needle image should point to the right, like -O----->
 */
lv_analogclock_indicator_t * lv_analogclock_add_needle_img(lv_obj_t * obj, lv_analogclock_scale_t * scale,
                                                           const void * src,
                                                           lv_coord_t pivot_x, lv_coord_t pivot_y);
void lv_analogclock_set_hour_needle_img(lv_obj_t * obj, const void * src,
                                        lv_coord_t pivot_x, lv_coord_t pivot_y);
void lv_analogclock_set_min_needle_img(lv_obj_t * obj, const void * src,
                                       lv_coord_t pivot_x, lv_coord_t pivot_y);
void lv_analogclock_set_sec_needle_img(lv_obj_t * obj, const void * src,
                                       lv_coord_t pivot_x, lv_coord_t pivot_y);

/**
 * Add an arc indicator the scale
 * @param obj           pointer to a analogclock object
 * @param scale         pointer to scale (added to `analogclock`)
 * @param width         width of the arc
 * @param color         color of the arc
 * @param r_mod         the radius modifier (added to the scale's radius) to get the outer radius of the arc
 * @return              the new indicator
 */
lv_analogclock_indicator_t * lv_analogclock_add_arc(lv_obj_t * obj, uint16_t width, lv_color_t color,
                                                    int16_t r_mod);


/**
 * Add a scale line indicator the scale. It will modify the ticks.
 * @param obj           pointer to a analogclock object
 * @param scale         pointer to scale (added to `analogclock`)
 * @param color_start   the start color
 * @param color_end     the end color
 * @param local         tell how to map start and end color. true: the indicator's start and end_value; false: the scale's min max value
 * @param width_mod     add this the affected tick's width
 * @return              the new indicator
 */
lv_analogclock_indicator_t * lv_analogclock_add_scale_lines(lv_obj_t * obj, lv_color_t color_start,
                                                            lv_color_t color_end, bool local, int16_t width_mod);

/*=====================
 * Set indicator value
 *====================*/

/**
 * Set the value of the indicator. It will set start and and value to the same value
 * @param obj           pointer to a analogclock object
 * @param indic         pointer to an indicator
 * @param value         the new value
 */
void lv_analogclock_set_indicator_value(lv_obj_t * obj, lv_analogclock_indicator_t * indic, int32_t value);

/**
 * Set the start value of the indicator.
 * @param obj           pointer to a analogclock object
 * @param indic         pointer to an indicator
 * @param value         the new value
 */
void lv_analogclock_set_indicator_start_value(lv_obj_t * obj, lv_analogclock_indicator_t * indic, int32_t value);

/**
 * Set the start value of the indicator.
 * @param obj           pointer to a analogclock object
 * @param indic         pointer to an indicator
 * @param value         the new value
 */
void lv_analogclock_set_indicator_end_value(lv_obj_t * obj, lv_analogclock_indicator_t * indic, int32_t value);

/**
 * Set the time of clock.
 * @param obj           pointer to a analogclock object
 * @param hour          hour value
 * @param min           minute value
 * @param sec           second value
 */
void lv_analogclock_set_time(lv_obj_t * obj, int32_t hour, int32_t min, int32_t sec);

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_ANALOGCLOCK*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_ANALOGCLOCK_H*/
