#include <tile.h>

void draw_layer(layer object, SDL_Surface *tile_set, SDL_Surface *dest_surface, SDL_Rect *camera, SDL_Rect *movement)
{
  short counter_x = camera->x/tile_size_x;
  short counter_y = camera->y/tile_size_y;
  
  SDL_Rect temp;
  
  SDL_Rect tile_source;
  tile_source.x = 0;
  tile_source.y = 0;
  tile_source.w = tile_size_x;
  tile_source.h = tile_size_y;
  
  SDL_Rect tile_dest;
  tile_dest = tile_source;
  
  while(counter_y <= (camera->y+camera->h)/tile_size_y)
  {
    tile_dest.x = 0;
    counter_x = camera->x/tile_size_x;
    while(counter_x <= (camera->x+camera->w)/tile_size_x)
    {
      if(object[counter_y][counter_x] != ' ')
      {
        temp = tile_dest;
        
        temp.x -= camera->x%tile_size_x;
        temp.y -= camera->y%tile_size_y;
        
        temp.x += movement->x;
        temp.y += movement->y;
        
        tile_source.y = (object[counter_y][counter_x] - 65) * tile_size_y;
        SDL_BlitSurface(tile_set, &tile_source, dest_surface, &temp);
      }
      tile_dest.x += tile_size_x;
      counter_x += 1;
    }
    tile_dest.y += tile_size_y;
    counter_y += 1;
  }
}
void layer_colision(character *object, layer map_object, SDL_Rect *camera, SDL_Rect *movement)
{
  char direction_x;
  char direction_y;
  
  char object_direction_x = split_dir_x(object->direction);
  char object_direction_y = split_dir_y(object->direction);
  
  short counter_x = camera->x/tile_size_x;
  short counter_y = camera->y/tile_size_y;
  
  SDL_Rect temp;
  
  SDL_Rect tile_object;
  tile_object.y = 0;
  tile_object.w = tile_size_x;
  tile_object.h = tile_size_y;
  
  while(counter_y <= (camera->y+camera->h)/tile_size_y)
  {
    tile_object.x = 0;
    counter_x = camera->x/tile_size_x;
    while(counter_x <= (camera->x+camera->w)/tile_size_x)
    {
      temp = tile_object;
      
      temp.x -= camera->x%tile_size_x;
      temp.y -= camera->y%tile_size_y;
      
      temp.x += movement->x;
      temp.y += movement->y;
      
      if(collision(&object->dest, &temp) != 0 && map_object[counter_y][counter_x] == '1')
      {
        direction_x = split_dir_x(get_dir_to(&object->dest, &temp));
        direction_y = split_dir_y(get_dir_to(&object->dest, &temp));
        
        if(direction_y == dir_none && object_direction_x == direction_x)
        {
          if(direction_x == dir_left)
          {
            object->dest.x = temp.x + temp.w;
          }
          if(direction_x == dir_right)
          {
            object->dest.x = temp.x - object->dest.w;
          }
          object_direction_x = dir_none;
        }
        if(direction_x == dir_none && object_direction_y == direction_y)
        {
          if(direction_y == dir_up)
          {
            object->dest.y = temp.y + temp.h;
          }
          if(direction_y == dir_down)
          {
            object->dest.y = temp.y - object->dest.h;
          }
          object_direction_y = dir_none;
        }
        
        if(direction_x + direction_y == dir_up_left && map_object[counter_y][counter_x + 1] != '1' && map_object[counter_y + 1][counter_x] != '1')
        {
          if(object_direction_y == dir_up && object->dest.x < temp.x + temp.h)
          {
            object_direction_y = dir_none;
          }
          if(object_direction_x == dir_left && object->dest.y < temp.y + temp.h)
          {
            object_direction_x = dir_none;
          }
        }
        else if(direction_x + direction_y == dir_down_left && map_object[counter_y][counter_x + 1] != '1' && map_object[counter_y - 1][counter_x] != '1')
        {
          if(object_direction_y == dir_down && object->dest.x < temp.x + temp.w)
          {
            object_direction_y = dir_none;
          }
          if(object_direction_x == dir_left && object->dest.y + object->dest.h > temp.y)
          {
            object_direction_x = dir_none;
          }
        }
        else if(direction_x + direction_y == dir_up_right && map_object[counter_y][counter_x - 1] != '1' && map_object[counter_y + 1][counter_x] != '1')
        {
          if(object_direction_y == dir_up && object->dest.x + object->dest.w > temp.x)
          {
            object_direction_y = dir_none;
          }
          if(object_direction_x == dir_right && object->dest.y < temp.y + temp.h)
          {
            object_direction_x = dir_none;
          }
        }
        else if(direction_x + direction_y == dir_down_right && map_object[counter_y][counter_x - 1] != '1' && map_object[counter_y - 1][counter_x] != '1')
        {
          if(object_direction_y == dir_down && object->dest.x + object->dest.w > temp.x)
          {
            object_direction_y = dir_none;
          }
          if(object_direction_x == dir_right && object->dest.y + object->dest.h > temp.y)
          {
            object_direction_x = dir_none;
          }
        }
      }
      tile_object.x += tile_size_x;
      counter_x += 1;
    }
    tile_object.y += tile_size_y;
    counter_y += 1;
  }
  object->direction = object_direction_x + object_direction_y;
}