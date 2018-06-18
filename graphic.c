#include <graphic.h>

SDL_Surface *bar_image = NULL;

char get_row_from_dir(const character *object)
{
  char row_direction = 0;
  switch(object->direction)
  {
    case dir_left:
      row_direction = 1;
      break;
    case dir_right:
      row_direction = 2;
      break;
    case dir_up:
      row_direction = 3;
      break;
    case dir_down_left:
      row_direction = 4;
      break;
    case dir_down_right:
      row_direction = 5;
      break;
    case dir_up_left:
      row_direction = 6;
      break;
    case dir_up_right:
      row_direction = 7;
      break;
  }
  if(row_direction >= object->rows)
    row_direction = 0;
  
  return row_direction;
}
char get_direction(character *object)
{
  if(object->source.y == 0)
  {
    return dir_down;
  }
  else if(object->source.y == object->dest.h)
  {
    return dir_left;
  }
  else if(object->source.y == object->dest.h * 2)
  {
    return dir_right;
  }
  else if(object->source.y == object->dest.h * 3)
  {
    return dir_up;
  }
  else if(object->source.y == object->dest.h * 4)
  {
    return dir_down_left;
  }
  else if(object->source.y == object->dest.h * 5)
  {
    return dir_down_right;
  }
  else if(object->source.y == object->dest.h * 6)
  {
    return dir_up_left;
  }
  else if(object->source.y == object->dest.h * 7)
  {
    return dir_up_right;
  }
  else
  {
    return dir_none;
  }
}
void set_direction(character *object)
{
  object->source.y = object->source.h * get_row_from_dir(object);
}
void animate(character *object)
{
  if(object->frame >= object->frame_max)
  {
    object->frame = 0;
  }
  object->source.x = object->frame*(object->source.w);
  object->frame++;
}
void move_char(character *object)
{
  char direction_x = split_dir_x(object->direction);
  char direction_y = split_dir_y(object->direction);
  
  unsigned char temp_speed = object->speed;
  
  if(object->direction != dir_up && object->direction != dir_down && object->direction != dir_left && object->direction != dir_right)
  {
    temp_speed = temp_speed/4 * 5;
  }
  if(temp_speed <= 0)
  {
    temp_speed = object->speed;
  }
  
  if(direction_y == dir_up)
    object->dest.y -= temp_speed;
  else if(direction_y == dir_down)
    object->dest.y += temp_speed;
  
  if(direction_x == dir_left)
    object->dest.x -= temp_speed;
  else if(direction_x == dir_right)
    object->dest.x += temp_speed;
}
void move_object(SDL_Rect *object, const char direction, const char speed)
{
  char direction_x = split_dir_x(direction);
  char direction_y = split_dir_y(direction);
  
  unsigned char temp_speed = speed;
  
  if(direction != dir_up && direction != dir_down && direction != dir_left && direction != dir_right)
  {
    temp_speed = temp_speed/4 * 5;
  }
  if(temp_speed <= 0)
  {
    temp_speed = speed;
  }
  
  if(direction_y == dir_up)
    object->y -= temp_speed;
  else if(direction_y == dir_down)
    object->y += temp_speed;
  
  if(direction_x == dir_left)
    object->x -= temp_speed;
  else if(direction_x == dir_right)
    object->x += temp_speed;
}
void move_camera(SDL_Rect *camera, character *object)
{
  char direction_x = split_dir_x(object->direction);
  char direction_y = split_dir_y(object->direction);
  
  unsigned char temp_speed = object->speed;
  
  if(object->direction != dir_up && object->direction != dir_down && object->direction != dir_left && object->direction != dir_right)
  {
    temp_speed = temp_speed/4 * 5;
  }
  if(temp_speed <= 0)
  {
    temp_speed = object->speed;
  }
  
  if(direction_y == dir_up)
    camera->y -= temp_speed;
  else if(direction_y == dir_down)
    camera->y += temp_speed;
  
  if(direction_x == dir_left)
    camera->x -= temp_speed;
  else if(direction_x == dir_right)
    camera->x += temp_speed;
}

void draw_bar(const char bar_nr, const unsigned short bar_lenght, const short x, const short y, SDL_Surface *screen)
{
  if(bar_image == NULL)
  {
    bar_image = load_image(bar_path);
  }
  SDL_Rect bar_source;
  bar_source.x = bar_nr;
  bar_source.y = 0;
  bar_source.w = bar_w;
  bar_source.h = bar_h;
  
  SDL_Rect bar_dest = bar_source;
  bar_dest.x = x;
  bar_dest.y = y;
  
  while(bar_dest.x - x < bar_lenght)
  {
    SDL_BlitSurface(bar_image, &bar_source, screen, &bar_dest);
    bar_dest.x++;
  }
}
void draw_all_bar(character *object, SDL_Rect *object_movement, SDL_Surface *screen)
{
  //draw health
  draw_bar(bar_black, object->health_max, object_movement->x, 0, screen);
  if(object->health <= object->health_max / 3)
  {
    draw_bar(bar_red, object->health, object_movement->x, 0, screen);
  }
  else if(object->health <= object->health_max / 2)
  {
    draw_bar(bar_yellow, object->health, object_movement->x, 0, screen);
  }
  else
  {
    draw_bar(bar_green, object->health, object_movement->x, 0, screen);
  }
  
  //draw mana
  draw_bar(bar_black, object->mana_max, object_movement->x, bar_h, screen);
  if(object->mana <= object->mana_max / 3)
  {
    draw_bar(bar_yellow, object->mana, object_movement->x, bar_h, screen);
  }
  else
  {
    draw_bar(bar_blue, object->mana, object_movement->x, bar_h, screen);
  }
}