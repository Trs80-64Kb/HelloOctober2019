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
    // Initialize SDL2 for  window, sound, and event for keyboard and mouse

   if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
   {
       cout << "Initialized SDL2 for  window, sound, and event for keyboard and mouse" << endl;
   }
   else
    {
        cout << "Error Initializing SDL2" << endl;
    }


   // Initialize SDL2 image
    if (SDL_Init(IMG_Init(IMG_INIT_PNG)) == 0)
   {
       cout << " Initialized SDL2 image" << endl;
   }
   else
    {
        cout << "Error Initializing SDL2 image " << endl;
    }

        // Initialize TTF for text
 if ( TTF_Init() == 0)
   {
       cout << " Initialized TTF for fonts" << endl;
   }
   else
    {
        cout << "Error Initializing TTF " << endl;
    }


    // integers use for window size
    width = 840;
    height = 680;
    // Set window variables such as title, width, height, and position
    window = SDL_CreateWindow("HelloOctober", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(window != NULL)
    {
        cout << "window  Initialized " << endl;

    }
    else
    {
         cout << SDL_GetError() << endl;
    }

     // Connect renderer to window
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer != NULL)
    {
        cout << "renderer  Initialized " << endl;

    }
     else
    {
        cout << "Error creating renderer" << endl;
         cout << SDL_GetError() << endl;
    }

    // Set total images used in Game
    gameImageTotal = 6;
    isWide = false;
    // Splash has been played or not
    beenPlayed = false;
    // Controls and exits loop function
    isGameRendering = false;
    isRunning = true;
}

void Window::playSplash()
{
    SDL_RenderCopyEx(renderer, Splash[1].texture, NULL, &Splash[1].spriteRect, Splash[1].angle, &Splash[1].center, Splash[1].flip);
    SDL_RenderCopyEx(renderer, Splash[0].texture, NULL, &Splash[0].spriteRect, Splash[0].angle, &Splash[0].center, Splash[0].flip);
}

void Window::createSplashText()
{
    // Load font from file path
    TTF_Font * font = TTF_OpenFont("fonts/Sansation_Regular.ttf", 25);
    // Set font color

    SDL_Color color = { 255,165,0 };
    // Create surface to hold text
            // TODO add string  variable to change text
    SDL_Surface * surf = TTF_RenderText_Solid(font, "Hello October", color);

    // Create Sprite to hold SDL_Texture
    Sprite text;
    text.texture = SDL_CreateTextureFromSurface(renderer, surf);
    text.angle = 0;
    text.center.x = 200;
    text.center.y = 200;
    text.flip = SDL_FLIP_NONE;
    text.spriteRect.h = 150;
    text.spriteRect.w = 450;
    text.spriteRect.x = 200;
    text.spriteRect.y = 520;

    // Add text to Splash vector
    Splash.push_back(text);

    SDL_FreeSurface(surf);
}

Sprite Window::loadSpriteTexture(Sprite sprite_tmp, string path)
{
    // Create surface from path
    SDL_Surface* surf = IMG_Load(path.c_str());
    // load texture into Sprite
    sprite_tmp.texture = SDL_CreateTextureFromSurface(renderer, surf);
    // Free used surface
    SDL_FreeSurface(surf);

    // Return SDL2_Texture in sprite
    return sprite_tmp;
}

SDL_Texture* Window::loadTexture(Sprite sprite_tmp, string path)
{
    // Create surface from path
    SDL_Surface* surf = IMG_Load(path.c_str());

    // load texture into Sprite
    sprite_tmp.texture = SDL_CreateTextureFromSurface(renderer, surf);
    // Return Sdl_Texture in sprite
    return sprite_tmp.texture;
}


void Window::loadSplash()
{
    Sprite frame;
    // Set frame
    frame.angle = 0;
    frame.center.x = width / 2;// Set SDL_Rect in Sprite object
    frame.center.y = height / 2;
    frame.flip = SDL_FLIP_NONE;
    frame.spritePath = "images/mask2.png";
    frame.spriteRect.h = height; // Set SDL_Rect in Sprite object
    frame.spriteRect.w = width;
    frame.spriteRect.x = 0;// Set SDL_Rect in Sprite object
    frame.spriteRect.y = 0;
    // Load image from path
    SDL_Surface* surf = IMG_Load(frame.spritePath.c_str());
    // Load surface into texture
    frame.texture = SDL_CreateTextureFromSurface(renderer, surf);
    // Add frame to Splash vector
    Splash.push_back(frame);
    // Free used surface
    SDL_FreeSurface(surf);
}

