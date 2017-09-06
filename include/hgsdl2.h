#ifndef HGSDL2_H
#define HGSDL2_H
#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class hgSDL2
{
    public:
        hgSDL2();
        bool init();
        SDL_Window* getwindow();
        SDL_Renderer* getrenderer();
        ~hgSDL2();

    protected:

    private:
        bool createwindow();
        bool createrenderer();
        SDL_Window* window;
        SDL_Renderer* renderer;
};

#endif // HGSDL2_H
