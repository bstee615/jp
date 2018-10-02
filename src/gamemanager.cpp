#include "gamemanager.h"

GameManager::GameManager(int w, int h) {
    images = new ImageCollection();
    window = new Window("JetPack", w, h);
    keys = { 0, 0, 0, 0 };
}

GameManager::~GameManager() {
    delete images;
    delete window;
}

void GameManager::loop() {
    update();
    render();

    if (!quit) {
        loop();
    }
}

void GameManager::update() {
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

    lprintf("U: %d D: %d L: %d R: %d\n", keys.up, keys.down, keys.left, keys.right);
}

void GameManager::render() {
    images->blitAllImagesOnSurface(window->screenSurface);
    window->updateSurface();
}

void GameManager::handleKeyDown(SDL_Event &e) {
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

void GameManager::handleKeyUp(SDL_Event &e) {
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

        default:
            lprintf("unregistered key %d released.\n", e.key.keysym.sym);
            break;
    }
}

void GameManager::loadImage(const char *path) {
    images->loadImage(path);
}