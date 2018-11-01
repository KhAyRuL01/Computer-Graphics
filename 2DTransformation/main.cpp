#include <iostream>
#include "screen.h"
#include "rectangle.h"

using namespace std;

int main()
{
    Screen screen;
    Rectangle rect;
    if(!screen.init()){

        cout << "Error initializing SDL" << endl;
        return 1;
    }
    rect.initObj(200, 200, 300, 300, 0x0000ff);
    rect.drawObj(screen);
    SDL_Delay(1000);
    screen.clearScreen();
    rect.tranlateObj(screen, 100, 100);
    SDL_Delay(1000);
    screen.clearScreen();
    rect.scaleObj(screen, 2,1);
    SDL_Delay(1000);
    for(int i = 0; i < 360; i++){

        screen.clearScreen();
        rect.rotateObj(screen, 250, 250, i);
        SDL_Delay(50);
    }
    bool quit = false;
    SDL_Event event;
    while(!quit){

        if(!screen.processEvents())
            quit = true;
    }
    screen.close();
    return 0;
}
