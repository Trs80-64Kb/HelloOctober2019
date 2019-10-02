#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
using namespace std;

#include <SDL.h>
#include <SDL_main.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Window
{
    public:
        Window();
        virtual ~Window();
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        int window_width;
        int window_height;
        bool isRunning;

        void init();
        void loop();

    protected:

    private:
};

#endif // WINDOW_H
