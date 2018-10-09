#ifndef GAMEOBJECTACTION_H
#define GAMEOBJECTACTION_H

enum ActionType {
    MOVE,
    NOOP
};

class GameObjectAction {
protected:
    GameObjectAction(ActionType _type): type(_type) { }

public:
    const ActionType type;
    GameObjectAction();
    virtual ~GameObjectAction();

    virtual void execute();
};

#endif