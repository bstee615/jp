#include "gameimage.h"

GameImage::GameImage(Image *_img): Image(*_img) {
}

GameImage::GameImage(Image *_img, GameObject *_obj): Image(*_img) {
    obj = _obj;
    clip(0, 0, obj->rect.size.x, obj->rect.size.y);
}

void GameImage::updateToModel() {
    lprintf("Moving to (%f, %f)\n", obj->rect.pos.x, obj->rect.pos.y);
    move(obj->rect.pos.x - obj->rect.size.x, obj->rect.pos.y - obj->rect.size.y);
}