#include "jp.h"

void jp_loop(SDL_Window *window)
{
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);
}