#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "screen.h"

class Rectangle
{
    public:


    protected:

    private:
        int x1, y1, x2, y2;
        int color;

    public:
        Rectangle();
        void drawObj(Screen &screen);
        void scaleObj(Screen &screen, int xs, int ys);
        int rotateObj(Screen &screen, int xr, int yr, int theta);
        int tranlateObj(Screen &screen, int xt, int yt);
        void initObj(int x1, int y1, int x2, int y2, int color);

};

#endif // RECTANGLE_H
