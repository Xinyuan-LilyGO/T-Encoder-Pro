
/**
 * @file lv_zh_keyboard.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_zh_keyboard.h"
#if LV_USE_ZH_KEYBOARD

#include "../../../lvgl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chinese_library.h"

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS &lv_zh_keyboard_class
#define LV_KB_BTN(width) LV_BTNMATRIX_CTRL_POPOVER | width

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_zh_keyboard_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_zh_keyboard_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_zh_keyboard_update_map(lv_obj_t * obj, uint8_t input_type);
static void lv_zh_keyboard_update_ctrl_map(lv_obj_t * obj, uint8_t input_type);
static void init_selection_box(lv_obj_t * parent);
static void switch_input_type(uint8_t inputType);
static void set_selection_box(uint8_t cand_show);
static void show_chinese(char * text_uft8);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t lv_zh_keyboard_class = {
    .constructor_cb = lv_zh_keyboard_constructor,
    .destructor_cb = lv_zh_keyboard_destructor,
    .width_def = LV_PCT(100),
    .height_def = LV_PCT(50),
    .instance_size = sizeof(lv_zh_keyboard_t),
    .editable = 1,
    .base_class = &lv_btnmatrix_class
};

static const char * const default_kb_map_lc[] = {" ", "\n", " ", "\n",
                                                 "1#", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", LV_SYMBOL_BACKSPACE, "\n",
                                                 "ABC", "a", "s", "d", "f", "g", "h", "j", "k", "l", LV_SYMBOL_NEW_LINE, "\n",
                                                 "_", "-", "z", "x", "c", "v", "b", "n", "m", ".", ",", ":", "\n",
                                                 LV_SYMBOL_KEYBOARD, "En/Zh", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
                                                };

static const lv_btnmatrix_ctrl_t default_kb_ctrl_lc_map[] = {
    LV_BTNMATRIX_CTRL_HIDDEN, LV_BTNMATRIX_CTRL_HIDDEN,
    LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 5, LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 6, LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1), LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1), LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1), LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1),
    LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_BTNMATRIX_CTRL_CHECKED | 2, 6, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 2
};

static const char * const default_kb_map_uc[] = {" ", "\n",
                                                 " ", "\n",
                                                 "1#", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", LV_SYMBOL_BACKSPACE, "\n",
                                                 "abc", "A", "S", "D", "F", "G", "H", "J", "K", "L", LV_SYMBOL_NEW_LINE, "\n",
                                                 "_", "-", "Z", "X", "C", "V", "B", "N", "M", ".", ",", ":", "\n",
                                                 LV_SYMBOL_KEYBOARD, "En/Zh", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
                                                };

static const lv_btnmatrix_ctrl_t default_kb_ctrl_uc_map[] = {
    LV_BTNMATRIX_CTRL_HIDDEN, LV_BTNMATRIX_CTRL_HIDDEN,
    LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 5, LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 6, LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1), LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1), LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1), LV_BTNMATRIX_CTRL_CHECKED | LV_KB_BTN(1),
    LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_BTNMATRIX_CTRL_CHECKED | 2, 6, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 2
};

static const char * const default_kb_map_spec[] = {" ", "\n",
                                                   " ", "\n",
                                                   "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n",
                                                   "abc", "+", "-", "/", "*", "=", "%", "!", "?", "#", "<", ">", "\n",
                                                   "\\", "@", "$", "(", ")", "{", "}", "[", "]", ";", "\"", "'", "\n",
                                                   LV_SYMBOL_KEYBOARD, "En/Zh", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
                                                  };

static const lv_btnmatrix_ctrl_t default_kb_ctrl_spec_map[] = {
    LV_BTNMATRIX_CTRL_HIDDEN, LV_BTNMATRIX_CTRL_HIDDEN,
    LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_BTNMATRIX_CTRL_CHECKED | 2,
    LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1),
    LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1),
    LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_BTNMATRIX_CTRL_CHECKED | 2, 6, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 2
};

static const char * const default_kb_map_num[] = {"1", "2", "3", LV_SYMBOL_KEYBOARD, "\n",
                                                  "4", "5", "6", LV_SYMBOL_OK, "\n",
                                                  "7", "8", "9", LV_SYMBOL_BACKSPACE, "\n",
                                                  "+/-", "0", ".", LV_SYMBOL_LEFT, LV_SYMBOL_RIGHT, ""
                                                 };

static const lv_btnmatrix_ctrl_t default_kb_ctrl_num_map[] = {
    1, 1, 1, LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 2,
    1, 1, 1, LV_ZH_KEYBOARD_CTRL_BTN_FLAGS | 2,
    1, 1, 1, 2,
    1, 1, 1, 1, 1
};

static const char ** en_kb_map[9] = {
    (const char **) & default_kb_map_lc[4],
    (const char **) & default_kb_map_uc[4],
    (const char **) & default_kb_map_spec[4],
    (const char **)default_kb_map_num,
    (const char **)default_kb_map_lc,
    (const char **)default_kb_map_lc,
    (const char **)default_kb_map_lc,
    (const char **)default_kb_map_lc,
    (const char **)NULL,
};

static const lv_btnmatrix_ctrl_t * en_kb_ctrl[9] = {
    &default_kb_ctrl_lc_map[2],
    &default_kb_ctrl_uc_map[2],
    &default_kb_ctrl_spec_map[2],
    default_kb_ctrl_num_map,
    default_kb_ctrl_lc_map,
    default_kb_ctrl_lc_map,
    default_kb_ctrl_lc_map,
    default_kb_ctrl_lc_map,
    NULL,
};

static const char ** zh_kb_map[9] = {
    (const char **)default_kb_map_lc,
    (const char **)default_kb_map_uc,
    (const char **)default_kb_map_spec,
    (const char **)default_kb_map_num,
    (const char **)default_kb_map_lc,
    (const char **)default_kb_map_lc,
    (const char **)default_kb_map_lc,
    (const char **)default_kb_map_lc,
    (const char **)NULL,
};

static const lv_btnmatrix_ctrl_t * zh_kb_ctrl[9] = {
    default_kb_ctrl_lc_map,
    default_kb_ctrl_uc_map,
    default_kb_ctrl_spec_map,
    default_kb_ctrl_num_map,
    default_kb_ctrl_lc_map,
    default_kb_ctrl_lc_map,
    default_kb_ctrl_lc_map,
    default_kb_ctrl_lc_map,
    NULL,
};

typedef struct zh_input_function {
    uint8_t input_type;
    lv_font_t * custom_font;
    lv_obj_t * obj_key_board;
    lv_obj_t * obj_selection_box;
    lv_obj_t * pinyin_label;
    lv_obj_t * adjustable_box;
    lv_obj_t * drop_btn_label;
    uint8_t extend_flag;
    char * matched_txt;
} zh_input_struct;

static zh_input_struct * zh_input_obj = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create a Keyboard object
 * @param parent pointer to an object, it will be the parent of the new keyboard
 * @param zh_font pointer to an font object.
 * @return pointer to the created keyboard
 */
