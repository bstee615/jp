#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H

#include "point.h"
#include "gameobject.h"
#include "gameobjectcollection.h"

class GridManager {
    Point grid_size;
    const Rect &gridBoundsRect;

public:
    GridManager(int _size, const Rect &_boundsRect);

    Point correctPointToGrid(Point p);
};

#endif