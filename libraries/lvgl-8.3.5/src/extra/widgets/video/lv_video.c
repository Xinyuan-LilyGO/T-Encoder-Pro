/**
 * @file lv_video.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_video.h"

#if LV_USE_VIDEO != 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// for run on target function.
#if !LV_USE_GUIDER_SIMULATOR
    #include "FreeRTOS.h"
    #include "task.h"
    #include "sdcard.h"
    #include "h264_dec.h"
    #include "fsl_common.h"
    #include "fsl_debug_console.h"
    #include "fsl_pxp.h"
    #include "fsl_cache.h"
#else
    #include "decoder.h"
    #include <unistd.h>
#endif

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS &lv_video_class
#define LV_COLOR_SIZE 16
#ifndef DEMO_FILE_BUF_SIZE
    #define DEMO_FILE_BUF_SIZE (16 * 1024)
#endif
#ifndef DEMO_DECODE_BUF_SIZE
    #define DEMO_DECODE_BUF_SIZE (64 * 1024)
#endif

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static int16_t video_width = 0;
static int16_t video_height = 0;
static void lv_video_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_video_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);

#if !LV_USE_GUIDER_SIMULATOR
/* PXP Usage */

static void PXP_DisplayFrame(uint16_t width,
                             uint16_t height,
                             const uint8_t * Y,
                             const uint8_t * U,
                             const uint8_t * V,
                             uint32_t Y_Stride,
                             uint32_t UV_Stride,
                             lv_obj_t * obj);
#else
static void yuv420pToRgb565(int oriWidth,
                            int oriHeight,
                            int width, int height,
                            uint8_t * py, uint8_t * pu, uint8_t * pv,
                            unsigned short * dst);
static void CPU_DisplayFrame(SBufferInfo sDstBufInfo, unsigned char ** dst, lv_obj_t * obj);
#endif
/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_video_class = {
    .base_class = &lv_img_class,
    .instance_size = sizeof(lv_video_t),
    .width_def = LV_SIZE_CONTENT,
    .height_def = LV_SIZE_CONTENT,
    .constructor_cb = lv_video_constructor,
    .destructor_cb = lv_video_destructor,
};

#if !LV_USE_GUIDER_SIMULATOR
    /* PXP Usage */
    static pxp_output_buffer_config_t s_pxpOutputBufferConfig;
    static pxp_ps_buffer_config_t s_pxpPsBufferConfig;
    static volatile uint8_t s_lcdActiveFbIdx = 0;
    static int buffer_byte_per_pixel = 2;
    static uint8_t * s_lcdBuffer[2];
#else
    static int mallocInit = 0;
    static uint8_t * rgb, *py, *pu, *pv;
#endif

static uint8_t s_decodeBuf[DEMO_DECODE_BUF_SIZE];

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create an image button object
 * @param parent pointer to an object, it will be the parent of the new image button
 * @return pointer to the created image button
 */
