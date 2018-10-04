#ifndef GAMEIMAGE_H
#define GAMEIMAGE_H

#include "image.h"
#include "gameobject.h"

class GameImage: public Image {
public:
    GameObject *obj;

    GameImage(Image *_img);
    GameImage(Image *_img, GameObject *_obj);

    GameImage &operator= (const Image &img);

    void updateToModel();
};

#endif