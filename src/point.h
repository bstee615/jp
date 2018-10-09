/**point.h
 * A pair of two numbers, with some utilities to aid mathematical operations.
 * Can act as a vector as well.
 */

#ifndef POINT_H
#define POINT_H

// float is a signed integer or floating-point type.
class Point {
    Point plus(const Point &p) {
        return Point(x + p.x, y + p.y);
    }
    
    Point minus(const Point &p) {
        return Point(x - p.x, y - p.y);
    }
    
    Point div(const int &scalar) {
        return Point(x / scalar, y / scalar);
    }

public:
    float x, y;

    Point(): Point(0, 0) { }
    Point(float _x, float _y): x(_x), y(_y) { }
    Point(const Point &point) {
        x = point.x;
        y = point.y;
    }

    Point &operator= (const Point &p) {
        x = p.x;
        y = p.y;
        return *this;
    }

    Point &operator+= (const Point &p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    Point operator+ (const Point &p) {
        return plus(p);
    }

    Point operator- (const Point &p) {
        return minus(p);
    }

    bool operator>= (const float scalar) {
        return x >= scalar && y >= scalar;
    }

    bool operator== (const Point &p) {
        return x == p.x && y == p.y;
    }

    Point operator/ (const int &scalar) {
        return div(scalar);
    }

    Point inverseX() {
        return Point(-x, y);
    }

    Point inverseY() {
        return Point(-x, y);
    }

    Point inverse() {
        return Point(-x, -y);
    }
};

#endif