lv_obj_t * lv_video_create(lv_obj_t * parent, int widgetWidth, int widgetHeight)
{
    LV_LOG_INFO("begin");

    video_width = widgetWidth;
    video_height = widgetHeight;

#if !LV_USE_GUIDER_SIMULATOR
    s_lcdBuffer[0] = malloc(widgetWidth * widgetHeight * buffer_byte_per_pixel);
    s_lcdBuffer[1] = malloc(widgetWidth * widgetHeight * buffer_byte_per_pixel);
#endif

    lv_obj_t * obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

void lv_video_play(lv_obj_t * obj)
{
    lv_video_t * video = (lv_video_t *)obj;
    Read_HFile(video->file_name, obj);
}

static int search_nalu(const uint8_t * data, int32_t len)
{
    int i;
    /* parse NALU 00 00 00 01 or 00 00 01 */
    for(i = 1; i < len - 4; i++) {
        if((data[i] == 0 && data[i + 1] == 0 && data[i + 2] == 0 && data[i + 3] == 1) ||
           (data[i] == 0 && data[i + 1] == 0 && data[i + 2] == 1)) {
            return i;
        }
    }

    if(data[i] == 0 && data[i + 1] == 0 && data[i + 2] == 1) {
        return i;
    }

    return -1;
}

int Decoder_Data(const uint8_t * data, int len, bool isStartOfFile, bool isEndOfFile, lv_obj_t * obj)
{
    lv_video_t * video = (lv_video_t *)obj;
    SBufferInfo sDstBufInfo = {0};
    int32_t copiedLen = 0;
    int32_t sliceSize = 0;
    uint8_t * dst[3];
    int32_t num_of_frames_in_buffer = 0;
    int32_t leftDataLen;

    static int32_t decodeBufStart = 0;
    static int32_t decodeBufEnd   = 0;

    if(isStartOfFile) {
        decodeBufStart         = 0;
        decodeBufEnd           = 0;
    }
    leftDataLen = len;

    while(leftDataLen > 0) {
        copiedLen = MIN(leftDataLen, ((int32_t)sizeof(s_decodeBuf) - decodeBufEnd));

        /* Copy the input data to the end of decode buffer. */
        memcpy(&s_decodeBuf[decodeBufEnd], data, copiedLen);
        decodeBufEnd += copiedLen;
        data += copiedLen;
        leftDataLen -= copiedLen;

        while(decodeBufStart < decodeBufEnd) {
            sliceSize = search_nalu(&s_decodeBuf[decodeBufStart], decodeBufEnd - decodeBufStart);
            if(video->exist) {
                return 0;
            }
            /* Could not find NALU. */
            if(sliceSize < 0) {
                /* This is the file end part, pass them all to H264 decoder. */
                if(isEndOfFile && (0 == leftDataLen)) {
                    sliceSize = decodeBufEnd - decodeBufStart;
                }
                else {
                    /* After searching the full buffer, no slice found, then drop the data in buffer. */
                    if((decodeBufStart == 0) && (decodeBufEnd == sizeof(s_decodeBuf))) {
                        /* Drop the decode buffer, fill using left input data. */
                        decodeBufEnd   = 0;
                        decodeBufStart = 0;
                    }

                    /* Have processed all slice in the buffer. */
                    break;
                }
            }
            /* Slice size too small, skip it. */
            else if(sliceSize < 4) {
                decodeBufStart += sliceSize;
                continue;
            }
            /* Found NALU, decode. */
            if(OpenH264_Decode(&s_decodeBuf[decodeBufStart], sliceSize, dst, &sDstBufInfo) == 0) {
                if(sDstBufInfo.iBufferStatus == 1) {
#if LV_USE_GUIDER_SIMULATOR
                    CPU_DisplayFrame(sDstBufInfo, dst, obj);
#else
                    PXP_DisplayFrame(
                        sDstBufInfo.UsrData.sSystemBuffer.iWidth, sDstBufInfo.UsrData.sSystemBuffer.iHeight,
                        sDstBufInfo.pDst[0], sDstBufInfo.pDst[1], sDstBufInfo.pDst[2],
                        sDstBufInfo.UsrData.sSystemBuffer.iStride[0], sDstBufInfo.UsrData.sSystemBuffer.iStride[1], obj);
#endif
                }

            }
            else {
                LV_LOG_ERROR("decode error\r\n");
            }

            decodeBufStart += sliceSize;
        }

        /* Move the left data in decode buffer to the start of decode buffer,
         * left input data will be appended to the end.
         */
        memcpy(s_decodeBuf, &s_decodeBuf[decodeBufStart], decodeBufEnd - decodeBufStart);
        decodeBufEnd -= decodeBufStart;
        decodeBufStart = 0;
    }

    if(isEndOfFile) {
        OpenH264_GetOption(&num_of_frames_in_buffer);
        for(int32_t i = 0; i < num_of_frames_in_buffer; i++) {
            dst[0] = NULL;
            dst[1] = NULL;
            dst[2] = NULL;

            OpenH264_FlashFrame(dst, &sDstBufInfo);
            if(sDstBufInfo.iBufferStatus == 1) {
#if LV_USE_GUIDER_SIMULATOR
                CPU_DisplayFrame(sDstBufInfo, dst, obj);
#else
                PXP_DisplayFrame(
                    sDstBufInfo.UsrData.sSystemBuffer.iWidth, sDstBufInfo.UsrData.sSystemBuffer.iHeight,
                    sDstBufInfo.pDst[0], sDstBufInfo.pDst[1], sDstBufInfo.pDst[2],
                    sDstBufInfo.UsrData.sSystemBuffer.iStride[0], sDstBufInfo.UsrData.sSystemBuffer.iStride[1], obj);
#endif
            }
        }
    }

    return 0;
}

void Read_HFile(const char * fileName, lv_obj_t * obj)
{
    lv_video_t * video = (lv_video_t *)obj;
    uint32_t bytesRead;
    while(1) {
        int error = lv_fs_open(&video->h264File, video->file_name, LV_FS_MODE_RD);
        if(error != LV_FS_RES_OK) {
            break;
        }
        video->fileStart = true;
        while(1) {
            if(video->play_status == 1) {
                error = lv_fs_read(&video->h264File, video->blk.data, DEMO_FILE_BUF_SIZE, &bytesRead);
                if(error != LV_FS_RES_OK) {
                    break;
                }
                video->blk.len           = bytesRead;
                video->blk.isEndOfFile   = (DEMO_FILE_BUF_SIZE > bytesRead);
                video->blk.isStartOfFile = video->fileStart;
                video->fileStart         = false;
                Decoder_Data(video->blk.data, video->blk.len, video->blk.isStartOfFile, video->blk.isEndOfFile, obj);
                if(video->blk.isEndOfFile) {
                    break;
                }
                if(video->exist) {
                    video->blk.data = NULL;
                    lv_fs_close(&video->h264File);
                    return;
                }
            }
            else {

#if LV_USE_GUIDER_SIMULATOR
                lv_task_handler();
                usleep(5 * 1000);
#else
                vTaskDelay(5);
#endif
                continue;
            }
        }
        lv_fs_close(&video->h264File);
    }
}

#if !LV_USE_GUIDER_SIMULATOR
int Video_InitPXP()
{
    /* Initialize variables. */


    memset(&s_pxpPsBufferConfig, 0, sizeof(s_pxpPsBufferConfig));
    memset(&s_pxpOutputBufferConfig, 0, sizeof(s_pxpOutputBufferConfig));
    memset(s_lcdBuffer[0], 0, video_width * video_height * buffer_byte_per_pixel);
    memset(s_lcdBuffer[1], 0, video_width * video_height * buffer_byte_per_pixel);
    s_pxpPsBufferConfig.pixelFormat = kPXP_PsPixelFormatYVU420;
    s_pxpPsBufferConfig.swapByte    = false,

    s_pxpOutputBufferConfig.pixelFormat    = kPXP_OutputPixelFormatRGB565;
    s_pxpOutputBufferConfig.interlacedMode = kPXP_OutputProgressive;
    s_pxpOutputBufferConfig.buffer1Addr    = 0U,
    s_pxpOutputBufferConfig.pitchBytes     = (video_width * buffer_byte_per_pixel);

    /* Initialize hardware. */
    PXP_Init(PXP);

    PXP_SetProcessSurfaceBackGroundColor(PXP, 0U);

    /* Disable AS. */
    PXP_SetAlphaSurfacePosition(PXP, 0xFFFFU, 0xFFFFU, 0U, 0U);

    PXP_SetCsc1Mode(PXP, kPXP_Csc1YCbCr2RGB);
    PXP_EnableCsc1(PXP, true);

    return 0;
}

static void PXP_DisplayFrame(uint16_t width,
                             uint16_t height,
                             const uint8_t * Y,
                             const uint8_t * U,
                             const uint8_t * V,
                             uint32_t Y_Stride,
                             uint32_t UV_Stride,
                             lv_obj_t * obj)
{
    lv_video_t * video = (lv_video_t *)obj;
    void * lcdFrameAddr;
    bool rotate                    = false;
    static uint16_t oldInputWidth  = 0U;
    static uint16_t oldInputHeight = 0U;

    uint16_t lcdWidth  = video_width;
    uint16_t lcdHeight = video_height;

    DCACHE_CleanInvalidateByRange((uint32_t)Y, height * Y_Stride);
    DCACHE_CleanInvalidateByRange((uint32_t)U, height * UV_Stride / 2);
    DCACHE_CleanInvalidateByRange((uint32_t)V, height * UV_Stride / 2);

    /* PS configure. */
    s_pxpPsBufferConfig.bufferAddr  = (uint32_t)Y;
    s_pxpPsBufferConfig.bufferAddrU = (uint32_t)U;
    s_pxpPsBufferConfig.bufferAddrV = (uint32_t)V;
    s_pxpPsBufferConfig.pitchBytes  = Y_Stride;

    PXP_SetProcessSurfaceBufferConfig(PXP, &s_pxpPsBufferConfig);

    /* Input frame size changed. */
    if((oldInputHeight != height) || (oldInputWidth != width)) {

        rotate = (height > width);

        if(rotate) {
            s_pxpOutputBufferConfig.width  = lcdHeight;
            s_pxpOutputBufferConfig.height = lcdWidth;

            PXP_SetRotateConfig(PXP, kPXP_RotateOutputBuffer, kPXP_Rotate90, kPXP_FlipDisable);
            PXP_SetProcessSurfaceScaler(PXP, width, height, lcdHeight, lcdWidth);
            PXP_SetProcessSurfacePosition(PXP, 0, 0, lcdHeight - 1, lcdWidth - 1);
        }
        else {
            s_pxpOutputBufferConfig.width  = lcdWidth;
            s_pxpOutputBufferConfig.height = lcdHeight;

            PXP_SetProcessSurfaceScaler(PXP, width, height, lcdWidth, lcdHeight);
            PXP_SetProcessSurfacePosition(PXP, 0, 0, lcdWidth - 1, lcdHeight - 1);
        }

        oldInputHeight = height;
        oldInputWidth  = width;
    }

    lcdFrameAddr                              = s_lcdBuffer[s_lcdActiveFbIdx ^ 1];
    s_pxpOutputBufferConfig.buffer0Addr = (uint32_t)lcdFrameAddr;

    PXP_SetOutputBufferConfig(PXP, &s_pxpOutputBufferConfig);
    PXP_Start(PXP);

    while(0U == (kPXP_CompleteFlag & PXP_GetStatusFlags(PXP))) {
    }
    PXP_ClearStatusFlags(PXP, kPXP_CompleteFlag);

    video->frameImage.data = lcdFrameAddr;
    s_lcdActiveFbIdx ^= 1;
    lv_img_set_src(obj, &video->frameImage);
}
#else
static void CPU_DisplayFrame(SBufferInfo sDstBufInfo, unsigned char ** dst, lv_obj_t * obj)
{
    lv_video_t * video = (lv_video_t *)obj;
    int width = 0;
    int height = 0;
    if(sDstBufInfo.iBufferStatus == 1) {
        width = sDstBufInfo.UsrData.sSystemBuffer.iWidth;
        height = sDstBufInfo.UsrData.sSystemBuffer.iHeight;
        int YStride = sDstBufInfo.UsrData.sSystemBuffer.iStride[0];
        int UVStride = sDstBufInfo.UsrData.sSystemBuffer.iStride[1];
        unsigned char * pPtr = NULL;
        if(mallocInit == 0) {
            rgb = malloc(2 * width * height);
            py = malloc(width * height);
            pu = malloc(width * height / 4);
            pv = malloc(width * height / 4);
            mallocInit = 1;
        }
        pPtr = dst[0];
        for(int i = 0; i < height; i++) {
            memcpy(py + i * width, pPtr, width);
            pPtr += YStride;
        }

        height = height / 2;
        width = width / 2;
        pPtr = dst[1];
        for(int i = 0; i < height; i++) {
            memcpy(pu + i * width, pPtr, width);
            pPtr += UVStride;
        }
        pPtr = dst[2];
        for(int i = 0; i < height; i++) {
            memcpy(pv + i * width, pPtr, width);
            pPtr += UVStride;
        }
        yuv420pToRgb565(width * 2, height * 2, video_width, video_height, py, pu, pv, (uint16_t *)rgb);
        // update the image data.
        video->frameImage.data = rgb;
        lv_img_set_src(obj, &video->frameImage);
        lv_img_cache_invalidate_src(lv_img_get_src(obj));
        lv_obj_invalidate(obj);
        lv_task_handler();
        usleep(30 * 1000);
    }
}

static void yuv420pToRgb565(int oriWidth, int oriHeight, int width, int height, uint8_t * py, uint8_t * pu,
                            uint8_t * pv, unsigned short * dst)
{
    int y, u, v, yy, vr, ug, vg, ub;
    int r, g, b;
    int oriLine, oriCol;

    for(int i = 0; i < height; i++) {
        oriLine = i * oriHeight / height;
        for(int j = 0; j < width; j++) {
            oriCol = j * oriWidth / width;
            y = py[oriLine * oriWidth + oriCol];
            yy = y << 8;
            u = pu[(oriLine / 2) * (oriWidth / 2) + (oriCol / 2)] - 128;
            ug = 88 * u;
            ub = 454 * u;
            v = pv[(oriLine / 2) * (oriWidth / 2) + (oriCol / 2)] - 128;
            vg = 183 * v;
            vr = 359 * v;

            r = (yy + vr) >> 8;
            g = (yy - ug - vg) >> 8;
            b = (yy + ub) >> 8;
            if(r < 0)
                r = 0;
            if(r > 255)
                r = 255;
            if(g < 0)
                g = 0;
            if(g > 255)
                g = 255;
            if(b < 0)
                b = 0;
            if(b > 255)
                b = 255;
            dst[i * width + j] = (((unsigned short)r >> 3) << 11) | (((unsigned short)g >> 2) << 5) | (((
                                                                                                            unsigned short)b >> 3) << 0);
        }
    }
}
#endif

/*=====================
 * Setter functions
 *====================*/

void lv_video_set_src(lv_obj_t * obj, const char * src)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_video_t * video = (lv_video_t *)obj;

    video->file_name = src;
}

