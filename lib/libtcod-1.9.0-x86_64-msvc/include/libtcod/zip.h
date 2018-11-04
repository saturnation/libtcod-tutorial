/* libtcod
 * Copyright © 2008-2018 Jice and the libtcod contributers.
 * All rights reserved.
 *
 * libtcod 'The Doryen library' is a cross-platform C/C++ library for roguelike
 * developers.
 * Its source code is available from:
 * https://github.com/libtcod/libtcod
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The name of copyright holder nor the names of its contributors may not
 *       be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _TCOD_ZIP_H
#define _TCOD_ZIP_H

#include "portability.h"
#include "color.h"
#include "console_types.h"
#include "image.h"

#ifdef __cplusplus
extern "C" {
#endif
struct TCOD_Zip;
typedef struct TCOD_Zip *TCOD_zip_t;

TCODLIB_API TCOD_zip_t TCOD_zip_new(void);
TCODLIB_API void TCOD_zip_delete(TCOD_zip_t zip);

/* output interface */
TCODLIB_API void TCOD_zip_put_char(TCOD_zip_t zip, char val);
TCODLIB_API void TCOD_zip_put_int(TCOD_zip_t zip, int val);
TCODLIB_API void TCOD_zip_put_float(TCOD_zip_t zip, float val);
TCODLIB_API void TCOD_zip_put_string(TCOD_zip_t zip, const char *val);
TCODLIB_API void TCOD_zip_put_color(TCOD_zip_t zip, const TCOD_color_t val);
#ifdef TCOD_IMAGE_SUPPORT
TCODLIB_API void TCOD_zip_put_image(TCOD_zip_t zip, const TCOD_image_t val);
#endif
#ifdef TCOD_CONSOLE_SUPPORT
TCODLIB_API void TCOD_zip_put_console(TCOD_zip_t zip, const TCOD_console_t val);
#endif
TCODLIB_API void TCOD_zip_put_data(TCOD_zip_t zip, int nbBytes, const void *data);
TCODLIB_API uint32_t TCOD_zip_get_current_bytes(TCOD_zip_t zip);
TCODLIB_API int TCOD_zip_save_to_file(TCOD_zip_t zip, const char *filename);

/* input interface */
TCODLIB_API int TCOD_zip_load_from_file(TCOD_zip_t zip, const char *filename);
TCODLIB_API char TCOD_zip_get_char(TCOD_zip_t zip);
TCODLIB_API int TCOD_zip_get_int(TCOD_zip_t zip);
TCODLIB_API float TCOD_zip_get_float(TCOD_zip_t zip);
TCODLIB_API const char *TCOD_zip_get_string(TCOD_zip_t zip);
TCODLIB_API TCOD_color_t TCOD_zip_get_color(TCOD_zip_t zip);
#ifdef TCOD_IMAGE_SUPPORT
TCODLIB_API TCOD_image_t TCOD_zip_get_image(TCOD_zip_t zip);
#endif
#ifdef TCOD_CONSOLE_SUPPORT
TCODLIB_API TCOD_console_t TCOD_zip_get_console(TCOD_zip_t zip);
#endif
TCODLIB_API int TCOD_zip_get_data(TCOD_zip_t zip, int nbBytes, void *data);
TCODLIB_API uint32_t TCOD_zip_get_remaining_bytes(TCOD_zip_t zip);
TCODLIB_API void TCOD_zip_skip_bytes(TCOD_zip_t zip, uint32_t nbBytes);
#ifdef __cplusplus
}
#endif
#endif
