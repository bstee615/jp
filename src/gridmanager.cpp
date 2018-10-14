#include "gridmanager.h"

GridManager::GridManager(int size, const Rect &boundsRect):
    grid_size(Point(size, size)), gridBoundsRect(boundsRect)
{

}

Point GridManager::correctObjectToGrid(Point p) {
    Rect rect = gridBoundsRect;
    return (p / grid_size).floor()
            * grid_size
            - (grid_size)
            + rect.getCorner(TOP_LEFT);
}