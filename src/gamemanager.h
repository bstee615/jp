/** gamemanager.h
 * A container to hold instances of GameObject in an arbitrary rectangle.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <unordered_map>
#include <vector>
#include "gameobject.h"

class GameManager {
    std::unordered_map<id_t, GameObject*> objects;
    
    std::vector<GameObject*> x_axis;
    std::vector<GameObject*> y_axis;
    int x, y, w, h;

    id_t g_id;

public:
    GameManager(int _x, int _y, int _w, int _h);

    GameObject *addGameObject(int x, int y, int w, int h);
    void updateGrid();
    void updateObjectPosition(GameObject obj);
};

#endif