#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "log.h"
#include "window.h"
#include "image.h"
#include "imagecollection.h"

class GameView {
    typedef struct Keys {
        bool up;
        bool down;
        bool left;
        bool right;
    } Keys;

    ImageCollection *images;
    Window *window;
    Keys keys;

    bool quit;

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
    void loadImage(const char *path);
};

#endif