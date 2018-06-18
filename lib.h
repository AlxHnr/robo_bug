#ifndef LIB_H
#define LIB_H

#include <SDL.h>
#include <tile_setting.h>

typedef struct{
  //file specific data
  SDL_Surface* image;
  SDL_Rect source;
  SDL_Rect dest;
  
  //graphic specific data
  unsigned char frame;
  unsigned char frame_max;
  unsigned char rows;
  
  //game specific data
  char direction;
  
  //character specific data
  short health_max;
  short health;
  
  short mana_max;
  short mana;
  
  short p_attack;
  short p_defence;
  
  short m_attack;
  short m_defence;
  
  unsigned char speed;
  
  //skill specific data
  char skill_trigger;
  Uint32 skill_1_timer;
  Uint32 skill_2_timer;
  Uint32 skill_3_timer;
  Uint32 skill_4_timer;
}character;

typedef char layer[max_tile_y][max_tile_x];

#endif