void Window::loadGameVector()
{
    Sprite tempSprite;
      tempSprite = loadSpriteTexture(tempSprite, "images/castle.png");

    tempSprite.spriteRect.h = 700;// Set SDL_Rect in Sprite object
    tempSprite.spriteRect.w = 1200;
    tempSprite.spriteRect.x = 0;
    tempSprite.spriteRect.y = 0;
    tempSprite.angle = 0;// Set SDL_Rect in Sprite object
    tempSprite.center.x = 100;
    tempSprite.center.y = 150;
    tempSprite.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    // Add updated tempSprite to  GameVector
    GameVectorAdd(tempSprite);


     tempSprite = loadSpriteTexture(tempSprite, "images/house1.png");
    tempSprite.spriteRect.h = 200;// Set SDL_Rect in Sprite object
    tempSprite.spriteRect.w = 250;
    tempSprite.spriteRect.x = 170;
    tempSprite.spriteRect.y = 365;
    tempSprite.angle = 0;// Set SDL_Rect in Sprite object
    tempSprite.center.x = 100;
    tempSprite.center.y = 150;
    tempSprite.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
     // Add updated tempSprite to  GameVector
    GameVectorAdd(tempSprite);

    tempSprite = loadSpriteTexture(tempSprite, "images/house2.png");
    tempSprite.spriteRect.h = 200;// Set SDL_Rect in Sprite object
    tempSprite.spriteRect.w = 250;
    tempSprite.spriteRect.x = 300;
    tempSprite.spriteRect.y = 360;
    tempSprite.angle = 0;// Set SDL_Rect in Sprite object
    tempSprite.center.x = 20;
    tempSprite.center.y = 50;
    tempSprite.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    // Add updated tempSprite to  GameVector
    GameVectorAdd(tempSprite);

    // TODO need to set positions for rest of houses
    tempSprite = loadSpriteTexture(tempSprite, "images/house3.png");

    tempSprite.spriteRect.h = 200;// Set SDL_Rect in Sprite object
    tempSprite.spriteRect.w = 250;
    tempSprite.spriteRect.x = 440;
    tempSprite.spriteRect.y = 390;
    tempSprite.angle = 0;// Set SDL_Rect in Sprite object
    tempSprite.center.x = 20;
    tempSprite.center.y = 20;
    tempSprite.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    GameVectorAdd(tempSprite);

    tempSprite = loadSpriteTexture(tempSprite, "images/house4.png");
     tempSprite.spriteRect.h = 250;// Set SDL_Rect in Sprite object
    tempSprite.spriteRect.w = 300;
    tempSprite.spriteRect.x = 650;
    tempSprite.spriteRect.y = 365;
    tempSprite.angle = 0;// Set SDL_Rect in Sprite object
    tempSprite.center.x = 60;
    tempSprite.center.y = 120;
    tempSprite.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    GameVectorAdd(tempSprite);

    tempSprite = loadSpriteTexture(tempSprite, "images/witch.png");

    tempSprite.spriteRect.h = 100;// Set SDL_Rect in Sprite object
    tempSprite.spriteRect.w = 150;
    tempSprite.spriteRect.x = 450;
    tempSprite.spriteRect.y = 100;
    tempSprite.angle = 0;// Set SDL_Rect in Sprite object
    tempSprite.center.x = 60;
    tempSprite.center.y = 120;
    tempSprite.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object

    GameVectorAdd(tempSprite);
    tempSprite = loadSpriteTexture(tempSprite, "images/pg1.png");

    tempSprite.spriteRect.h = 30;// Set SDL_Rect in Sprite object
    tempSprite.spriteRect.w = 50;
    tempSprite.spriteRect.x = 60;
    tempSprite.spriteRect.y = 55;
    tempSprite.angle = 0;// Set SDL_Rect in Sprite object
    tempSprite.center.x = 60;
    tempSprite.center.y = 120;
    tempSprite.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object


    GameVectorAdd(tempSprite);

        // TODO need to turn repetitive task to a function

}

