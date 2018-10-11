#ifndef GAMEOBJECTMOVETOACTION_H
#define GAMEOBJECTMOVETOACTION_H

#include "point.h"
#include "gameobject.h"
#include "gameobjectaction.h"

class GameObjectMoveToAction: public GameObjectAction {
    GameObject *obj;
    const Point p;

public:
    GameObjectMoveToAction(GameObject *_obj, Point _p):
        GameObjectAction(MOVE), obj(_obj), p(_p) { }

    void execute() {
        obj->moveTo(p);
    }
};

#endif