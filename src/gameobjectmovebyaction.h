#ifndef GAMEOBJECTMOVEACTION_H
#define GAMEOBJECTMOVEACTION_H

#include "gameobject.h"
#include "gameobjectaction.h"
#include "point.h"

class GameObjectMoveByAction: public GameObjectAction {
    const GameObject *obj;
    const Point p;

public:
    GameObjectMoveByAction(GameObject *_obj, Point _p): GameObjectAction(MOVE), obj(_obj), p(_p) { }

    void execute() {
        obj->moveBy(p);
    }
};

#endif