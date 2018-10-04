/**gameobject.h
 * An entity to provide:
 * - Absolute position from the origin of the game world.
 * - Size of the object, relative to its position.
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "rect.h"

typedef unsigned int id_t;

class GameObject {
    id_t id;
    Rect rect;
public:
    const Point &pos;
    const Point &size;

    GameObject(id_t _id);
    GameObject(id_t _id, int x, int y, int x_size, int y_size);

    // Moves the centerpoint of this rect and returns the new center Point.
    void moveBy(float x, float y);
    void moveBy(Point p);
};

#endif