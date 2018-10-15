#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include "rect.h"
#include "point.h"
#include "window.h"

class Renderer {
    SDL_Renderer *renderer;

public:
    Renderer(Window *window);
    ~Renderer();

    void clear();
    void draw();
    void drawLine(Point origin, Point length);

    void drawRect(Rect rect);

    void setColor(int r, int g, int b);
};

#endif