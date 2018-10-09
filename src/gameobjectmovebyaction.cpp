#include "gameobjectmovebyaction.h"

GameObjectMoveByAction::GameObjectMoveByAction(GameObject *_obj, Point _p):
    GameObjectAction(MOVE), obj(_obj), p(_p) { }

void GameObjectMoveByAction::execute() {
    obj->moveBy(p);
}