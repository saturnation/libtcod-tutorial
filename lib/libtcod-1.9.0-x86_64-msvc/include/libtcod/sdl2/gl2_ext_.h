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
#ifndef LIBTCOD_SDL2_GL2_EXT_H_
#define LIBTCOD_SDL2_GL2_EXT_H_
#include <stdexcept>

#include <glad/glad.h>
namespace tcod {
namespace sdl2 {
class opengl_error : public std::runtime_error {
 public:
  explicit opengl_error(const std::string& what_arg)
  : runtime_error(what_arg)
  {};
};
inline void gl_check() {
#ifndef NDEBUG
  switch(glGetError()) {
    case GL_NO_ERROR:
      return;
    case GL_INVALID_ENUM:
      throw opengl_error("GL_INVALID_ENUM");
    case GL_INVALID_VALUE:
      throw opengl_error("GL_INVALID_VALUE");
    case GL_INVALID_OPERATION:
      throw opengl_error("GL_INVALID_OPERATION");
    //case GL_INVALID_FRAMEBUFFER_OPERATION:
    //  throw opengl_error("GL_INVALID_FRAMEBUFFER_OPERATION");
    case GL_OUT_OF_MEMORY:
      throw opengl_error("GL_OUT_OF_MEMORY");
    default:
      throw opengl_error("Unknown OpenGL error.");
  }
#endif // NDEBUG
}
} // namespace sdl2
} // namespace tcod
#endif // LIBTCOD_SDL2_GL2_EXT_H_
