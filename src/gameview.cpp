#include "gameview.h"
#include <ctime>
#include <thread>

GameView::GameView(int w, int h) {
    images = new ImageCollection();
    window = new Window("JetPack", w, h);
    keys = { 0, 0, 0, 0 };
}

GameView::~GameView() {
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
    lprintf("U: %d D: %d L: %d R: %d\n", keys.up, keys.down, keys.left, keys.right);
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

void GameView::loadImage(const char *path) {
    images->loadImage(path);
}