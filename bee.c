#include <bee.h>

SDL_Rect fireball_dest;
char fireball_direction;

character *init_bee()
{
  character *object = NULL;
  if((object = malloc(sizeof(character))) != NULL && (object->image = load_image(bee_image)) != NULL)
  {
    //graphical stuff
    object->frame = 1;
    object->frame_max = bee_frames;
    object->rows = bee_directions;
    
    object->source.x = 0;
    object->source.y = 0;
    object->source.w = object->image->w/object->frame_max;
    object->source.h = object->image->h/object->rows;
    
    //copy source into dest
    object->dest = object->source;
    
    object->direction = 0;
    
    //character attribute
    object->health_max = bee_health_max;
    object->health = bee_health_max;
    
    object->mana_max = bee_mana_max;
    object->mana = bee_mana_max;
    
    object->p_attack = bee_p_defence;
    object->p_defence = bee_p_defence;
    
    object->m_attack = bee_m_defence;
    object->m_defence = bee_m_defence;
    
    object->speed = bee_speed;
    
    //skill attribute
    object->skill_1_timer = 0;
    object->skill_2_timer = 0;
    object->skill_3_timer = 0;
    object->skill_4_timer = 0;
    
    return object;
  }
  return NULL;
}
void bee_call(SDL_Surface *screen, character *player_1, SDL_Rect *camera_1, SDL_Rect *player_1_movement, character *player_2, SDL_Rect *camera_2, SDL_Rect *player_2_movement)
{
  if(SDL_GetTicks() - player_1->skill_1_timer < 3000)
  {
    move_object(&fireball_dest, fireball_direction, 15);
    draw_bar(bar_green, 20, fireball_dest.x, fireball_dest.y, screen);
  }
  else if(player_1->skill_trigger == 1 && player_1->mana >= 5)
  {
    player_1->skill_1_timer = SDL_GetTicks();
    player_1->mana -= 5;
    fireball_direction = get_direction(player_1);
    fireball_dest = player_1->dest;
    draw_bar(bar_green, 20, fireball_dest.x, fireball_dest.y, screen);
  }
}