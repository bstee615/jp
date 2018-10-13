/**point.h
 * A pair of two numbers, with some utilities to aid mathematical operations.
 * Can act as a vector as well.
 */

#ifndef POINT_H
#define POINT_H
#include <cmath>
#include "log.h"

// float is a signed integer or floating-point type.
class Point {
    Point plus(const Point &p) {
        return Point(x + p.x, y + p.y);
    }
    
    Point minus(const Point &p) {
        return Point(x - p.x, y - p.y);
    }
    
    Point times(const int &scalar) {
        return Point(x * scalar, y * scalar);
    }
    
    Point times(const Point &p) {
        return Point(x * p.x, y * p.y);
    }
    
    Point div(const int &scalar) {
        if (scalar == 0) lprintf("div by 0.\n");
        return Point(x / scalar, y / scalar);
    }
    
    Point div(const Point &p) {
        if (p.x == 0 || p.y == 0) lprintf("div by 0.\n");
        return Point(x / p.x, y / p.y);
    }
    
    Point mod(const int &modScalar) {
        return Point((int)x % modScalar, (int)y % modScalar);
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

    Point operator* (const Point &p) {
        return times(p);
    }

    Point operator* (const int &scalar) {
        return times(scalar);
    }

    Point operator/ (const Point &p) {
        return div(p);
    }

    Point operator/ (const int &scalar) {
        return div(scalar);
    }

    Point operator% (const int &modScalar) {
        return mod(modScalar);
    }

    bool operator>= (const int scalar) {
        return x >= scalar && y >= scalar;
    }

    bool operator== (const Point &p) {
        return x == p.x && y == p.y;
    }

    Point inverseX() {
        return Point(-x, y);
    }

    Point inverseY() {
        return Point(x, -y);
    }

    Point inverse() {
        return Point(-x, -y);
    }

    Point floor() {
        return Point((int)x, (int)y);
    }

    Point abs() {
        return Point(std::abs(x), std::abs(y));
    }

    float magnitude() {
        return std::sqrt(x * x + y * y);
    }

    Point normalized() {
        return div(magnitude());
    }
};

#endif