#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <all_header.h>

char get_row_from_dir(const character* object);
char get_direction(character *object);
void set_direction(character *object);
void animate(character *object);
void move_char(character *object);
void move_object(SDL_Rect *object, const char direction, const char speed);
void move_camera(SDL_Rect *camera, character *object);
void draw_bar(const char bar_nr, const unsigned short bar_lenght, const short x, const short y, SDL_Surface *screen);
void draw_all_bar(character *object, SDL_Rect *object_movement, SDL_Surface *screen);

#endif