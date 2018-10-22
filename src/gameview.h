#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "log.h"
#include "window.h"
#include "image.h"
#include "imagecollection.h"
#include "gameobjectcollection.h"
#include "gameimage.h"
#include "renderer.h"
#include <unordered_map>

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

    GameObjectCollection *model;
    ImageCollection *images;
    Window *window;
    Renderer *renderer;
    Keys keys;
    Mouse mouse;

    bool quit;

    // Testing code
    GameObject *selectedObj = nullptr;

    std::unordered_map<const char*, SDL_Surface *> preloadedSurfaces;
    void preloadSurfaces();
    
    void update();
    void pollEvents();
    void render();

    void handleMouseEvent(SDL_Event &e);
    void handleKeyDown(SDL_Event &e);
    void handleKeyUp(SDL_Event &e);

    GameObject *findObjectAtPoint(Point p);

    Image *loadImage(const char *path);
    void updateGameImagesToModel();
    GameImage *loadImageToModel(const char *path, GameObject *obj);

public:
    GameView(int w, int h);
    ~GameView();

    void show();
    void loop(int duration_ms);
};

#endif