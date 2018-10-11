#include "gameview.h"
#include "gameobjectmovebyaction.h"
#include "gameobjectmovetoaction.h"
#include <ctime>

GameView::GameView(int w, int h) {
    model = new GameObjectCollection(50, 50, w-100, h-100);
    images = new ImageCollection();
    window = new Window("JetPack", w, h);
    keys = { 0, 0, 0, 0 };
    mouse = { 0, 0, false };

    // Testing code
    lprintf("Testing GameImage and GameObject.\n");
    obj = model->addGameObject(100, 100, 30, 30);
    loadImageToModel("images/smile.bmp", obj);
}

GameView::~GameView() {
    delete model;
    delete images;
    delete window;
}

void GameView::loop(int duration_ms) {
    time_t start = time(0);
    pollEvents();
    update();
    render();
    
    time_t end = time(0);

    if (!quit) {
        if (end <= start + duration_ms) {
            SDL_Delay(end - start + duration_ms);
        }
        loop(duration_ms);
    }
}

void GameView::update() {
    // lprintf("U: %d D: %d L: %d R: %d\n", keys.up, keys.down, keys.left, keys.right);
    
    if (mouse.leftButtonDown) {
        Point size = obj->size;
        const int cellSize = size.x;
        obj->scheduleAction(new GameObjectMoveToAction(obj,
            // Move in a grid
            ((Point(mouse.x, mouse.y) / cellSize).floor() * cellSize) + size / 2));
    }
    else {
        Point delta;
        float speed = 5;
        if (keys.up) { delta.y -= speed; }
        if (keys.down) { delta.y += speed; }
        if (keys.left) { delta.x -= speed; }
        if (keys.right) { delta.x += speed; }
        obj->scheduleAction(new GameObjectMoveByAction(obj, delta));
    }

    model->updateGrid();
}

void GameView::pollEvents() {
    SDL_Event e;

    // Process entire event queue
    while(SDL_PollEvent(&e) != 0)
    {
        switch (e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                handleKeyDown(e);
                break;
            case SDL_KEYUP:
                handleKeyUp(e);
                break;
            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                handleMouseEvent(e);
                break;
        }
    }
}

void GameView::render() {
    updateGameImagesToModel();
    
    SDL_FillRect(window->screenSurface, NULL, SDL_MapRGB(window->screenSurface->format, 24, 206, 106));
    Rect boundsRect = model->boundsRect;
    SDL_Rect rect = { boundsRect.getX() - obj->size.x/2, boundsRect.getY() - obj->size.x/2, boundsRect.getW() + obj->size.x, boundsRect.getH() + obj->size.x };
    SDL_FillRect(window->screenSurface, &rect, SDL_MapRGB(window->screenSurface->format, 11, 96, 50));
    images->blitAllImagesOnSurface(window->screenSurface);
    window->updateSurface();
}

void GameView::handleMouseEvent(SDL_Event &e) {
    int x, y;
    SDL_GetMouseState( &x, &y );

    mouse.x = x;
    mouse.y = y;

    switch (e.type) {
        case SDL_MOUSEBUTTONDOWN:
            mouse.leftButtonDown = true;
            break;
        case SDL_MOUSEBUTTONUP:
            mouse.leftButtonDown = false;
            break;
        // case SDL_MOUSEMOTION: // No behavior for now
        //     break;
        default:
            break;
    }
}

void GameView::handleKeyDown(SDL_Event &e) {
    switch(e.key.keysym.sym)
    {
        case SDLK_UP:
            keys.up = true;
            break;

        case SDLK_DOWN:
            keys.down = true;
            break;

        case SDLK_LEFT:
            keys.left = true;
            break;

        case SDLK_RIGHT:
            keys.right = true;
            break;

        default:
            lprintf("unregistered key %d pressed.\n", e.key.keysym.sym);
            break;
    }
}

void GameView::handleKeyUp(SDL_Event &e) {
    switch(e.key.keysym.sym)
    {
        case SDLK_UP:
            keys.up = false;
            break;

        case SDLK_DOWN:
            keys.down = false;
            break;

        case SDLK_LEFT:
            keys.left = false;
            break;

        case SDLK_RIGHT:
            keys.right = false;
            break;

        case SDLK_ESCAPE:
            quit = true;
            break;

        default:
            lprintf("unregistered key %d released.\n", e.key.keysym.sym);
            break;
    }
}

void GameView::updateGameImagesToModel() {
    for (auto it : images->images) {
        GameImage *gi = dynamic_cast<GameImage*>(it);
        if (gi != nullptr) {
            gi->updateToModel();
        }
    }
}

Image *GameView::loadImage(const char *path) {
    return images->loadImage(path);
}

GameImage *GameView::loadImageToModel(const char *path, GameObject *obj) {    
    GameImage *gi = new GameImage(path, obj);
    images->addImage(gi);
    return gi;
}