#include "window.h"
#include "log.h"

Window::Window(const char *title, int w, int h) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        lprintf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        screenSurface = SDL_GetWindowSurface(window);
    }
}

Window::~Window() {
    SDL_DestroyWindow(window);
    window = NULL;
}

void Window::updateSurface() {
    SDL_UpdateWindowSurface(window);
}
