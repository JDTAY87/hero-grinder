#include "hgobject.h"

hgTexture* hgObject::textures[] = { NULL, NULL, NULL, NULL };

int hgObject::pushpull[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void hgObject::settexture( int number, hgTexture* texture )
{
    textures[number] = texture;
    return;
}
