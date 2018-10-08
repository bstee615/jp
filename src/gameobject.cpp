#include "gameobject.h"

GameObject::GameObject(unsigned int _id, int x, int y, int x_size, int y_size):
    action(new GameObjectAction()), id(_id), rect(Rect(Point(x, y), Point(x_size, y_size))), pos(rect.pos), size(rect.size) { }

GameObject::GameObject(unsigned int id): GameObject(id, 0, 0, 0, 0) { }

GameObject::~GameObject() {
    delete action;
}

void GameObject::moveBy(float x, float y) {
    rect.pos = rect.pos + Point(x, y);
}
void GameObject::moveBy(const Point &p) {
    rect.pos += p;
}

void GameObject::scheduleMoveBy(Point p) {
    delete action;
    action = new GameObjectMoveByAction(this, p);
}