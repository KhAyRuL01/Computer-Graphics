#include <cmath>
#include <iostream>
#include "screen.h"
#include "circle.h"
#include "particle.h"


using namespace std;

int main()
{
    Screen screen;
    Circle circle1(Screen::WIDTH/2, Screen::HEIGHT/2, 50);
    Circle circle2(200, 200, 30);
    if(!screen.init()){

        cout << "Error initializing SDL" << endl;
        return 1;
    }
    for(int i = 0; i < 360; i+=1){

        circle1.draw(screen,0);
        circle2.draw(screen, i);
        SDL_Delay(20);
        circle2.clear(screen, i);
    }
    SDL_Delay(1000);
    Particle par[10000];
    SDL_Event event;
    while(true){

        screen.clearScreen();
        for(int i = 0; i < 10000; i++){

            par[i].update();
            par[i].draw(screen);
        }
        screen.update();
        if(!screen.processEvents())
            break;
    }
    screen.close();
    return 0;
}
