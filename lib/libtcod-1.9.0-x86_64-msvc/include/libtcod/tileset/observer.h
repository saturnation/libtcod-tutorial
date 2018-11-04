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
#ifndef LIBTCOD_TILESET_OBSERVER_H_
#define LIBTCOD_TILESET_OBSERVER_H_
#include "../portability.h"

#ifdef __cplusplus
#include <algorithm>
#include <memory>
#include <utility>
#include <vector>
#endif

#include "tile.h"
#include "tileset.h"
#ifdef __cplusplus
namespace tcod {
namespace tileset {
class Tileset;
class TilesetObserver;
typedef std::vector<std::pair<int, Tile&>> IdTileRefPairVector_;
class TilesetObserver {
 public:
  TilesetObserver() = default;

  TilesetObserver(const std::shared_ptr<Tileset>& subject)
  {
    if (!subject) {
      throw std::invalid_argument("tileset cannot be nullptr.");
    }
    observe(subject);
  }

  TilesetObserver(TilesetObserver&& rhs)
  : TilesetObserver(rhs.tileset_)
  {}
  TilesetObserver& operator=(TilesetObserver&& rhs)
  {
    if (this != &rhs) {
      observe(rhs.tileset_);
    }
    return *this;
  }
  TilesetObserver(const TilesetObserver& rhs)
  : TilesetObserver(rhs.tileset_)
  {}
  TilesetObserver& operator=(const TilesetObserver& rhs)
  {
    if (this != &rhs) {
      observe(rhs.tileset_);
    }
    return *this;
  }
  virtual ~TilesetObserver() {
    unobserve();
  }
  /**
   *  Called on Tileset state changes.
   *
   *  `changes` is a vector of index,Tile pairs.
   *
   *  The Tileset may have been resized.
   */
  virtual void on_tileset_changed(
      const std::vector<std::pair<int, Tile&>> &changes)
  {}
  std::shared_ptr<Tileset>& get_tileset()
  {
    return tileset_;
  }
 protected:
  std::shared_ptr<Tileset> tileset_;
 private:
  void observe(const std::shared_ptr<Tileset>& subject)
  {
    unobserve();
    tileset_ = subject;
    subject->observers_.emplace_back(this);
  }
  void unobserve() {
    if (!tileset_) { return; }
    auto& observers = tileset_->observers_;
    observers.erase(std::find(observers.begin(), observers.end(), this));
    tileset_ = nullptr;
  }
};
} // namespace tileset
} // namespace tcod
#endif /* __cplusplus */
#endif /* LIBTCOD_TILESET_OBSERVER_H_ */
