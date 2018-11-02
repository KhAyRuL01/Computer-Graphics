#include <cmath>

#include "circle.h"
#include "screen.h"

#define PI acos(-1)

Circle::Circle(int x, int y, int r)
{
    this-> x = x;
    this-> y = y;
    this-> r = r;
}

Circle::~Circle()
{
    //dtor
}

void Circle::draw(Screen &screen, int theta){

    int xr = Screen::WIDTH/2;
    int yr = Screen::HEIGHT/2;
    for(int i = abs(x-r); i < x+r; i++){

        int y1 = abs(y-sqrt(r*r-(i-x)*(i-x)));
        int y2 = abs(y+sqrt(r*r-(i-x)*(i-x)));
        for(int j = y1; j < y2; j++){

            float x = xr+(i-xr)*cos(PI*theta/180)-(j-yr)*sin(PI*theta/180);
            float y = yr+(i-xr)*sin(PI*theta/180)+(j-yr)*cos(PI*theta/180);
            screen.setPixel(x, y, 255, 0, 0);
            screen.setPixel(x+0.9, y, 255, 0, 0);
            screen.setPixel(x, y+0.9, 255, 0, 0);
            screen.setPixel(x+0.9, y+0.9, 255, 0, 0);
        }
    }
    screen.update();
}

void Circle::clear(Screen &screen, int theta){

    int xr = Screen::WIDTH/2;
    int yr = Screen::HEIGHT/2;
    for(int i = abs(x-r); i < x+r; i++){

        int y1 = abs(y-sqrt(r*r-(i-x)*(i-x)));
        int y2 = abs(y+sqrt(r*r-(i-x)*(i-x)));
        for(int j = y1; j < y2; j++){

            float x = xr+(i-xr)*cos(PI*theta/180)-(j-yr)*sin(PI*theta/180);
            float y = yr+(i-xr)*sin(PI*theta/180)+(j-yr)*cos(PI*theta/180);
            screen.setPixel(x, y, 0, 0, 0);
            screen.setPixel(x+0.9, y, 0, 0, 0);
            screen.setPixel(x, y+0.9, 0, 0, 0);
            screen.setPixel(x+0.9, y+0.9, 0, 0, 0);
        }
    }
    screen.update();
}
