#include "gameobject.h"

GameObject::GameObject(unsigned int _id, int x, int y, int x_size, int y_size):
    id(_id), rect(Rect(Point(x, y), Point(x_size, y_size))), pos(rect.pos), size(rect.size) { }

GameObject::GameObject(unsigned int id): GameObject(id, 0, 0, 0, 0) { }

void GameObject::moveBy(float x, float y) {
    rect.pos = rect.pos + Point(x, y);
}
void GameObject::moveBy(Point p) {
    rect.pos += p;
}