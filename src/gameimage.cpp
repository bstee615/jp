#include "gameimage.h"

GameImage::GameImage(Image *_img): Image(*_img) {
}

GameImage::GameImage(Image *_img, GameObject *_obj): Image(*_img) {
    obj = _obj;
    clip(0, 0, obj->size.x, obj->size.y);
}

void GameImage::updateToModel() {
    moveTo(obj->pos);
}