lv_obj_t * lv_zh_keyboard_create(lv_obj_t * parent, const lv_font_t * zh_font)
{
    LV_LOG_INFO("begin");
    if(zh_input_obj) {
        return NULL;
    }

    else {
        zh_input_obj = lv_mem_alloc(sizeof(zh_input_struct));
        if(zh_input_obj == NULL)
            return NULL;
        lv_memset(zh_input_obj, 0, sizeof(zh_input_struct));
        zh_input_obj->custom_font = (lv_font_t *)zh_font;
    }
    lv_obj_t * obj = lv_obj_class_create_obj(&lv_zh_keyboard_class, parent);
    lv_obj_class_init_obj(obj);
    lv_group_remove_obj(obj);
    return obj;
}

/*=====================
 * Setter functions
 *====================*/

/**
 * Assign a Text Area to the Keyboard. The pressed characters will be put there.
 * @param kb pointer to a Keyboard object
 * @param ta pointer to a Text Area object to write there
 */
void lv_zh_keyboard_set_textarea(lv_obj_t * obj, lv_obj_t * ta)
{
    if(ta) {
        LV_ASSERT_OBJ(ta, &lv_textarea_class);
    }

    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;

    /*Hide the cursor of the old Text area if cursor management is enabled*/
    if(keyboard->ta) {
        lv_obj_clear_state(obj, LV_STATE_FOCUSED);
    }

    keyboard->ta = ta;

    /*Show the cursor of the new Text area if cursor management is enabled*/
    if(keyboard->ta) {
        lv_obj_add_flag(obj, LV_STATE_FOCUSED);
    }

    if(keyboard->ta) {
        if(zh_input_obj->input_type) {
            lv_obj_clear_flag(zh_input_obj->obj_selection_box, LV_OBJ_FLAG_HIDDEN);
        }
        else {
            lv_obj_add_flag(zh_input_obj->obj_selection_box, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

/**
 * Set a new a mode (text or number map)
 * @param kb pointer to a Keyboard object
 * @param mode the mode from 'lv_keyboard_mode_t'
 */
void lv_zh_keyboard_set_mode(lv_obj_t * obj, lv_zh_keyboard_mode_t mode)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;
    if(keyboard->mode == mode)
        return;

    keyboard->mode = mode;
    lv_zh_keyboard_update_map(obj, zh_input_obj->input_type);
    switch_input_type(zh_input_obj->input_type);
}

/**
 * Show the button title in a popover when pressed.
 * @param kb pointer to a Keyboard object
 * @param en whether "popovers" mode is enabled
 */
void lv_zh_keyboard_set_popovers(lv_obj_t * obj, bool en)
{
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;

    if(keyboard->popovers == en) {
        return;
    }

    keyboard->popovers = en;
    lv_zh_keyboard_update_ctrl_map(obj, zh_input_obj->input_type);
}

/**
 * Set a new map for the keyboard
 * @param kb pointer to a Keyboard object
 * @param mode keyboard map to alter 'lv_keyboard_mode_t'
 * @param map pointer to a string array to describe the map.
 *            See 'lv_btnmatrix_set_map()' for more info.
 */
void lv_zh_keyboard_set_map(lv_obj_t * obj, lv_zh_keyboard_mode_t mode, const char * map[],
                            const lv_btnmatrix_ctrl_t ctrl_map[])
{
    en_kb_map[mode] = map;
    en_kb_ctrl[mode] = ctrl_map;
    lv_zh_keyboard_update_map(obj, zh_input_obj->input_type);
}

/*=====================
 * Getter functions
 *====================*/

/**
 * Assign a Text Area to the Keyboard. The pressed characters will be put there.
 * @param kb pointer to a Keyboard object
 * @return pointer to the assigned Text Area object
 */
lv_obj_t * lv_zh_keyboard_get_textarea(const lv_obj_t * obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;
    return keyboard->ta;
}

/**
 * Set a new a mode (text or number map)
 * @param kb pointer to a Keyboard object
 * @return the current mode from 'lv_keyboard_mode_t'
 */
lv_zh_keyboard_mode_t lv_zh_keyboard_get_mode(const lv_obj_t * obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;
    return keyboard->mode;
}

/**
 * Tell whether "popovers" mode is enabled or not.
 * @param kb pointer to a Keyboard object
 * @return true: "popovers" mode is enabled; false: disabled
 */
bool lv_zh_btnmatrix_get_popovers(const lv_obj_t * obj)
{
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;
    return keyboard->popovers;
}

/*=====================
 * Other functions
 *====================*/
/**
 * Default keyboard event to add characters to the Text area and change the map.
 * If a custom `event_cb` is added to the keyboard this function can be called from it to handle the
 * button clicks
 * @param kb pointer to a keyboard
 * @param event the triggering event
 */
void lv_zh_keyboard_def_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);

    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;
    uint16_t btn_id = lv_btnmatrix_get_selected_btn(obj);
    if(btn_id == LV_BTNMATRIX_BTN_NONE)
        return;

    const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if(txt == NULL)
        return;

    if(strcmp(txt, "abc") == 0) {
        keyboard->mode = LV_ZH_KEYBOARD_MODE_TEXT_LOWER;
        lv_zh_keyboard_update_map(obj, zh_input_obj->input_type);
        return;
    }
    else if(strcmp(txt, "ABC") == 0) {
        keyboard->mode = LV_ZH_KEYBOARD_MODE_TEXT_UPPER;
        lv_zh_keyboard_update_map(obj, zh_input_obj->input_type);
        return;
    }
    else if(strcmp(txt, "1#") == 0) {
        keyboard->mode = LV_ZH_KEYBOARD_MODE_SPECIAL;
        lv_zh_keyboard_update_map(obj, zh_input_obj->input_type);
        return;
    }
    else if(strcmp(txt, LV_SYMBOL_CLOSE) == 0 || strcmp(txt, LV_SYMBOL_KEYBOARD) == 0) {
        lv_res_t res = lv_event_send(obj, LV_EVENT_CANCEL, NULL);
        if(res != LV_RES_OK)
            return;

        if(keyboard->ta) {
            res = lv_event_send(keyboard->ta, LV_EVENT_CANCEL, NULL);
            if(res != LV_RES_OK)
                return;
        }
        return;
    }
    else if(strcmp(txt, LV_SYMBOL_OK) == 0) {
        lv_res_t res = lv_event_send(obj, LV_EVENT_READY, NULL);
        if(res != LV_RES_OK)
            return;

        if(keyboard->ta) {
            res = lv_event_send(keyboard->ta, LV_EVENT_READY, NULL);
            if(res != LV_RES_OK)
                return;
        }
        return;
    }
    else if(strcmp(txt, "En/Zh") == 0) {
        if(zh_input_obj->input_type == 0) {
            zh_input_obj->input_type = 1;
        }
        else {
            zh_input_obj->input_type = 0;
        }
        lv_zh_keyboard_update_map(obj, zh_input_obj->input_type);
        switch_input_type(zh_input_obj->input_type);
        return;
    }

    /*Add the characters to the text area if set*/
    if(keyboard->ta == NULL)
        return;

    if(strcmp(txt, "Enter") == 0 || strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
        lv_textarea_add_char(keyboard->ta, '\n');
        if(lv_textarea_get_one_line(keyboard->ta)) {
            lv_res_t res = lv_event_send(keyboard->ta, LV_EVENT_READY, NULL);
            if(res != LV_RES_OK)
                return;
        }
    }
    else if(strcmp(txt, LV_SYMBOL_LEFT) == 0) {
        lv_textarea_cursor_left(keyboard->ta);
    }
    else if(strcmp(txt, LV_SYMBOL_RIGHT) == 0) {
        lv_textarea_cursor_right(keyboard->ta);
    }
    else if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
        const char * pinyin_str;
        pinyin_str = lv_textarea_get_text(zh_input_obj->pinyin_label);
        if(pinyin_str[0] != 0) {
            lv_textarea_del_char(zh_input_obj->pinyin_label);
            const char * kb_input = lv_textarea_get_text(zh_input_obj->pinyin_label);
            if(kb_input[0] != 0) {
                zh_input_obj->matched_txt = get_chinese((char *)kb_input);
                show_chinese(zh_input_obj->matched_txt);
            }
            return;
        }
        else {
            lv_textarea_set_text(zh_input_obj->adjustable_box, "");
        }
        lv_textarea_del_char(keyboard->ta);
    }
    else if(strcmp(txt, "+/-") == 0) {
        uint16_t cur = lv_textarea_get_cursor_pos(keyboard->ta);
        const char * ta_txt = lv_textarea_get_text(keyboard->ta);
        if(ta_txt[0] == '-') {
            lv_textarea_set_cursor_pos(keyboard->ta, 1);
            lv_textarea_del_char(keyboard->ta);
            lv_textarea_add_char(keyboard->ta, '+');
            lv_textarea_set_cursor_pos(keyboard->ta, cur);
        }
        else if(ta_txt[0] == '+') {
            lv_textarea_set_cursor_pos(keyboard->ta, 1);
            lv_textarea_del_char(keyboard->ta);
            lv_textarea_add_char(keyboard->ta, '-');
            lv_textarea_set_cursor_pos(keyboard->ta, cur);
        }
        else {
            lv_textarea_set_cursor_pos(keyboard->ta, 0);
            lv_textarea_add_char(keyboard->ta, '-');
            lv_textarea_set_cursor_pos(keyboard->ta, cur + 1);
        }
    }
    else {
        if(keyboard->ta) {
            if((zh_input_obj->input_type == 0) || (keyboard->mode == LV_ZH_KEYBOARD_MODE_SPECIAL)) {
                lv_textarea_add_text(keyboard->ta, txt);
            }
            else if(zh_input_obj->input_type == 1) {
                lv_textarea_add_text(zh_input_obj->pinyin_label, txt);
                const char * kb_input = lv_textarea_get_text(zh_input_obj->pinyin_label);
                if(kb_input[0] != 0) {
                    zh_input_obj->matched_txt = get_chinese((char *)kb_input);
                    show_chinese(zh_input_obj->matched_txt);
                }
            }
        }
    }
}

