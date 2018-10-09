#ifndef GAMEOBJECTMOVEACTION_H
#define GAMEOBJECTMOVEACTION_H

#include "point.h"
#include "gameobject.h"
#include "gameobjectaction.h"

class GameObjectMoveByAction: public GameObjectAction {
    GameObject *obj;
    const Point p;

public:
    GameObjectMoveByAction(GameObject *_obj, Point _p);

    void execute();
};

#endif