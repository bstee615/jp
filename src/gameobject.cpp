#include "gameobject.h"

GameObject::GameObject(unsigned int id): GameObject(id, 0, 0, 0, 0) { }

GameObject::GameObject(unsigned int id, int x, int y, int x_size, int y_size) {
    rect = Rect(Point(x, y), Point(x_size, y_size));
    id = id;
}