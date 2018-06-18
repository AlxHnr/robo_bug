#include <calc.h>

char get_dir_to(const SDL_Rect *object_1, const SDL_Rect *object_2)
{
  //get direction from object_1 to object_2
  char direction = dir_none;
  
  if(object_1->y + (object_1->h/2) > object_2->y + object_2->h)
    direction += dir_up;
  else if(object_1->y + object_1->h < object_2->y + (object_2->h/2))
    direction += dir_down;
  
  if(object_1->x + (object_1->w/2) > object_2->x + object_2->w)
    direction += dir_left;
  else if(object_1->x + object_1->w < object_2->x + (object_2->w/2))
    direction += dir_right;
  
  return direction;
}
char split_dir_x(const char direction)
{
  char direction_x = 0;
  
  switch(direction)
  {
    case dir_left:
      direction_x = dir_left;
      break;
    case dir_right:
      direction_x = dir_right;
      break;
    case dir_down_left:
      direction_x = dir_left;
      break;
    case dir_down_right:
      direction_x = dir_right;
      break;
    case dir_up_left:
      direction_x = dir_left;
      break;
    case dir_up_right:
      direction_x = dir_right;
      break;
  }
  
  return direction_x;
}
char split_dir_y(const char direction)
{
  char direction_y = 0;
  
  switch(direction)
  {
    case dir_down:
      direction_y = dir_down;
      break;
    case dir_up:
      direction_y = dir_up;
      break;
    case dir_down_left:
      direction_y = dir_down;
      break;
    case dir_down_right:
      direction_y = dir_down;
      break;
    case dir_up_left:
      direction_y = dir_up;
      break;
    case dir_up_right:
      direction_y = dir_up;
      break;
  }
  
  return direction_y;
}
int collision(const SDL_Rect *object_1, const SDL_Rect *object_2)
{
  if(object_1->x + object_1->w >= object_2->x &&
  object_1->x <= object_2->x + object_2->w &&
  object_1->y + object_1->h >= object_2->y &&
  object_1->y <= object_2->y + object_2->h)
    return 1;
    
  return 0;
}
int get_pos_x(const SDL_Rect *object_dest, const SDL_Rect *camera, const SDL_Rect *movement)
{
  return (camera->x + object_dest->x) - movement->x;
}
int get_pos_y(const SDL_Rect *object_dest, const SDL_Rect *camera, const SDL_Rect *movement)
{
  return (camera->y + object_dest->y) - movement->y;
}
SDL_Rect get_dest(character *player, SDL_Rect *camera_1, SDL_Rect *player_1_movement, SDL_Rect *camera_2, SDL_Rect *player_2_movement)
{
  SDL_Rect dest;
  dest.x = get_pos_x(&player->dest, camera_1, player_1_movement);
  dest.y = get_pos_y(&player->dest, camera_1, player_1_movement);
  dest.w = player->dest.w;
  dest.h = player->dest.h;
  
  if(collision(&dest, camera_2) != 0)
  {
    dest.x -= camera_2->x;
    dest.y -= camera_2->y;
    
    dest.x += player_2_movement->x;
    dest.y += player_2_movement->y;
  }
  else
  {
    dest.x = screen_w;
    dest.y = screen_h;
  }
  return dest;
}