#include <all_header.h>

#define map_w 20
#define map_h 20

SDL_Surface *map_tile = NULL;

layer map_layer = {
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",

int init_forest(character *player_1, character *player_2, SDL_Rect *camera_1, SDL_Rect *camera_2)
{
  if((map_tile = load_image("graphic/map_tile.png")) == NULL)
  {
    return -1;
  }
  
  camera_1->x = x_start_position;
  camera_1->y = y_start_position;
  
  camera_2->x = x_start_position;
  camera_2->y = y_start_position;
  
  return 0;
}
void draw_map(SDL_Surface *screen, SDL_Rect *camera, SDL_Rect *player_movement)
{
  draw_layer(map_layer, map_tile, screen, camera, player_movement);
}
void collision_map(character *player, SDL_Rect *camera, SDL_Rect *player_movement)
{
  layer_colision(player, map_collision, camera, player_movement);
}