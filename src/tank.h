#ifndef TANK_H
#define TANK_H

#include<SDL.h>
#include "enums.h"

class Tank{
public: 
    void move();
    void shot();
    SDL_Rect boundingBox();

    int getX() const { return x; }
    void setX(int x_) { x = x_; }

    int getY() const { return y; }
    void setY(int y_) { y = y_; }

    Direction getDirection() const { return direction; }
    void setDirection(const Direction &direction_) { direction = direction_; }

private:
    int x;
    int y;
    int width;
    int height;
    int speed;  
    Direction direction;
    bool isMoving;
};

#endif