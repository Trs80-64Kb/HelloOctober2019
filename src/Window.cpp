#include "Window.h"

Window::Window()
{
    //ctor
}

Window::~Window()
{
    //dtor
}


void Window::init()
{
    window_height = 650; window_width = 1000;
    window = SDL_CreateWindow("HelloOctober", SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer(window, -1, 0);
    isRunning = true;
}

void Window::loop()
{

    while (isRunning)
    {

        // message processing loop

        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
            // exit if the window is closed
            case SDL_QUIT:
                isRunning = false;
                break;

            // check for keypresses
            case SDL_KEYDOWN:
            {
                // exit if ESCAPE is pressed
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    isRunning = false;
                break;
            }
            } // end switch
        } // end of message processing
        // Drawing

        //Clear screen
        SDL_RenderClear( renderer );

        //Render texture to screen


        //Update screen
        SDL_RenderPresent( renderer );

    }
}
