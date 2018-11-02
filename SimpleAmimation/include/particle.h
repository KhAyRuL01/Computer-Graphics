#ifndef PARTICLE_H
#define PARTICLE_H

#include <cmath>

#include "screen.h"


class Particle
{
    public:

    private:
        float x, y;
        float dir, speed;

    public:
        Particle();
        virtual ~Particle();
        void update();
        void draw(Screen &screen);
        void init();
};

#endif // PARTICLE_H
