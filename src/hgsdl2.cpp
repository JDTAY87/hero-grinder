#include "hgsdl2.h"

hgSDL2::hgSDL2()
{
    return;
}

bool hgSDL2::init()
{
    bool success = true;
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        printf( "hgSDL2::init failed. %s/n", SDL_GetError() );
        success = false;
    }
    else if ( (IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG) != IMG_INIT_PNG )
    {
        printf( "hgSDL2::init failed. %s/n", SDL_GetError() );
        success = false;
    }
    else if ( !hgSDL2::createwindow() ) { success = false; }
    return success;
}

bool hgSDL2::createwindow()
{
    bool success = true;
    window = SDL_CreateWindow( "Hero Grinder", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_SHOWN);
    if ( window == NULL )
    {
        printf( "hgSDL2::createwindow failed. %s/n", SDL_GetError() );
        success = false;
    }
    else if ( !hgSDL2::createrenderer() ) { success = false; }
    return success;
}

bool hgSDL2::createrenderer()
{
    bool success = true;
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC );
    if ( renderer == NULL )
    {
        printf( "hgSDL2::createrenderer failed. %s/n", SDL_GetError() );
        success = false;
    }
    else
    {
        SDL_RenderSetLogicalSize( renderer, 640, 360 );
        SDL_RenderSetIntegerScale( renderer, SDL_TRUE );
    }
    return success;
}

SDL_Renderer* hgSDL2::getrenderer()
{
    return renderer;
}

hgSDL2::~hgSDL2()
{
    SDL_DestroyRenderer( renderer );
    renderer = NULL;
    SDL_DestroyWindow( window );
    window = NULL;
    IMG_Quit();
    SDL_Quit();
    return;
}
