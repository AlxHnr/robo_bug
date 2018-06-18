#ifndef TILE_H
#define TILE_H

#include <SDL.h>
#include <SDL_image.h>

#include <calc.h>
#include <lib.h>

#include <direction.h>
#include <graphic_setting.h>
#include <tile_setting.h>

void draw_layer(layer object, SDL_Surface *tile_set, SDL_Surface *dest_surface, SDL_Rect *camera, SDL_Rect *movement);
void layer_colision(character *object, layer map_object, SDL_Rect *camera, SDL_Rect *movement);

#endif