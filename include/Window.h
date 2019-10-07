#ifndef WINDOW_H
#define WINDOW_H
#include "Sprite.h"

class Window
{
    public:
        Window();
        virtual ~Window();
        int width; int height;
        SDL_Window* window; // Main window
        SDL_Renderer* renderer; // Default renderer
        bool isRunning;     // Control is inside loop() function
        bool beenPlayed; // Has Splash screen completed
        bool isGameRendering;
        bool isWide;
        void init();
        SDL_Event event;

         int gameImageTotal;

        Sprite loadSpriteTexture(Sprite sprite_tmp, string path);
        SDL_Texture* loadTexture(Sprite sprite_tmp, string path);
        vector <Sprite> Splash; // All Sprites in Splash Screen
        vector <Sprite> gameVector; // All Sprites for game
        vector <Sprite> pumpkinVector; // All Sprites for pumpkins
        vector <Sprite> players;

        void playSplash();
        void createSplashText();
        void loadSplash();
        void loadGameVector();
        void GameVectorAdd(Sprite tmpSprite);
        void loadPlayer();
        void loadPumpkins();
        void GameRenderer();
        void playerRenderer();
        void loop();

    protected:

    private:
};

#endif // WINDOW_H
