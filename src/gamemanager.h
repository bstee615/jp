#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "log.h"
#include "window.h"
#include "image.h"
#include "imagecollection.h"

//Screen dimension constants

class GameManager {
    ImageCollection *images;
    Window *window;

    typedef struct Keys {
        bool up;
        bool down;
        bool left;
        bool right;
    } Keys;
    Keys keys;

    bool quit;

public:
    GameManager(int w, int h);
    ~GameManager();

    void show();
    void loop();
    void update();
    void render();

    void handleKeyDown(SDL_Event &e);
    void handleKeyUp(SDL_Event &e);
    void loadImage(const char *path);
};

#endif