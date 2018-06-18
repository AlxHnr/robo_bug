#ifndef FOREST_H
#define FOREST_H

#include <all_header.h>

#define forest_w 46
#define forest_h 46

int init_forest(character *player_1, character *player_2, SDL_Rect *camera_1, SDL_Rect *camera_2);
void draw_lower_forest(SDL_Surface *screen, SDL_Rect *camera, SDL_Rect *player_movement);
void draw_upper_forest(SDL_Surface *screen, SDL_Rect *camera, SDL_Rect *player_movement);
void collision_forest(character *player, SDL_Rect *camera, SDL_Rect *player_movement);
void free_forest();

#endif