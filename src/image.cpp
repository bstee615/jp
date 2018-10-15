#include "image.h"
#include "log.h"

Image::Image(const char *path) {
    dstRect = new SDL_Rect();
    dstRect->x = 0;
    dstRect->y = 0;

    clipRect = new SDL_Rect();

    lprintf("Loading path %s.\n", path);
    surface = SDL_LoadBMP(path);
    if( surface == NULL )
    {
        lprintf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
    }
}

Image::Image(SDL_Surface *surface) {
    dstRect = new SDL_Rect();
    dstRect->x = 0;
    dstRect->y = 0;

    clipRect = new SDL_Rect();

    surface = surface;
}

Image::~Image() {
    SDL_FreeSurface(surface);
    surface = NULL;
}

void Image::moveTo(int x, int y) {
    // lprintf("Moving image to (%d, %d).", x, y);
    *dstRect = { x, y, 0, 0 };
}

void Image::moveTo(Point p) {
    // lprintf("Moving image to (%d, %d).", x, y);
    *dstRect = { (int)p.x, (int)p.y, 0, 0 };
}

void Image::clip(int x, int y, int w, int h) {
    *clipRect = { x, y, w, h };
}

void Image::clip(Point p) {
    clip(0, 0, (int)(p.x * 4), (int)(p.y * 4));
}

void Image::blitOnSurface(SDL_Surface *dstSurface) {
    // lprintf("Blitting image at (%d, %d).\n", dstRect->x, dstRect->y);
    SDL_BlitSurface(surface, clipRect, dstSurface, dstRect);
}