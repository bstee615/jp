#include "gamemanager.h"

GameManager::GameManager() {
    objects = std::unordered_map<id_t, GameObject*>();
}

GameObject *GameManager::addGameObject(int x, int y, int x_size, int y_size) {
    id_t current_id = g_id++;
    GameObject *object = new GameObject(current_id, x, y, x_size, y_size);
    objects[current_id] = object;
    return object;
}