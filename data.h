#ifndef DATA_H
#define DATA_H

#include <SDL.h>
#include <SDL_image.h>
#include <lib.h>

SDL_Surface *load_image(const char *image_path);
void FreeCharacter(character* object);

#endif