#ifndef IMAGECOLLECTION_H
#define IMAGECOLLECTION_H

#include <SDL.h>
#include <vector>
#include "image.h"

class ImageCollection {
public:
    std::vector<Image *> images;

    ImageCollection();
    ~ImageCollection();

    Image *addImage(Image *img);
    Image *loadImage(const char *path);

    void blitAllImagesOnSurface(SDL_Surface *dstSurface);
};

#endif