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
#ifndef LIBTCOD_ENGINE_GLOBALS_H_
#define LIBTCOD_ENGINE_GLOBALS_H_

#ifdef __cplusplus
#include <memory>
#endif // __cplusplus

#include "backend.h"
#include "display.h"
#include "../tileset/tileset.h"
#include "../tileset/tilesheet.h"

#ifdef __cplusplus
namespace tcod {
namespace engine {
using tileset::Tileset;
using tileset::Tilesheet;
/**
 *  Replace the active backend with a new instance, can be nullptr.
 */
void set_backend(std::shared_ptr<Backend> backend);
/**
 *  Return a shared pointer to the active backend.  Might be nullptr.
 */
std::shared_ptr<Backend> get_backend();
/**
 *  Replace the active display with a new instance, can be nullptr.
 */
void set_display(std::shared_ptr<Display> display);
/**
 *  Return a shared pointer to the active display.  Might be nullptr.
 */
std::shared_ptr<Display> get_display();

void set_tileset(std::shared_ptr<Tileset> tileset);
auto get_tileset() -> std::shared_ptr<Tileset>;
void set_tilesheet(std::shared_ptr<Tilesheet> sheet);
auto get_tilesheet() -> std::shared_ptr<Tilesheet>;
} // namespace sdl2
} // namespace tcod
#endif // __cplusplus
#endif // LIBTCOD_ENGINE_GLOBALS_H_


