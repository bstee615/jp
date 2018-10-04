#include "gameimage.h"

GameImage::GameImage(Image *_img): Image(*_img) {
}

GameImage::GameImage(Image *_img, GameObject *_obj): Image(*_img) {
    obj = _obj;
    lprintf("set size (%02f, %02f)\n", obj->size.x, obj->size.y);
    clip(obj->size);
}

GameImage::GameImage(const char *path): GameImage(new Image(path)) { }

GameImage::GameImage(const char *path, GameObject *_obj): GameImage(new Image(path), _obj) { }

void GameImage::updateToModel() {
    moveTo(obj->pos);
}

void GameImage::setObject(GameObject *obj) {
    this->obj = obj;
    clip(obj->size);
}