#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "log.h"
#include "window.h"
#include "image.h"
#include "imagecollection.h"
#include "gamemanager.h"
#include "gameimage.h"

class GameView {
    typedef struct Keys {
        bool up;
        bool down;
        bool left;
        bool right;
    } Keys;

    GameManager *model;
    ImageCollection *images;
    Window *window;
    Keys keys;

    bool quit;

    // Testing code
    GameObject *obj;

public:
    GameView(int w, int h);
    ~GameView();

    void show();
    void loop(int duration_ms);
    void update();
    void pollEvents();
    void render();

    void handleKeyDown(SDL_Event &e);
    void handleKeyUp(SDL_Event &e);
    Image *loadImage(const char *path);
    GameImage *loadImageToModel(const char *path, GameObject *obj);
    void updateGameImagesToModel();
};

#endif