#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "log.h"
#include "window.h"
#include "image.h"
#include "imagecollection.h"
#include "gameobjectcollection.h"
#include "gameimage.h"
#include "gridmanager.h"

class GameView {
    typedef struct Keys {
        bool up;
        bool down;
        bool left;
        bool right;
    } Keys;

    typedef struct Mouse {
        int x, y;
        bool leftButtonDown;
    } Mouse;

    GridManager *gridManager;
    GameObjectCollection *model;
    ImageCollection *images;
    Window *window;
    Keys keys;
    Mouse mouse;

    bool quit;

    // Testing code
    GameObject *grabbedObj = nullptr;
    Point gridSize;
    
    void update();
    void pollEvents();
    void render();

    void handleMouseEvent(SDL_Event &e);
    void handleKeyDown(SDL_Event &e);
    void handleKeyUp(SDL_Event &e);
    Image *loadImage(const char *path);
    GameImage *loadImageToModel(const char *path, GameObject *obj);
    void updateGameImagesToModel();

public:
    GameView(int w, int h);
    ~GameView();

    void show();
    void loop(int duration_ms);
};

#endif