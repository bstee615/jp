#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>

class Image {
    SDL_Rect *dstRect = NULL;
    SDL_Rect *clipRect = NULL;
    SDL_Surface *surface = NULL;

public:
    Image(const char *path);
    virtual ~Image();

    void move(int x, int y);

    void clip(int x, int y, int w, int h);

    void blitOnSurface(SDL_Surface *surface);
};

#endif