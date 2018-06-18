#include <data.h>

SDL_Surface *load_image(const char *image_path)
{
  SDL_Surface *temp = NULL;
  
  if((temp = IMG_Load(image_path)) != NULL)
  {
    return SDL_DisplayFormatAlpha(temp);
  }
  
  return NULL;
}
void FreeCharacter(character* object)
{
  SDL_FreeSurface(object->image);
  free(object);
}