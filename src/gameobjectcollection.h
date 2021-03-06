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
    DISAPPEAR =     (1 << 0),
    CONSTRAIN =     (1 << 1),
    GRID =          (1 << 2),
    NOCONSTRAINT =  (0)
};

class GameObjectCollection {
    std::unordered_map<id_t, GameObject*> objects;
    
    int x, y, w, h;

    id_t g_id; // GameObject id

    GameObjectConstraintPolicy policy;
    void applyPolicy(GameObject *obj);
    void applyAction(GameObject *obj);

public:
    Rect boundsRect;

    GameObjectCollection(int _x, int _y, int _w, int _h);

    GameObject *addGameObject(int x, int y, int w, int h);
    void updateGrid();

    bool isObjectInsideBounds(GameObject *obj);
    
    void setPolicy(int _policy);

    GameObject *findObjectAtPoint(Point p);
};

#endif