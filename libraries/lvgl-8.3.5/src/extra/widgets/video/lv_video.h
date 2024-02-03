/**
 * @file lv_video.h
 *
 */

#ifndef LV_VIDEO_H
#define LV_VIDEO_H
#if !defined(MIN)
    #define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../../lvgl.h"

#if LV_USE_VIDEO != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    uint8_t * data;     /* Pointer to data. */
    uint32_t len;        /* Length of the data. */
    bool isEndOfFile;   /* Has reached file end. */
    bool isStartOfFile; /* Is start of file. */
} file_data_block_t;

typedef struct {
    lv_obj_t obj;
    const void * src; /*Image source: Pointer to an array or a file or a symbol*/
    lv_point_t offset;
    lv_coord_t w;          /*Width of the image (Handled by the library)*/
    lv_coord_t h;          /*Height of the image (Handled by the library)*/
    uint16_t angle;    /*rotation angle of the image*/
    lv_point_t pivot;     /*rotation center of the image*/
    uint16_t zoom;         /*256 means no zoom, 512 double size, 128 half size*/
    uint8_t src_type : 2;  /*See: lv_img_src_t*/
    uint8_t cf : 5;        /*Color format from `lv_img_color_format_t`*/
    uint8_t antialias : 1; /*Apply anti-aliasing in transformations (rotate, zoom)*/
    uint8_t obj_size_mode: 2; /*Image size mode when image size and object size is different.*/
    int play_status;
    const char * file_name;
    lv_img_dsc_t frameImage;
    lv_fs_file_t h264File;
    file_data_block_t blk;
    bool  fileStart;
    bool exist;
} lv_video_t;

extern const lv_obj_class_t lv_video_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_video_play(lv_obj_t * obj);

void Read_HFile(const char * fileName, lv_obj_t * obj);
int Video_InitPXP();
/**
 * Create an image button object
 * @param parent pointer to an object, it will be the parent of the new image button
 * @return pointer to the created image button
 */
lv_obj_t * lv_video_create(lv_obj_t * parent, int widgetWidth, int widgetHeight);


/*======================
 * Add/remove functions
 *=====================*/

/*=====================
 * Setter functions
 *====================*/

/**
 * Set images for a state of the image button
 * @param obj pointer to an image button object
 * @param state for which state set the new image
 */
void lv_video_set_src(lv_obj_t * obj, const char * src);

void lv_video_set_status(lv_obj_t * obj, int status);
/*=====================
 * Getter functions
 *====================*/

int lv_video_get_status(lv_obj_t * obj);
const char * lv_video_get_src(lv_obj_t * obj);

/*=====================
 * Other functions
 *====================*/

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_VIDEO*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_VIDEO_H*/
