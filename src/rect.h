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

enum Corner {
    TOP_RIGHT,
    TOP_LEFT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT
};

class Rect {
public:
    Pos pos;
    // size.x and size.y are the horizontal and vertical size, respectively.
    Size size;

    Rect(): Rect(Pos(0, 0), Size(0, 0)) { }
    Rect(Pos _pos, Size _size): pos(_pos), size(_size) {
        assert(size >= 0);
    }

    Rect(Pos pos, int h_size, int v_size):
        Rect(pos, Size(h_size, v_size)) { }

    Rect(int x_pos, int y_pos, int h_size, int v_size):
        Rect(Pos(x_pos, y_pos), Size(h_size, v_size)) { }

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
                return pos + size.inverseY();
            case TOP_LEFT:
                return pos + size.inverse();
            case BOTTOM_LEFT:
                return pos + size.inverseX();
            case BOTTOM_RIGHT:
                return pos + size;
            default:
                lprintf("Error: invalid corner %d.\n", c);
                return Point();
        }
    }
    
    bool contains(Point p) {
        Point top_left = getCorner(TOP_LEFT);
        Point bottom_right = getCorner(BOTTOM_RIGHT);
        return !(p.x < top_left.x ||
                p.y < top_left.y ||
                p.x >= bottom_right.x ||
                p.y >= bottom_right.y);
    }
    
    Point correction(Point p) {
        Point top_left = getCorner(TOP_LEFT);
        Point bottom_right = getCorner(BOTTOM_RIGHT);

        Point ret;
        if (p.x < top_left.x) {
            ret.x = top_left.x - p.x;
        }
        else if (p.x >= bottom_right.x) {
            ret.x = bottom_right.x - p.x;
        }

        if (p.y < top_left.y) {
            ret.y = top_left.y - p.y;
        }
        else if (p.y >= bottom_right.y) {
            ret.y = bottom_right.y - p.y;
        }
        // lprintf("correction: (%f, %f)\n", ret.x, ret.y);

        return ret;
    }

    int getX() { return (pos - size).x; }
    int getY() { return (pos - size).y; }
    int getW() { return (size * 2).x; }
    int getH() { return (size * 2).y; }
};

#endif