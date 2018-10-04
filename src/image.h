#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>
#include "rect.h"
#include "point.h"

class Image {
    SDL_Rect *dstRect = NULL;
    SDL_Rect *clipRect = NULL;
    SDL_Surface *surface = NULL;

public:
    Image(const char *path);
    virtual ~Image();

    void moveTo(int x, int y);
    void moveTo(Point p);

    void clip(int x, int y, int w, int h);
    void clip(Point p);

    void blitOnSurface(SDL_Surface *surface);
};

#endif