/**
 * Find Chinese characters based on pinyin.
 * @param input_string pointer to input pinyin.
 * @return pointer to chinese characters.
 */

char * get_chinese(char * input_string)
{
    char i, cInputStrLength;
    int pinyinLen, j;

    cInputStrLength = strlen(input_string);
    if(*input_string == '\0' || *input_string == 'i' || *input_string == 'u' || *input_string == 'v') {
        return NULL;
    }

    for(i = 0; i < cInputStrLength; i++) {
        *(input_string + i) |= 0x20;
    }
    pinyinLen = sizeof(PINYIN_SUMMARY) / sizeof(PINYIN_SUMMARY[0]);

    for(j = 0; j < pinyinLen; j++) {
        if(strcmp(input_string, PINYIN_SUMMARY[j].PINYIN) == 0) {
            return PINYIN_SUMMARY[j].PINYIN_mp;
        }
    }
    return NULL;
}

/**
 * Tell whether "popovers" mode is enabled or not.
 * @param kb pointer to a Keyboard object
 * @return true: "popovers" mode is enabled; false: disabled
 */

static void switch_input_type(uint8_t inputType)
{
    zh_input_obj->matched_txt = NULL;
    if(inputType == 0) {
        set_selection_box(0);
    }
    else if(inputType == 1) {
        set_selection_box(1);
    }
}

