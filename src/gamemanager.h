/** gamemanager.h
 * A container to perform bounds checking on instances of GameObject.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "gameobject.h"
#include <vector>

class GameManager {
    std::vector<GameObject*> objects;
    unsigned int g_id;

public:
    GameManager();

    GameObject *addGameObject(int x, int y, int x_size, int y_size);
};

#endif