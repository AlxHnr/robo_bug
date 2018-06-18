#ifndef BEE_H
#define BEE_H

#include <all_header.h>

#define bee_image "graphic/char.png"

#define bee_frames 4
#define bee_directions 8

#define bee_health_max 170
#define bee_mana_max 95

#define bee_p_attack 30
#define bee_m_attack 35

#define bee_p_defence 20
#define bee_m_defence 10

#define bee_speed 7

character *init_bee();
void bee_call(SDL_Surface *screen, character *player_1, SDL_Rect *camera_1, SDL_Rect *player_1_movement, character *player_2, SDL_Rect *camera_2, SDL_Rect *player_2_movement);

#endif