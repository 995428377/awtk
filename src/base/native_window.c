﻿/**
 * File:   native_window.h
 * Author: AWTK Develop Team
 * Brief:  native window
 *
 * Copyright (c) 2019 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-07-21 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "base/native_window.h"

ret_t native_window_move(native_window_t* win, xy_t x, xy_t y, bool_t force) {
  return_value_if_fail(win != NULL && win->vt != NULL, RET_BAD_PARAMS);

  if (win->vt->move != NULL) {
    if (force || !(win->shared)) {
      return win->vt->move(win, x, y);
    }
  }

  return RET_OK;
}

ret_t native_window_resize(native_window_t* win, wh_t w, wh_t h, bool_t force) {
  return_value_if_fail(win != NULL && win->vt != NULL, RET_BAD_PARAMS);

  if (win->vt->resize != NULL) {
    if (force || !(win->shared)) {
      return win->vt->resize(win, w, h);
    }
  }

  return RET_OK;
}

canvas_t* native_window_get_canvas(native_window_t* win) {
  return_value_if_fail(win != NULL && win->vt != NULL, NULL);

  if (win->vt->get_canvas != NULL) {
    return win->vt->get_canvas(win);
  }

  return NULL;
}