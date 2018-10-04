/**rect.h
 * A rectangle with a center point and a horizontal and vertical size.
 */

#ifndef RECT_H
#define RECT_H

#include "point.h"
#include "log.h"
#include <cassert>

#define Pos Point
#define Size Point

// num_t is a signed integer or floating-point type.
class Rect {
public:
    enum Corner {
        TOP_RIGHT,
        TOP_LEFT,
        BOTTOM_LEFT,
        BOTTOM_RIGHT
    };

    Pos pos;
    // size.x and size.y are the horizontal and vertical size, respectively.
    Size size;

    Rect(): Rect(Pos(0, 0), Size(0, 0)) { }
    Rect(Pos _pos, Size _size): pos(_pos), size(_size) {
        assert(size >= 0);
    }

    Rect(Pos pos, float h_size, float v_size):
        Rect(pos, Size(h_size, v_size)) { }

    Rect(const Rect &r) {
        pos = r.pos;
        size = r.size;
    }

    Rect &operator= (const Rect &r) {
        pos = r.pos;
        size = r.size;
        return *this;
    }

    Pos moveTo(Pos new_pos) {
        pos = new_pos;
        return pos;
    }

    Pos moveBy(Pos new_pos) {
        pos += new_pos;
        return pos;
    }

    Point *getAllCorners() {
        Point *points = new Point[4];
        points[0] = getCorner(TOP_RIGHT);
        points[1] = getCorner(TOP_LEFT);
        points[2] = getCorner(BOTTOM_LEFT);
        points[3] = getCorner(BOTTOM_RIGHT);
        return points;
    }

    Point getCorner(Corner c) {
        switch (c) {
            case TOP_RIGHT:
                return pos + size;
            case TOP_LEFT:
                return pos + size.inverseX();
            case BOTTOM_LEFT:
                return pos + size.inverse();
            case BOTTOM_RIGHT:
                return pos + size.inverseY();
            default:
                lprintf("Error: invalid corner %d.\n", c);
                return Point();
        }
    }
};

#endif