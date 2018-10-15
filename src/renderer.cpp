#include "renderer.h"

Renderer::Renderer(Window *window) {
    renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
}

void Renderer::drawLine(Point origin, Point length) {
    Point end = origin + length;
    SDL_RenderDrawLine(renderer, (int)origin.x, (int)origin.y, (int)end.x, (int)end.y);
}

void Renderer::clear() {
    SDL_RenderClear(renderer);
}

void Renderer::draw() {
    SDL_RenderPresent(renderer);
}

void Renderer::drawRect(Rect rect) {
    SDL_Rect s_rect;
    s_rect.x = rect.getCorner(TOP_LEFT).x;
    s_rect.y = rect.getCorner(TOP_LEFT).y;
    s_rect.w = rect.size.x * 2;
    s_rect.h = rect.size.y * 2;
    SDL_RenderFillRect(renderer, &s_rect);
}

void Renderer::setColor(int r, int g, int b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
}