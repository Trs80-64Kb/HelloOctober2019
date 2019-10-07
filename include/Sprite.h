#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_timer.h>

class Sprite
{
    public:
        Sprite();
        virtual ~Sprite();
        SDL_Texture* texture;
        string spritePath;
        SDL_Rect spriteRect;
        SDL_Point center;
        SDL_RendererFlip flip;
        double angle;



    protected:

    private:
};

#endif // SPRITE_H
