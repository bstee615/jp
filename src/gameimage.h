#ifndef GAMEIMAGE_H
#define GAMEIMAGE_H

#include "image.h"
#include "gameobject.h"

class GameImage: public Image {
    GameObject *obj;

public:
    GameImage(Image *_img);
    GameImage(Image *_img, GameObject *_obj);
    GameImage(const char *path);
    GameImage(const char *path, GameObject *_obj);

    GameImage &operator= (const Image &img);

    void updateToModel();
    void setObject(GameObject *obj);
};

#endif