#include <libtcod.h>
#include <malloc.h>
#include <stdio.h>
#include "input_handlers.h"
#include "entity.h"
#include "render_functions.h"
#include "map/game_map.h"
#include "map/fov.h"
#include "data/enums.h"
#include "data/list.h"

int main() {
    int screen_width = 80;
    int screen_height = 50;
    int map_width = 80;
    int map_height = 45;
    int room_max_size = 10;
    int room_min_size = 6;
    int max_rooms = 30;
    int fov_algorithm = 0;
    bool fov_light_walls = true;
    int fov_radius = 10;
    int max_monsters_per_room = 3;

    TCOD_color_t colors[4];
    colors[DARK_WALL] = TCOD_color_RGB(0, 0, 100);
    colors[DARK_GROUND] = TCOD_color_RGB(50, 50, 150);
    colors[LIGHT_WALL] = TCOD_color_RGB(130, 110, 50);
    colors[LIGHT_GROUND] = TCOD_color_RGB(200, 180, 50);

    struct entity_list *entities_list_head;
    struct entity *player;
    entities_list_head = (struct entity_list *) malloc(sizeof(struct entity_list));
    entities_list_head->next = NULL;
    struct fighter *fighter = create_fighter(30, 2, 5);
    entities_list_head->data = create_entity(screen_width / 2, screen_height / 2, '@', TCOD_white, "Player", true, fighter, NULL);;
    player = entities_list_head->data;
    TCOD_console_set_custom_font("terminal16x16_gs_ro.png",
                                 TCOD_FONT_TYPE_GRAYSCALE | TCOD_FONT_LAYOUT_ASCII_INROW,
                                 16,
                                 16);
    TCOD_console_init_root(screen_width, screen_height, "libtcod Tutorial", false, TCOD_RENDERER_SDL2);
    TCOD_console_t con = TCOD_console_new(screen_width, screen_height);

    struct game_map *map = create_game_map(map_width, map_height);
    make_map(map, max_rooms, room_min_size, room_max_size, map_width, map_height, player, entities_list_head,
             max_monsters_per_room);

    TCOD_key_t *key;
    key = malloc(sizeof(TCOD_key_t));
    TCOD_mouse_t *mouse;
    mouse = malloc(sizeof(TCOD_mouse_t));
    struct action *action;
    action = malloc(sizeof(struct action));

    enum game_states game_state = PLAYERS_TURN;

    bool fov_recompute = true;
    TCOD_Map *fov_map = initialize_fov(map);

    while (!TCOD_console_is_window_closed()) {
        TCOD_sys_check_for_event(TCOD_EVENT_KEY_PRESS, key, mouse);

        if (fov_recompute) {
            recompute_fov(fov_map, player->x, player->y, fov_radius, fov_light_walls, fov_algorithm);
        }
        render_all(con, entities_list_head, map, fov_map, fov_recompute, screen_width, screen_height, colors);
        fov_recompute = false;

        TCOD_console_flush();

        clear_all(con, entities_list_head);

        handle_keys(key, action);
        if (action->type != NO_ACTION) {

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
            if (action->type == MOVE && game_state == PLAYERS_TURN) {
                int dx = action->data.move.dx;
                int dy = action->data.move.dy;
                int destination_x = player->x + dx;
                int destination_y = player->y + dy;
                if (!is_blocked(map, destination_x, destination_y)) {
                    struct entity *target = get_blocking_entities_at_location(entities_list_head, destination_x,
                                                                       destination_y);
                    if (target) {
                        attack(player, target);
                    } else {
                        move(player, dx, dy);
                        fov_recompute = true;
                    }
                }
                game_state = ENEMY_TURN;
            } else if (action->type == EXIT) {
                return true;
            } else if (action->type == FULLSCREEN) {
                TCOD_console_set_fullscreen(!TCOD_console_is_fullscreen());
            }
#pragma clang diagnostic pop

            if (game_state == ENEMY_TURN) {
                struct entity_list *curr = entities_list_head;
                while (curr != NULL) {
                    if (curr->data->ai_action) {
                        (*curr->data->ai_action)(curr->data, player, fov_map, map, entities_list_head);
                    }
                    curr = curr->next;
                }
                game_state = PLAYERS_TURN;
            }
        }
    }
    free(key);
    free(mouse);
}