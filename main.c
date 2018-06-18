#include <SDL.h>
#include <SDL_image.h>

#include <all_header.h>

#include <forest.h>

#include <bee.h>

#ifdef __WIN32__
  int WinMain(int argc, char *argv[])
#else
  int main(int argc, char *argv[])
#endif
{
  //variables
  SDL_Surface *screen = NULL;
  SDL_Event user_input;
  
  //programm and input variables
  char program_run = 1;
  char key_button[323] = {0};
  
  //frame_rate variables
  Uint32 frame_timestop;
  Uint32 frame_stop_rate = frame_calc_rate;
  Uint32 frame_delay = 0;
  
  //map variables
  int (*init_map)();
  void (*draw_lower_map)();
  void (*draw_upper_map)();
  void (*collision_map)();
  void (*free_map)();
  
  //player_1 variables
  character *player_1;
  SDL_Rect camera_1;
  SDL_Rect player_1_temp;
  SDL_Rect player_1_movement;
  character* (*init_player_1)();
  void (*player_1_call)();
  
  //player_2 variables
  character *player_2;
  SDL_Rect camera_2;
  SDL_Rect player_2_temp;
  SDL_Rect player_2_movement;
  character* (*init_player_2)();
  void (*player_2_call)();
  
  //black rect to split screen
  SDL_Rect box;
  box.x = screen_w/2 - tile_size_x/2;
  box.y = 0;
  box.w = tile_size_x;
  box.h = screen_h;
  
  //init game settings
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    exit(-1);
  if((screen = SDL_SetVideoMode(screen_w, screen_h, bit_depth, screen_mode)) == NULL)
    exit(-1);
  atexit(SDL_Quit);
  
  SDL_ShowCursor(show_mouse);
  SDL_WM_SetCaption(window_title, window_icon);
  
  //init player_1
  init_player_1 = &init_bee;
  player_1_call = &bee_call;
  
  if((player_1 = init_player_1()) == NULL)
    exit(-1);
  
  player_1_temp = player_1->dest;
  
  camera_1.w = screen_w/2;
  camera_1.h = screen_h;
  
  player_1_movement.x = 0;
  player_1_movement.y = 0;
  
  player_1->dest.x = screen_w/4 - player_1->dest.w/2;
  player_1->dest.y = screen_h/2 - player_1->dest.h/2;
  
  //init player_2
  init_player_2 = &init_bee;
  player_2_call = &bee_call;
  
  if((player_2 = init_player_2()) == NULL)
    exit(-1);
  player_2_temp = player_2->dest;
  
  camera_2.w = screen_w/2;
  camera_2.h = screen_h;
  
  player_2_movement.x = screen_w/2 + tile_size_x/2;
  player_2_movement.y = 0;
  
  player_2->dest.x = screen_w/4 * 3 - player_2->dest.w/2;
  player_2->dest.y = screen_h/2 - player_2->dest.h/2;
  
  //init map
  init_map = &init_forest;
  draw_lower_map = &draw_lower_forest;
  draw_upper_map = &draw_upper_forest;
  collision_map = &collision_forest;
  free_map = &free_forest;
  
  if(init_map(player_1, player_2, &camera_1, &camera_2) != 0)
    exit(-1);
  
  //draw player_1 side
  draw_lower_map(screen, &camera_1, &player_1_movement);
  SDL_BlitSurface(player_1->image, &player_1->source, screen, &player_1->dest);
  draw_upper_map(screen, &camera_1, &player_1_movement);
  draw_all_bar(player_1, &player_1_movement, screen);
  
  //draw player_2 side
  draw_lower_map(screen, &camera_2, &player_2_movement);
  SDL_BlitSurface(player_2->image, &player_2->source, screen, &player_2->dest);
  draw_upper_map(screen, &camera_2, &player_2_movement);
  draw_all_bar(player_2, &player_2_movement, screen);
  
  //update screen
  SDL_Flip(screen);
  
  //main program
  while(program_run)
  {
    //stop time at current point
    frame_timestop = SDL_GetTicks();
    
    //do only while reading
    while(SDL_PollEvent(&user_input))
    {
      switch(user_input.type)
      {
        case SDL_KEYDOWN:
          key_button[user_input.key.keysym.sym] = 1;
          break;
        case SDL_KEYUP:
          key_button[user_input.key.keysym.sym] = 0;
          break;
        case SDL_QUIT:
          program_run = 0;
          break;
      }
    }
        
    //reset player direction and skills for new read-in
    player_1->direction = dir_none;
    player_1->skill_trigger = dir_none;
    
    player_2->direction = dir_none;
    player_2->skill_trigger = dir_none;
    
    //handle player_1 input
    if(key_button[SDLK_a])
      player_1->direction += dir_left;
    else if(key_button[SDLK_d])
      player_1->direction += dir_right;
    
    if(key_button[SDLK_w])
      player_1->direction += dir_up;
    else if(key_button[SDLK_s])
      player_1->direction += dir_down;
    
    if(key_button[SDLK_1])
      player_1->skill_trigger = 1;
    else if(key_button[SDLK_2])
      player_1->skill_trigger = 2;
    
    //handle player_2 input
    if(key_button[SDLK_LEFT])
      player_2->direction += dir_left;
    else if(key_button[SDLK_RIGHT])
      player_2->direction += dir_right;
    
    if(key_button[SDLK_UP])
      player_2->direction += dir_up;
    else if(key_button[SDLK_DOWN])
      player_2->direction += dir_down;
    
    if(key_button[SDLK_PERIOD])
      player_2->skill_trigger = 1;
    else if(key_button[SDLK_MINUS])
      player_2->skill_trigger = 2;
    
    //handle other input
    if(key_button[SDLK_ESCAPE])
      program_run = 0;
    
    //only move, if direction != dir_none
    if(player_1->direction != dir_none)
    {
      set_direction(player_1);
      animate(player_1);
      collision_map(player_1, &camera_1, &player_1_movement);
      
      move_camera(&camera_1, player_1);
    }
    else
      animate(player_1);
    
    if(player_2->direction != dir_none)
    {
      set_direction(player_2);
      animate(player_2);
      collision_map(player_2, &camera_2, &player_2_movement);
      
      move_camera(&camera_2, player_2);
    }
    else
      animate(player_2);
    
    //handle player_1 side
    //draw lower map layer to player_1 side
    draw_lower_map(screen, &camera_1, &player_1_movement);
    
    player_2_temp = get_dest(player_2, &camera_2, &player_2_movement, &camera_1, &player_1_movement);
    SDL_BlitSurface(player_2->image, &player_2->source, screen, &player_2_temp);
    
    //draw player_1
    SDL_BlitSurface(player_1->image, &player_1->source, screen, &player_1->dest);
    
    //draw upper map layer to player_1 side
    draw_upper_map(screen, &camera_1, &player_1_movement);
    
    //handle player_2 side
    //draw lower map layer to player_2 side
    draw_lower_map(screen, &camera_2, &player_2_movement);
    
    player_1_temp = get_dest(player_1, &camera_1, &player_1_movement, &camera_2, &player_2_movement);
    SDL_BlitSurface(player_1->image, &player_1->source, screen, &player_1_temp);
    
    //draw player_2
    SDL_BlitSurface(player_2->image, &player_2->source, screen, &player_2->dest);
    
    //draw upper map layer to player_2 side
    draw_upper_map(screen, &camera_2, &player_2_movement);
    player_1_call(screen, player_1, &camera_1, &player_1_movement, player_2, &camera_2, &player_2_movement);
    player_2_call(screen, player_2, &camera_2, &player_2_movement, player_1, &camera_1, &player_1_movement);
    //draw black rect to split screen
    SDL_FillRect(screen, &box, 0);
    
    //draw bars
    draw_all_bar(player_1, &player_1_movement, screen);
    draw_all_bar(player_2, &player_2_movement, screen);
    
    //update screen
    SDL_Flip(screen);
    
    //calculate frames
    if(frame_stop_rate >= frame_calc_rate)
    {
      if(1000/frame_rate > (SDL_GetTicks() - frame_timestop))
      {
        frame_delay = 1000/frame_rate - (SDL_GetTicks() - frame_timestop);
      }
      else
      {
        frame_delay = 0;
      }
      
      frame_stop_rate = 0;
    }
    frame_stop_rate++;
    
    //wait calculatet delay
    SDL_Delay(frame_delay);
  }
  
  //clean up and end
  FreeCharacter(player_1);
  FreeCharacter(player_2);
  free_map();
  SDL_FreeSurface(screen);
  return 0;
}