static void font_click_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);

    static uint16_t index = 0;
    if(code == LV_EVENT_CLICKED) {
        index = lv_textarea_get_cursor_pos(ta);
        if(index % 2 == 0) {
            index = index / 2;
            if(zh_input_obj->matched_txt != NULL && index < strlen(zh_input_obj->matched_txt) / 3) {
                char uft8_char[3] = {0};
                lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)zh_input_obj->obj_key_board;
                lv_memcpy(uft8_char, &zh_input_obj->matched_txt[index * 3], 3);
                if(keyboard->ta != NULL) {
                    lv_textarea_add_text(keyboard->ta, uft8_char);
                    lv_textarea_set_text(zh_input_obj->adjustable_box, "");
                    zh_input_obj->matched_txt = NULL;
                    lv_textarea_set_text(zh_input_obj->pinyin_label, "");
                }
            }
        }
    }
}

static void expand_retract_click_cb(lv_event_t * e)
{
    zh_input_obj->extend_flag = (zh_input_obj->extend_flag == 1) ? 2 : 1;
    set_selection_box(zh_input_obj->extend_flag);
}

static void set_selection_box(uint8_t cand_show)
{
    if(zh_input_obj->obj_selection_box != NULL) {
        if(cand_show == 0) {
            lv_obj_add_flag(zh_input_obj->obj_selection_box, LV_OBJ_FLAG_HIDDEN);
        }
        else if(cand_show == 1) {
            lv_textarea_set_one_line(zh_input_obj->adjustable_box, true);
            lv_obj_set_scroll_dir(zh_input_obj->adjustable_box, LV_DIR_HOR);
            lv_obj_set_height(zh_input_obj->adjustable_box, 38);
            lv_obj_set_height(zh_input_obj->obj_selection_box, 38);
            lv_label_set_text(zh_input_obj->drop_btn_label, LV_SYMBOL_DOWN);
            lv_obj_clear_flag(zh_input_obj->obj_selection_box, LV_OBJ_FLAG_HIDDEN);

        }
        else if(cand_show == 2) {
            lv_textarea_set_one_line(zh_input_obj->adjustable_box, false);
            lv_obj_set_scroll_dir(zh_input_obj->adjustable_box, LV_DIR_VER);
            lv_obj_set_height(zh_input_obj->adjustable_box, lv_obj_get_height(zh_input_obj->obj_key_board));
            lv_obj_set_height(zh_input_obj->obj_selection_box, lv_obj_get_height(zh_input_obj->obj_key_board));
            lv_label_set_text(zh_input_obj->drop_btn_label, LV_SYMBOL_UP);
            lv_obj_clear_flag(zh_input_obj->obj_selection_box, LV_OBJ_FLAG_HIDDEN);

        }
    }
}

