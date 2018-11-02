#include "particle.h"
#include "screen.h"
#include <iostream>
#include <cmath>

#define PI acos(-1)


Particle::Particle()
{
    x = Screen::WIDTH/2;
    y = Screen::HEIGHT/2;
    dir = ((2.0*PI*rand()/RAND_MAX));
    speed = 0.9*((2.0*rand()/RAND_MAX));
}

void Particle::init(){

    x = Screen::WIDTH/2;
    y = Screen::HEIGHT/2;
    dir = ((2.0*PI*rand()/RAND_MAX));
    speed = 0.9*((2.0*rand()/RAND_MAX));
}
Particle::~Particle()
{
    //dtor
}

void Particle::update(){

    float xdir = speed*cos(dir);
    float ydir = speed*sin(dir);
    x += xdir;
    y += ydir;
    if(x< 0 || x>Screen::WIDTH) {

        this->init();
    }
    if(y< 0 || y>Screen::HEIGHT){

        this->init();
    }
}

void Particle::draw(Screen &screen){

    Uint8 r = 200+rand()%56;
    Uint8 g = 200+rand()%56;
    Uint8 b = 200+rand()%56;
    screen.setPixel(x, y, r, g, b);
}
