/** gamemanager.h
 * A container to hold instances of GameObject in an arbitrary rectangle.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <unordered_map>
#include <vector>
#include "gameobject.h"
#include "point.h"

class GameManager {
    std::unordered_map<id_t, GameObject*> objects;
    
    std::vector<GameObject*> x_axis;
    std::vector<GameObject*> y_axis;
    int x, y;

    id_t g_id;

public:
    GameManager(int _x, int _y, int _w, int _h);

    GameObject *addGameObject(int x, int y, int w, int h);
    void updateGrid();
    void updateObjectPosition(GameObject *obj);

    void setObjectAtPosition(Point p, GameObject *obj);
    bool isInsideBounds(Point p);
    bool isInsideBounds(GameObject *obj);

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getW() {
        return x_axis.size();
    }

    int getH() {
        return y_axis.size();
    }
};

#endif