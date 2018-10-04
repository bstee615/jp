#include "gameview.h"
#include <ctime>
#include <thread>

GameView::GameView(int w, int h) {
    model = new GameManager();
    images = new ImageCollection();
    window = new Window("JetPack", w, h);
    keys = { 0, 0, 0, 0 };

    // Testing code
    obj = model->addGameObject(10, 0, 100, 100);
    loadImageToModel("images/hello_world.bmp", obj);
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
    Point delta;
    if (keys.up) { delta.y --; }
    if (keys.down) { delta.y ++; }
    if (keys.left) { delta.x --; }
    if (keys.right) { delta.x ++; }
    obj->rect.moveBy(delta);
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
        }
    }
}

void GameView::render() {
    updateGameImagesToModel();
    
    SDL_FillRect(window->screenSurface, NULL, SDL_MapRGB(window->screenSurface->format, 0xFF, 0x00, 0x00));
    images->blitAllImagesOnSurface(window->screenSurface);
    window->updateSurface();
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
    Image *img = new Image(path);
    GameImage *gi = new GameImage(img);
    images->addImage(gi);
    gi->obj = obj;
    return gi;
}