static void show_chinese(char * chineseText)
{
    if(chineseText != NULL) {
        size_t i = 0, j = 0;
        char resultText[4 * 120 + 12] = {0};
        for(i = 0; i < strlen(chineseText); i++) {
            if(chineseText[i] == 0) break;
            resultText[j++] = chineseText[i];
            if((i + 1) % 3 == 0) {
                resultText[j++] = ' ';
            }
        }
        lv_textarea_set_text(zh_input_obj->adjustable_box, resultText);
        lv_obj_scroll_to(zh_input_obj->adjustable_box, 0, 0, LV_ANIM_OFF);
    }
    else {
        lv_textarea_set_text(zh_input_obj->adjustable_box, "");
    }
    return;
}

static void init_selection_box(lv_obj_t * parent)
{
    lv_obj_update_layout(parent);
    lv_obj_set_style_bg_opa(parent, LV_OPA_COVER, 0);
    zh_input_obj->obj_selection_box = lv_obj_create(parent);
    lv_obj_align(zh_input_obj->obj_selection_box, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_width(zh_input_obj->obj_selection_box, lv_obj_get_width(parent));
    lv_obj_set_style_bg_color(zh_input_obj->obj_selection_box, lv_color_hex(0xf7f7f7), 0);
    lv_obj_set_style_pad_all(zh_input_obj->obj_selection_box, 5, 0);
    lv_obj_set_style_pad_top(zh_input_obj->obj_selection_box, 12, 0);
    lv_obj_clear_flag(zh_input_obj->obj_selection_box, LV_OBJ_FLAG_SCROLLABLE);

    zh_input_obj->pinyin_label = lv_textarea_create(zh_input_obj->obj_selection_box);
    lv_obj_remove_style_all(zh_input_obj->pinyin_label);
    lv_obj_align(zh_input_obj->pinyin_label, LV_ALIGN_TOP_LEFT, 0, -12);
    lv_obj_clear_flag(zh_input_obj->pinyin_label, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_size(zh_input_obj->pinyin_label, lv_obj_get_width(zh_input_obj->obj_selection_box), 20);
    lv_obj_set_style_text_font(zh_input_obj->pinyin_label, &lv_font_montserrat_12, 0);
    lv_obj_set_style_text_color(zh_input_obj->pinyin_label, lv_color_hex(0x262626), 0);

    lv_obj_t * ext_btn = lv_btn_create(zh_input_obj->obj_selection_box);
    lv_obj_remove_style_all(ext_btn);
    lv_obj_align(ext_btn, LV_ALIGN_TOP_RIGHT, 0, -5);
    lv_obj_set_size(ext_btn, 30, 30);
    lv_obj_add_event_cb(ext_btn, expand_retract_click_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_clear_flag(ext_btn, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_FLOATING);
    zh_input_obj->drop_btn_label = lv_label_create(ext_btn);
    lv_obj_set_align(zh_input_obj->drop_btn_label, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(zh_input_obj->drop_btn_label, LV_FONT_DEFAULT, 0);
    lv_label_set_text(zh_input_obj->drop_btn_label, LV_SYMBOL_DOWN);
    lv_obj_set_style_text_color(zh_input_obj->drop_btn_label, lv_color_hex(0x262626), 0);
    lv_obj_update_layout(zh_input_obj->obj_selection_box);

    int16_t width;
    zh_input_obj->adjustable_box = lv_textarea_create(zh_input_obj->obj_selection_box);
    width = lv_obj_get_width(zh_input_obj->obj_selection_box) - lv_obj_get_width(ext_btn) - 20;
    lv_obj_remove_style_all(zh_input_obj->adjustable_box);
    lv_obj_set_width(zh_input_obj->adjustable_box, width);
    lv_obj_set_style_text_font(zh_input_obj->adjustable_box, zh_input_obj->custom_font, 0);
    lv_obj_set_style_text_color(zh_input_obj->adjustable_box, lv_color_hex(0x262626), 0);
    lv_obj_align(zh_input_obj->adjustable_box, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_clear_flag(zh_input_obj->adjustable_box, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_add_event_cb(zh_input_obj->adjustable_box, font_click_event_cb, LV_EVENT_CLICKED, 0);

    lv_obj_update_layout(parent);
    switch_input_type(zh_input_obj->input_type);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_zh_keyboard_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE);

    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;
    keyboard->ta = NULL;
    keyboard->mode = LV_ZH_KEYBOARD_MODE_TEXT_LOWER;
    keyboard->popovers = 0;

    lv_disp_t * disp = lv_obj_get_disp(obj);
    obj->class_p = &lv_zh_keyboard_class;
    disp->theme->apply_cb(NULL, obj);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    zh_input_obj->obj_key_board = obj;
    zh_input_obj->input_type = 1;
    zh_input_obj->extend_flag = 1;
    lv_obj_align(obj, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_add_event_cb(obj, lv_zh_keyboard_def_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_set_style_base_dir(obj, LV_BASE_DIR_LTR, 0);
    lv_zh_keyboard_update_map(obj, 1);
    lv_obj_update_layout(obj);
    init_selection_box(obj);
}

/**
 * Update the key and control map for the current mode
 * @param obj pointer to a keyboard object
 */
static void lv_zh_keyboard_update_map(lv_obj_t * obj, uint8_t input_type)
{
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;
    if(input_type == 0) {
        lv_btnmatrix_set_map(obj, en_kb_map[keyboard->mode]);
        lv_btnmatrix_set_ctrl_map(obj, en_kb_ctrl[keyboard->mode]);
    }
    else {
        lv_btnmatrix_set_map(obj, zh_kb_map[keyboard->mode]);
        lv_btnmatrix_set_ctrl_map(obj, zh_kb_ctrl[keyboard->mode]);
    }
}

/**
 * Update the control map for the current mode
 * @param obj pointer to a keyboard object
 */
static void lv_zh_keyboard_update_ctrl_map(lv_obj_t * obj, uint8_t input_type)
{
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;

    if(keyboard->popovers) {
        /*Apply the current control map (already includes LV_BTNMATRIX_CTRL_POPOVER flags)*/
        if(input_type == 0) {
            lv_btnmatrix_set_ctrl_map(obj, en_kb_ctrl[keyboard->mode]);
        }
        else {
            lv_btnmatrix_set_ctrl_map(obj, zh_kb_ctrl[keyboard->mode]);
        }
    }
    else {
        /*Make a copy of the current control map*/
        lv_btnmatrix_t * btnm = (lv_btnmatrix_t *)obj;
        lv_btnmatrix_ctrl_t * ctrl_map = lv_mem_alloc(btnm->btn_cnt * sizeof(lv_btnmatrix_ctrl_t));
        lv_memcpy(ctrl_map, en_kb_ctrl[keyboard->mode], sizeof(lv_btnmatrix_ctrl_t) * btnm->btn_cnt);

        /*Remove all LV_BTNMATRIX_CTRL_POPOVER flags*/
        for(uint16_t i = 0; i < btnm->btn_cnt; i++) {
            ctrl_map[i] &= (~LV_BTNMATRIX_CTRL_POPOVER);
        }

        /*Apply new control map and clean up*/
        lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
        lv_mem_free(ctrl_map);
    }
}

static void lv_zh_keyboard_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_zh_keyboard_t * keyboard = (lv_zh_keyboard_t *)obj;
    keyboard->ta = NULL;
    /* when the screen deleted will set the zh_input_obj value to NULL*/
    zh_input_obj = NULL;
}

#endif /*LV_USE_ZH_KEYBOARD*/
