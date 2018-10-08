#include "gamemanager.h"

GameManager::GameManager(int _x, int _y, int _w, int _h):
    objects(std::unordered_map<id_t, GameObject*>()),
    x_axis(std::vector<GameObject*>()),
    y_axis(std::vector<GameObject*>()),
    x(_x), y(_y), w(_w), h(_h) {
}

GameObject *GameManager::addGameObject(int x, int y, int x_size, int y_size) {
    id_t current_id = g_id++;
    GameObject *object = new GameObject(current_id, x, y, x_size, y_size);
    objects[current_id] = object;
    return object;
}

void GameManager::updateGrid() {
    for (auto obj : objects) {
        switch (obj->action->type) {
        case MOVE:
            updateObjectPosition(obj);
            break;
        default:
            break;
        }
    }
}

void GameManager::updateObjectPosition(GameObject obj) {
    // Delete & replace obj in x_axis and y_axis.
}