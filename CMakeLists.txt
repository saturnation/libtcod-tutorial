cmake_minimum_required(VERSION 3.7)
project(libtcod-tutorial)

set(CMAKE_C_STANDARD 11)

include_directories(lib/libtcod-1.9.0-x86_64-msvc/include)

#https://stackoverflow.com/questions/8774593/cmake-link-to-external-library/41909627#41909627
link_directories(lib/libtcod-1.9.0-x86_64-msvc/)
find_library( LIBTCOD_LIB libtcod )

set(SOURCE_FILES src/main.c
        src/input_handlers.c
        src/input_handlers.h
        src/entity.c
        src/entity.h
        src/render_functions.c
        src/render_functions.h
        src/map/tile.c
        src/map/tile.h
        src/map/game_map.c
        src/map/game_map.h
        src/map/rectangle.c
        src/map/rectangle.h
        src/map/fov.c
        src/map/fov.h
        src/data/list.h src/data/enums.h)

add_executable(libtcod-tutorial ${SOURCE_FILES})
target_link_libraries(libtcod-tutorial libtcod)
