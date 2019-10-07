#include "Window.h"

int main(int argc, char* argv[])
{
    // TODO need to add frames per second limiter
    // TODO need to add keyboard controls for player
    // TODO need to add sounds
    // TODO need to add animations
    // TODO need to add cauldron image


    Window win; // Create Window object
    win.init(); // Initialize window size, position, title, etc...
    win.createSplashText(); // Create text texture from surface
    win.loadSplash(); // Load Splash Screen
    win.loadGameVector(); // Load images for Game vector
    win.loadPlayer();  //Load Player images to make textures
    win.loop();
        // TODO Add "clean up" delete and free all objects
    cout << "Hello October!" << endl;
    return 0;
}
