#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include "image.h"

class Window {
public:
    SDL_Window* window;
    SDL_Surface* screenSurface;

    Window(const char *title, int w, int h);
    ~Window();

    void updateSurface();
};

#endif