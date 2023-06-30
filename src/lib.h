#ifndef LIB_H
#define LIB_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600; 

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

bool SDL_Init();

void loadMedia();

void exit();

#endif