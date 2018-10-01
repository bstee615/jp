#include "image.h"
#include "log.h"

Image::Image(const char *path) {
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
