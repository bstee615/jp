#include "imagecollection.h"
#include "log.h"

ImageCollection::ImageCollection() {
    images = std::vector<Image *>();
}

ImageCollection::~ImageCollection() {
    for (size_t i = 0; i < images.size(); i ++) {
        delete (images.at(i));
    }
}

Image *ImageCollection::addImage(Image *img) {
    images.push_back(img);
    return img;
}

Image *ImageCollection::loadImage(const char *path) {
    lprintf("Loading %s.\n", path);
    return addImage(new Image(path));
}

void ImageCollection::blitAllImagesOnSurface(SDL_Surface *dstSurface) {
    // lprintf("Blitting %d images.\n", images.size());
    for (size_t i = 0; i < images.size(); i ++) {
        // lprintf("Blitting image %d.\n", i);
        images.at(i)->blitOnSurface(dstSurface);
    }
}