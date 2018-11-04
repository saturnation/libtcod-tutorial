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
#ifndef LIBTCOD_SDL2_GL2_RAII_H_
#define LIBTCOD_SDL2_GL2_RAII_H_

#include <cstdint>
#include <string>
#include <utility>

namespace tcod {
namespace sdl2 {
class GLShader {
 public:
  GLShader() = delete;
  explicit GLShader(int shader_type, const std::string& source);
  GLShader(const GLShader&) = delete;
  GLShader& operator=(const GLShader&) = delete;
  GLShader(GLShader&& rhs) noexcept
  : shader_(rhs.shader_)
  {
    rhs.shader_ = 0;
  }
  GLShader& operator=(GLShader&& rhs) noexcept
  {
    std::swap(shader_, rhs.shader_);
    return *this;
  }
  ~GLShader() noexcept;
  uint32_t get() const noexcept
  {
    return shader_;
  }
  std::string get_log() const;
  int get_variable(int name) const;
 private:
  void verify_shader();
  uint32_t shader_{0};
};
class GLProgram {
 public:
  GLProgram();
  GLProgram(const std::string& vshader, const std::string& fshader);
  GLProgram(const GLProgram&) = delete;
  GLProgram& operator=(const GLProgram&) = delete;
  GLProgram(GLProgram&& rhs) noexcept
  : program_(rhs.program_)
  {
    rhs.program_ = 0;
  }
  GLProgram& operator=(GLProgram&& rhs) noexcept
  {
    std::swap(program_, rhs.program_);
    return *this;
  }
  ~GLProgram() noexcept;
  uint32_t get() const noexcept
  {
    return program_;
  }
  void attach(const GLShader& shader);
  std::string get_log() const;
  void link();
  void validate();
  void use() const;
  int get_attribute(const std::string& name) const;
  int get_variable(int name) const;
  int get_uniform(const std::string& name) const;
 private:
  uint32_t program_{0};
};
class GLBuffer {
 public:
  GLBuffer();
  template <typename T>
  GLBuffer(int target, const T& data, int usage)
  : GLBuffer()
  {
    allocate(target, data, usage);
  }
  GLBuffer(const GLBuffer&) = delete;
  GLBuffer& operator=(const GLBuffer&) = delete;
  GLBuffer(GLBuffer&& rhs) noexcept
  : buffer_(rhs.buffer_)
  {
    rhs.buffer_ = 0;
  }
  GLBuffer& operator=(GLBuffer&& rhs) noexcept
  {
    std::swap(buffer_, rhs.buffer_);
    return *this;
  }
  ~GLBuffer() noexcept;
  uint32_t get() const noexcept
  {
    return buffer_;
  }
  void allocate(int target, int size, const void* data, int usage);
  template <typename T>
  void allocate(int target, const T& data, int usage)
  {
    allocate(target, sizeof(data[0]) * data.size(), data.data(), usage);
  }
  void bind();
 private:
  uint32_t buffer_{0};
  int target_{-1};
};
class GLTexture {
 public:
  GLTexture();
  GLTexture(const GLTexture&) = delete;
  GLTexture& operator=(const GLTexture&) = delete;
  GLTexture(GLTexture&& rhs) noexcept
  : texture_(rhs.texture_)
  {
    rhs.texture_ = 0;
  }
  GLTexture& operator=(GLTexture&& rhs) noexcept
  {
    std::swap(texture_, rhs.texture_);
    return *this;
  }
  ~GLTexture() noexcept;
  uint32_t get() const noexcept
  {
    return texture_;
  }
  void bind();
 private:
  uint32_t texture_{0};
};

} // namespace sdl2
} // namespace tcod
#endif // LIBTCOD_SDL2_GL2_RAII_H_
