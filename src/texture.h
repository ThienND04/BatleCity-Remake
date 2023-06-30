#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Texture{
public:
    bool loadFromFile(SDL_Renderer* renderer, std::string path, SDL_bool colorKeying = SDL_TRUE);
    // void loadFromText();

    void render(int x, int y, SDL_Rect* clip, double angle = 0, SDL_Point* center = NULL);

    void free();

    void setBlendMode(SDL_BlendMode blending);
    void setAlpha(int alpha);

private: 
    int width;
    int height;

    SDL_Renderer* renderer;
    SDL_Texture* wrapedTexture;
};

bool Texture::loadFromFile(SDL_Renderer* renderer, std::string path, SDL_bool colorKeying){
    SDL_Texture* newTexture = NULL;
    free();
    this->renderer = renderer;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL){
        printf("Unable to load image %s! IMG Error: %s\n", path, IMG_GetError());
    }
    else{
        SDL_SetColorKey(loadedSurface, colorKeying, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

        if(newTexture == NULL){
            printf("Unable to create Texture from %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
        }
        else{
            width = loadedSurface->w;
            height = loadedSurface->h;
        }

        SDL_FreeSurface(loadedSurface);
    }

    wrapedTexture = newTexture;
    return wrapedTexture != NULL;
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center){
    SDL_Rect renderSpace = {x, y, width, height};
    if(clip != NULL) {
        renderSpace.w = clip->w;
        renderSpace.h = clip->h;
    }
    SDL_RenderCopyEx(renderer, wrapedTexture, clip, &renderSpace, angle,  center, SDL_FLIP_NONE);
}

void Texture::free(){
    if(wrapedTexture != NULL){
        SDL_DestroyTexture(wrapedTexture);
        wrapedTexture = NULL;
        height = 0;
        width = 0;
    }
}

void Texture::setBlendMode(SDL_BlendMode blending){
    SDL_SetTextureBlendMode(wrapedTexture, blending);
}

void Texture::setAlpha(int alpha){
    SDL_SetTextureAlphaMod(wrapedTexture, alpha);
}

#endif