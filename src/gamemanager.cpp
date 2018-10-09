#include "gamemanager.h"
#include <algorithm>

GameManager::GameManager(int _x, int _y, int _w, int _h):
    objects(std::unordered_map<id_t, GameObject*>()),
    x_axis(std::vector<GameObject*>(_w, nullptr)),
    y_axis(std::vector<GameObject*>(_h, nullptr)),
    x(_x), y(_y) {
}

GameObject *GameManager::addGameObject(int x, int y, int x_size, int y_size) {
    id_t current_id = g_id++;
    GameObject *object = new GameObject(current_id, x, y, x_size, y_size);
    objects[current_id] = object;
    setObjectAtPosition(Point(x, y), object);
    return object;
}

void GameManager::updateGrid() {
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

void GameManager::updateObjectPosition(GameObject *obj) {
    setObjectAtPosition(obj->pos, nullptr);
    obj->action->execute();
    setObjectAtPosition(obj->pos, obj);
}

void GameManager::setObjectAtPosition(Point p, GameObject *obj) {
    if (!isInsideBounds(p)) {
        return;
    }
    
    x_axis.at(p.x) = obj;
    y_axis.at(p.y) = obj;
}

bool GameManager::isInsideBounds(Point p) {
    bool ret = !(p.x < getX() ||
             p.y < getY() ||
             p.x >= getX() + getW() ||
             p.y >= getY() + getH());

    return ret;
}

bool GameManager::isInsideBounds(GameObject *obj) {
    return std::find(x_axis.begin(), x_axis.end(), obj) != x_axis.end();
}
