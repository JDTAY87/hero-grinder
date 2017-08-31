#include "hgtexture.h"

hgTexture::hgTexture()
{
    return;
}

bool hgTexture::loadtexture( SDL_Renderer* renderer, const char* filename )
{
    bool success = true;
    SDL_Surface* surface;
    surface = IMG_Load( filename );
    if ( surface == NULL )
    {
        printf( "hgTexture::loadtexture failed. %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        texture = SDL_CreateTextureFromSurface( renderer, surface );
        if ( texture == NULL )
        {
            printf( "hgTexture::loadtexture failed. %s\n", SDL_GetError() );
            success = false;
        }
    }
    SDL_FreeSurface( surface );
    return success;
}

SDL_Texture* hgTexture::gettexture()
{
    return texture;
}

hgTexture::~hgTexture()
{
    SDL_DestroyTexture( texture );
    texture = NULL;
    return;
}
