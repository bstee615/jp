/**gameobject.h
 * An entity to provide:
 * - Absolute position from the origin of the game world.
 * - Size of the object, relative to its position.
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "rect.h"

class GameObject {
    unsigned int id;
public:
    Rect rect;

    GameObject(unsigned int _id);
    GameObject(unsigned int _id, int x, int y, int x_size, int y_size);
};

#endif