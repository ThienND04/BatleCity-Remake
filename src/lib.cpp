#include "lib.h"

SDL_Window* gWindow;
SDL_Renderer* gRenderer;

bool SDL_Init(){
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL_Init failed! SDL_Error: %s\n", SDL_GetError());
        success = false;
	}
    gWindow = SDL_CreateWindow("BATTLE CITY", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(gWindow == NULL){
        printf("SDL could not create Window!\n");
        success = false;
    }
    else{
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        if( gRenderer == NULL )
        {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else {
            SDL_SetRenderDrawColor(gRenderer, 149, 149, 149, 0xFF);
            SDL_RenderClear(gRenderer);
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
        }
    }
    return success;
}
