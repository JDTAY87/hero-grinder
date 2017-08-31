#ifndef HGTEXTURE_H
#define HGTEXTURE_H
#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

class hgTexture
{
    public:
        hgTexture();
        bool loadtexture( SDL_Renderer* renderer, const char* filename );
        SDL_Texture* gettexture();
        ~hgTexture();

    protected:

    private:
        SDL_Texture* texture;
};

#endif // HGTEXTURE_H
