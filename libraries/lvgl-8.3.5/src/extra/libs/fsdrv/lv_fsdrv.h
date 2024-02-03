/**
 * @file lv_fsdrv.h
 *
 */

#ifndef LV_FSDRV_H
#define LV_FSDRV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../../lv_conf_internal.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_FS_FATFS != '\0'
void lv_fs_fatfs_init(void);
#endif

#if LV_USE_FS_RAWFS != '\0'
#include "stdint.h"

typedef uint32_t rawfs_addr_t;
typedef uint32_t rawfs_size_t;

typedef struct _rawfs_file_t {
    rawfs_addr_t base;
    rawfs_addr_t offset;
    rawfs_size_t size;
    char * name;
} rawfs_file_t;

void lv_fs_rawfs_init(void);
#endif

#if LV_USE_FS_STDIO != '\0'
void lv_fs_stdio_init(void);
#endif

#if LV_USE_FS_POSIX != '\0'
void lv_fs_posix_init(void);
#endif

#if LV_USE_FS_WIN32 != '\0'
void lv_fs_win32_init(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_FSDRV_H*/

