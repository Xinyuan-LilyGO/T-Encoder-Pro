/*
 * @Description: None
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-12-08 10:45:26
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2023-12-08 10:53:54
 * @License: GPL 3.0
 */

#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_
#ifdef __cplusplus
extern "C"
{
#endif

#include "gui_guider.h"

    void events_init(lv_ui *ui);

    void events_init_Home(lv_ui *ui);
    void events_init_Test(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
