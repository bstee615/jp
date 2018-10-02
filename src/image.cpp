#include "image.h"
#include "log.h"

Image::Image(const char *path) {
    dstRect = new SDL_Rect();
    dstRect->x = 0;
    dstRect->y = 0;

    lprintf("Loading path %s.\n", path);
    surface = SDL_LoadBMP(path);
    if( surface == NULL )
    {
        lprintf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
    }
}

Image::~Image() {
    SDL_FreeSurface(surface);
    surface = NULL;
}

void Image::move(int x, int y) {
    // lprintf("Moving image to (%d, %d).", x, y);
    *this->dstRect = { x, y, 0, 0 };
}

void Image::clip(int x, int y, int w, int h) {
    *this->clipRect = { x, y, w, h };
}

void Image::blitOnSurface(SDL_Surface *dstSurface) {
    // lprintf("Blitted image on surface at (%d, %d).\n", dstRect->x, dstRect->y);
    SDL_BlitSurface(surface, clipRect, dstSurface, dstRect);
}
