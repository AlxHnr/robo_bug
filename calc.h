#ifndef CALC_H
#define CALC_H

#include <SDL.h>
#include <lib.h>
#include <direction.h>
#include <graphic_setting.h>

char get_dir_to(const SDL_Rect *object_1, const SDL_Rect *object_2);
char split_dir_x(const char direction);
char split_dir_y(const char direction);
int collision(const SDL_Rect *object_1, const SDL_Rect *object_2);
int get_pos_x(const SDL_Rect *object_dest, const SDL_Rect *camera, const SDL_Rect *movement);
int get_pos_y(const SDL_Rect *object_dest, const SDL_Rect *camera, const SDL_Rect *movement);
SDL_Rect get_dest(character *player, SDL_Rect *camera_1, SDL_Rect *player_1_movement, SDL_Rect *camera_2, SDL_Rect *player_2_movement);

#endif