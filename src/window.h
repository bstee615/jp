#include <SDL.h>

class Window {
public:
    SDL_Window* window;
    SDL_Surface* screenSurface;

    Window(const char *title, int w, int h);
    ~Window();

    SDL_Surface *loadBMP(const char *path);
};