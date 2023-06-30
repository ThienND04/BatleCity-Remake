#include "tank.h"

SDL_Rect Tank::boundingBox(){
    return {x, y, width, height};
}