void lv_video_set_status(lv_obj_t * obj, int status)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_video_t * video = (lv_video_t *)obj;

    video->play_status = status;
}

/*=====================
 * Getter functions
 *====================*/
int lv_video_get_status(lv_obj_t * obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_video_t * video = (lv_video_t *)obj;

    return video->play_status;
}


const char * lv_video_get_src(lv_obj_t * obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_video_t * video = (lv_video_t *)obj;

    return video->file_name;
}


/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_video_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    lv_video_t * video = (lv_video_t *)obj;

    video->play_status = 1;
    video->exist = false;
    OpenH264_Init();
    video->frameImage.header.always_zero = 0;
    video->frameImage.header.cf = LV_IMG_CF_TRUE_COLOR;
    video->frameImage.header.w = video_width;
    video->frameImage.header.h = video_height;
    video->frameImage.data_size = video_width * video_height * LV_COLOR_SIZE / 8;
    video->blk.data = (uint8_t *)malloc(DEMO_FILE_BUF_SIZE + 4);
    video->frameImage.data = NULL;
    video->fileStart = true;
    LV_TRACE_OBJ_CREATE("finished");
    lv_obj_update_layout(obj);
}

static void lv_video_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    lv_video_t * video = (lv_video_t *)obj;
    video->exist = true;
    if(video->blk.data) {
        free(video->blk.data);
        video->blk.data = NULL;
    }

#if LV_USE_GUIDER_SIMULATOR
    mallocInit = 0;
    if(rgb) {
        free(py);
        free(pu);
        free(pv);
        free(rgb);
    }
#else
    if(s_lcdBuffer[0] != NULL && s_lcdBuffer[1] != NULL) {
        free(s_lcdBuffer[0]);
        free(s_lcdBuffer[1]);
        s_lcdBuffer[0] = NULL;
        s_lcdBuffer[1] = NULL;
    }
#endif
    lv_img_cache_invalidate_src(lv_img_get_src(obj));
}
#endif
