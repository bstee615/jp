#include "gamemanager.h"

GameManager::GameManager() {
    objects = std::vector<GameObject *>();
}

GameObject *GameManager::addGameObject(int x, int y, int x_size, int y_size) {
    GameObject *object = new GameObject(g_id++, x, y, x_size, y_size);
    objects.push_back(object);
    return object;
}