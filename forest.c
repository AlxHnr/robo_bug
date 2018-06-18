#include <forest.h>

SDL_Surface *forest_tile = NULL;

layer forest_ground = {
"______________________________________________",
"______________________________________________",
"______________________________________________",
"______________________________________________",
"______________________________________________",
"______________________________________________",
"_______`ffffffffffffffffffffffffffffffc_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAd_______",
"_______bgggggggggggggggggggggggggggggge_______",
"______________________________________________",
"______________________________________________",
"______________________________________________",
"______________________________________________",
"______________________________________________",
"______________________________________________"};

layer forest_upper = {
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                             LQV[             ",
"                             MRW\\             ",
"                             NSX]             ",
"                  D          OTY              ",
"                        K    PUZ              ",
"          LQV[      EG                        ",
"          MRW\\      FH              BC         ",
"          NSX]                                ",
"          OTY       LQV[                      ",
"          PUZ       MRW\\                      ",
"                    NSX]                      ",
"                    OTY                       ",
"                    PUZ             I         ",
"               D                              ",
"                                 LQV[         ",
"           LQV[                  MRW\\         ",
"           MRW\\                  NSX]         ",
"           NSX]       K          OTY          ",
"           OTY                   PUZ          ",
"           PUZ               D                ",
"          LQV[      EG                        ",
"          MRW\\      FH              BC         ",
"          NSX]                                ",
"          OTY       LQV[                      ",
"          PUZ       MRW\\                      ",
"                    NSX]                      ",
"                    OTY                       ",
"                    PUZ             I         ",
"               D                              ",
"                                 LQV[         ",
"           LQV[                  MRW\\         ",
"           MRW\\                  NSX]         ",
"           NSX]       K          OTY          ",
"           OTY                   PUZ          ",
"           PUZ               D                ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              ",
"                                              "};

layer forest_collision = {
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"11111111          1                   11111111",
"11111111                1     11      11111111",
"11111111                              11111111",
"11111111            11              1111111111",
"11111111                              11111111",
"11111111                              11111111",
"11111111   11                         11111111",
"11111111                              11111111",
"11111111                              11111111",
"11111111             11             1 11111111",
"11111111       1                      11111111",
"11111111                              11111111",
"11111111                              11111111",
"11111111                              11111111",
"11111111              1               11111111",
"11111111                          11  11111111",
"11111111    11               1        11111111",
"11111111                              11111111",
"11111111            11              1111111111",
"11111111                              11111111",
"11111111                              11111111",
"11111111   11                         11111111",
"11111111                              11111111",
"11111111                              11111111",
"11111111             11             1 11111111",
"11111111       1                      11111111",
"11111111                              11111111",
"11111111                              11111111",
"11111111                              11111111",
"11111111              1               11111111",
"11111111                          11  11111111",
"11111111    11               1        11111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111",
"1111111111111111111111111111111111111111111111"};

int init_forest(character *player_1, character *player_2, SDL_Rect *camera_1, SDL_Rect *camera_2)
{
  if((forest_tile = load_image("graphic/forest_tile.png")) == NULL)
  {
    return -1;
  }
  
  camera_1->x = 300;
  camera_1->y = 250;
  
  camera_2->x = 840;
  camera_2->y = 580;
  
  return 0;
}
void draw_lower_forest(SDL_Surface *screen, SDL_Rect *camera, SDL_Rect *player_movement)
{
  draw_layer(forest_ground, forest_tile, screen, camera, player_movement);
}
void draw_upper_forest(SDL_Surface *screen, SDL_Rect *camera, SDL_Rect *player_movement)
{
  draw_layer(forest_upper, forest_tile, screen, camera, player_movement);
}
void collision_forest(character *player, SDL_Rect *camera, SDL_Rect *player_movement)
{
  layer_colision(player, forest_collision, camera, player_movement);
}
void free_forest()
{
  free(forest_tile);
}