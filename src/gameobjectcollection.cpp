#include "gameobjectcollection.h"

GameObjectCollection::GameObjectCollection(int _x, int _y, int _w, int _h):
    objects(std::unordered_map<id_t, GameObject*>()),
    x_axis(std::vector<GameObject*>(_w, nullptr)),
    y_axis(std::vector<GameObject*>(_h, nullptr)),
    x(_x), y(_y), boundsRect(Rect(_x + _w/2, _y + _h/2, _w/2, _h/2)),
    policy(GameObjectConstraintPolicy::CONSTRAIN) { }

GameObject *GameObjectCollection::addGameObject(int x, int y, int x_size, int y_size) {
    id_t current_id = g_id++;
    GameObject *object = new GameObject(current_id, x, y, x_size, y_size);
    objects[current_id] = object;
    applyPolicy(object);
    setObjectAtPosition(Point(x, y), object);
    return object;
}

void GameObjectCollection::updateGrid() {
    for (auto pair : objects) {
        GameObject *obj = pair.second;
        switch (obj->action->type) {
        case MOVE:
            updateObjectPosition(obj);
            break;
        default:
            break;
        }
    }
}

void GameObjectCollection::updateObjectPosition(GameObject *obj) {
    if (isObjectInsideBounds(obj)) {
        setObjectAtPosition(obj->pos, nullptr);
    }
    obj->action->execute();
    applyPolicy(obj);
    if (isObjectInsideBounds(obj)) {
        setObjectAtPosition(obj->pos, obj);
    }
}

void GameObjectCollection::applyPolicy(GameObject *obj) {
    switch (policy) {
    case CONSTRAIN:
        obj->moveBy(boundsRect.correction(obj->pos));
        break;
    case DISAPPEAR:
        if (isObjectInsideBounds(obj)) {
            obj->show();
        }
        else {
            obj->hide();
        }
        break;
    default:
        break;
    }
}

void GameObjectCollection::setPolicy(GameObjectConstraintPolicy _policy) {
    policy = _policy;
}

void GameObjectCollection::setObjectAtPosition(Point p, GameObject *obj) {
    x_axis.at(p.x - getX()) = obj;
    y_axis.at(p.y - getY()) = obj;
}

bool GameObjectCollection::isPointInsideBounds(Point p) {
    // lprintf("(%f, %f)\n", p.x, p.y);
    // lprintf("(%f, %f, %f, %f)\n", boundsRect.pos.x, boundsRect.pos.y, boundsRect.size.x, boundsRect.size.y);
    return boundsRect.contains(p);
}

bool GameObjectCollection::isObjectInsideBounds(GameObject *obj) {
    return isPointInsideBounds(obj->pos);
}
