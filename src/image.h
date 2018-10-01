#include <SDL.h>

class Image {
public:
    SDL_Surface *surface = NULL;
    Image(const char *path);
    ~Image();
};