void Window::GameVectorAdd(Sprite tmpSprite)
{
    gameVector.push_back(tmpSprite);

}



void Window::loadPumpkins()
{

}


void Window::loadPlayer()
{

    Sprite spriteTemp;
    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a1.png");

     spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 470;
    spriteTemp.spriteRect.y = 500;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object

    players.push_back(spriteTemp);
    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a2.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 470;
    spriteTemp.spriteRect.y = 500;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a3.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 470;
    spriteTemp.spriteRect.y = 500;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a4.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 470;
    spriteTemp.spriteRect.y = 500;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a5.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 260;
    spriteTemp.spriteRect.y = 500;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a6.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 260;
    spriteTemp.spriteRect.y = 470;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a7.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 260;
    spriteTemp.spriteRect.y = 470;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a8.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 260;
    spriteTemp.spriteRect.y = 470;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a9.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 260;
    spriteTemp.spriteRect.y = 470;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a10.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 260;
    spriteTemp.spriteRect.y = 470;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a11.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 260;
    spriteTemp.spriteRect.y = 470;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);

    spriteTemp.texture = loadTexture(spriteTemp, "images/characters/a12.png");
    spriteTemp.spriteRect.h = 48;// Set SDL_Rect in Sprite object
    spriteTemp.spriteRect.w = 48;
    spriteTemp.spriteRect.x = 260;
    spriteTemp.spriteRect.y = 470;
    spriteTemp.angle = 0;// Set SDL_Rect in Sprite object
    spriteTemp.center.x = 60;
    spriteTemp.center.y = 120;
    spriteTemp.flip = SDL_FLIP_NONE;// Set SDL_Rect in Sprite object
    players.push_back(spriteTemp);


}


void Window::GameRenderer()
{
    // RenderCopy Game images
    SDL_RenderCopyEx(renderer, gameVector[0].texture, NULL, &gameVector[0].spriteRect, gameVector[0].angle, &gameVector[0].center, gameVector[0].flip);
    SDL_RenderCopyEx(renderer, gameVector[1].texture, NULL, &gameVector[1].spriteRect, gameVector[1].angle, &gameVector[1].center, gameVector[1].flip);
    SDL_RenderCopyEx(renderer, gameVector[2].texture, NULL, &gameVector[2].spriteRect, gameVector[2].angle, &gameVector[2].center, gameVector[2].flip);
    SDL_RenderCopyEx(renderer, gameVector[3].texture, NULL, &gameVector[3].spriteRect, gameVector[3].angle, &gameVector[3].center, gameVector[3].flip);
    SDL_RenderCopyEx(renderer, gameVector[4].texture, NULL, &gameVector[4].spriteRect, gameVector[4].angle, &gameVector[4].center, gameVector[4].flip);
    SDL_RenderCopyEx(renderer, gameVector[5].texture, NULL, &gameVector[5].spriteRect, gameVector[5].angle, &gameVector[5].center, gameVector[5].flip);
    SDL_RenderCopyEx(renderer, gameVector[6].texture, NULL, &gameVector[6].spriteRect, gameVector[6].angle, &gameVector[6].center, gameVector[6].flip);
}

void Window::playerRenderer()
{
    int i = 2;
        SDL_RenderCopyEx(renderer, players[i].texture, NULL, &players[i].spriteRect, players[i].angle, &players[i].center, players[i].flip);

}

void Window::loop()
{


    while (isRunning)
    {

        // Start Clock
       Uint32 clockStart = SDL_GetTicks();
       if(clockStart > 4000)
       {
           beenPlayed = true;
            isGameRendering = true;
            SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN);
       }

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
cout << "renderer  Initialized " << endl;
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
        if(!beenPlayed)   // boolean Controls Splash Screen
        {
            playSplash(); // Render Splash Screen images


        }

            if(isGameRendering)   // boolean Controls  rendering of Game images
        {

            GameRenderer();
             playerRenderer();
        }



        //Update screen
        SDL_RenderPresent( renderer );

    }
}
