#include "gameobjectcollection.h"

#define CHECKPOLICY(bitset, policy) ((bitset & policy) != 0)

GameObjectCollection::GameObjectCollection(int _x, int _y, int _w, int _h):
    objects(std::unordered_map<id_t, GameObject*>()),
    x(_x), y(_y), w(_w), h(_h),
    policy(GameObjectConstraintPolicy(GameObjectConstraintPolicy::CONSTRAIN)),
    boundsRect(Rect(_x + _w/2, _y + _h/2, _w/2, _h/2)) { }

GameObject *GameObjectCollection::addGameObject(int x, int y, int x_size, int y_size) {
    id_t current_id = g_id++;
    GameObject *object = new GameObject(current_id, x, y, x_size, y_size);
    objects[current_id] = object;
    applyPolicy(object);
    return object;
}

void GameObjectCollection::updateGrid() {
    for (auto pair : objects) {
        GameObject *obj = pair.second;
        if (obj->action != nullptr) {
            switch (obj->action->type) {
            case MOVE:
                applyAction(obj);
                applyPolicy(obj);
                break;
            default:
                break;
            }
        }
    }
}

void GameObjectCollection::applyAction(GameObject *obj) {
    obj->action->execute();
    delete obj->action;
    obj->action = nullptr;
}

void GameObjectCollection::applyPolicy(GameObject *obj) {
    if ((GameObjectConstraintPolicy)policy == GameObjectConstraintPolicy::NOCONSTRAINT) {
        return;
    }
    if (CHECKPOLICY(policy, GameObjectConstraintPolicy::CONSTRAIN)) {
        Rect r = boundsRect;
        Point pos = obj->pos;
        Point correction = r.correction(pos);
        if (!isPointInsideBounds(pos)) {
            obj->moveBy(correction);
            // obj->moveBy(correction.normalized() * size);
        }
    }
    if (CHECKPOLICY(policy, GameObjectConstraintPolicy::DISAPPEAR)) {
        if (isObjectInsideBounds(obj)) {
            obj->show();
        }
        else {
            obj->hide();
        }
    }
}

void GameObjectCollection::setPolicy(int _policy) {
    policy = GameObjectConstraintPolicy(_policy);
}

bool GameObjectCollection::isPointInsideBounds(Point p) {
    // lprintf("(%f, %f)\n", p.x, p.y);
    // lprintf("(%f, %f, %f, %f)\n", boundsRect.pos.x, boundsRect.pos.y, boundsRect.size.x, boundsRect.size.y);
    Rect r = boundsRect;
    return r.contains(p);
}

bool GameObjectCollection::isObjectInsideBounds(GameObject *obj) {
    return isPointInsideBounds(obj->pos);
}

GameObject *GameObjectCollection::findObjectAtPoint(Point p) {
    for (auto pair : objects) {
        GameObject *obj = pair.second;
        Point size = obj->size;
        if (Rect(obj->pos, size/2).contains(p)) {
            return obj;
        }
    }
    return nullptr;
}