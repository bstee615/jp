/** gamemanager.h
 * A container to perform bounds checking on instances of GameObject.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <unordered_map>
#include "gameobject.h"

class GameManager {
    std::unordered_map<id_t, GameObject*> objects;
    id_t g_id;

public:
    GameManager();

    GameObject *addGameObject(int x, int y, int x_size, int y_size);
};

#endif