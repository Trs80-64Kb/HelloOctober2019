#include "Window.h"


int main(int argc, char* argv[])
{
    Window win;
    win.init();
    win.loop();
    cout << "Hello October!" << endl;
    return 0;
}
