/**gameobject.h
 * An entity to provide:
 * - Absolute position from the origin of the game world.
 * - Size of the object, relative to its position.
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "rect.h"
#include "gameobjectaction.h"
#include "gameobjectmovebyaction.h"

typedef unsigned int id_t;
typedef GameObjectAction Action;

class GameObject {
    id_t id;
    Rect rect;

public:
    const Point &pos;
    const Point &size;

    Action *action;

    GameObject(id_t _id);
    GameObject(id_t _id, int x, int y, int x_size, int y_size);
    
    ~GameObject();

    // Moves the centerpoint of this rect and returns the new center Point.
    void moveBy(float x, float y);
    void moveBy(const Point &p);

    void scheduleMoveBy(Point p);
};

#endif