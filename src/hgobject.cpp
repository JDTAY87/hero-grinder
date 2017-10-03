#include "hgobject.h"

SDL_Texture* hgObject::textures[] = { NULL, NULL, NULL, NULL };

int hgObject::pushpull[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void hgObject::settexture( int number, SDL_Texture* texture )
{
    textures[number] = texture;
    return;
}
