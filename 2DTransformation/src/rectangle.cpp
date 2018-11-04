#include <cmath>

#include "rectangle.h"
#include "screen.h"

#define PI acos(-1)

Rectangle::Rectangle()
{

}

void Rectangle:: initObj(int x1, int y1, int x2, int y2, int color=0xffffff)
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
    this->color = color;
}

void Rectangle::drawObj(Screen &screen){

    for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++)
            screen.setPixel(i, j, color);
    }
}

void Rectangle::scaleObj(Screen &screen, int xs, int ys){

    for(int i = x1*xs; i < x2*xs; i++){
        for(int j = y1*ys; j < y2*ys; j++)
            screen.setPixel(i, j, color);
    }
}

int Rectangle::rotateObj(Screen &screen, int xr, int yr, int theta){

    for(int i = x1; i < x2; i++){

        for(int j = y1; j < y2; j++){

            float x = xr+(i-xr)*cos(PI*theta/180)-(j-yr)*sin(PI*theta/180);
            float y = yr+(i-xr)*sin(PI*theta/180)+(j-yr)*cos(PI*theta/180);
            screen.setPixel(x, y, color);
            screen.setPixel(x+0.9, y, color);
            screen.setPixel(x, y+0.9, color);
            screen.setPixel(x+0.9, y+0.9, color);
        }
    }
}

int Rectangle::tranlateObj(Screen &screen, int xt, int yt){

    for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++)
            screen.setPixel(i+xt, j+yt, color);
    }
}

void Rectangle::setColor(int color){

    this-> color = color;
}
