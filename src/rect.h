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

    Rect &operator= (Rect &r) {
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

    bool contains(Point p) {
        Point bottom_right = pos + size;
        return !(p.x < pos.x ||
                p.y < pos.y ||
                p.x >= bottom_right.x ||
                p.y >= bottom_right.y);
    }

    bool contains(Rect r) {
        return contains(r.pos) && // top left
            contains(r.pos + r.size.zeroX()) && // bottom left
            contains(r.pos + r.size.zeroY()) && // top right
            contains(r.pos + r.size); // bottom right
    }

    Point correction(Point p) {
        Point bottom_right = pos + size;

        Point ret;
        if (p.x < pos.x) {
            ret.x = pos.x - p.x;
        }
        else if (p.x > bottom_right.x) {
            ret.x = bottom_right.x - p.x;
        }

        if (p.y < pos.y) {
            ret.y = pos.y - p.y;
        }
        else if (p.y > bottom_right.y) {
            ret.y = bottom_right.y - p.y;
        }

        return ret;
    }

    Point correction(Rect r) {
        Point correction;
        if (contains(r.pos)) { // top left
            correction = pos + size - r.pos;
        }
        if (contains(r.pos + r.size.zeroX())) { // bottom left
            correction = pos + size.zeroY() - r.pos + r.size.zeroX();
        }
        if (contains(r.pos + r.size.zeroY())) { // top right
            correction = pos + size.zeroX() - r.pos + r.size.zeroY();
        }
        if (contains(r.pos + r.size)) { // bottom right
            correction = pos - r.pos + r.size;
        }

        return correction;
    }
};

#endif
