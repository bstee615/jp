#include "gameimage.h"

GameImage::GameImage(Image *_img): Image(*_img) {
}

GameImage::GameImage(Image *_img, GameObject *_obj): Image(*_img) {
    obj = _obj;
    clip(obj->size);
}

GameImage::GameImage(const char *path): GameImage(new Image(path)) { }

GameImage::GameImage(const char *path, GameObject *_obj): GameImage(new Image(path), _obj) { }

void GameImage::updateToModel() {
    moveTo(obj->pos);
}

GameObject *GameImage::getObject() {
    return obj;
}

void GameImage::setObject(GameObject *obj) {
    this->obj = obj;
    clip(obj->size);
}