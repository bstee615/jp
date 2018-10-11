/** gamemanager.h
 * A container to hold instances of GameObject in an arbitrary rectangle.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <unordered_map>
#include <vector>
#include <algorithm>
#include "log.h"
#include "gameobject.h"
#include "point.h"

enum GameObjectConstraintPolicy {
    DISAPPEAR = (1 << 0),
    CONSTRAIN = (1 << 1),
    GRID =      (1 << 2)
};

class GameObjectCollection {
    std::unordered_map<id_t, GameObject*> objects;
    
    int x, y, w, h;

    id_t g_id; // GameObject id

    GameObjectConstraintPolicy policy;
    void applyPolicy(GameObject *obj);

public:
    const Rect boundsRect;

    GameObjectCollection(int _x, int _y, int _w, int _h);

    GameObject *addGameObject(int x, int y, int w, int h);
    void updateGrid();

    bool isPointInsideBounds(Point p);
    bool isObjectInsideBounds(GameObject *obj);
    
    void setPolicy(int _policy);
};

#endif