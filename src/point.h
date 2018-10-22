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

    Point &operator= (Point p) {
        x = p.x;
        y = p.y;
        return *this;
    }

    Point &operator+= (Point p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    Point operator+ (const Point &p) const {
        return Point(*this).plus(p);
    }

    Point operator- (const Point &p) const {
        return Point(*this).minus(p);
    }

    Point operator* (const Point &p) const {
        return Point(*this).times(p);
    }

    Point operator* (const int &scalar) const {
        return Point(*this).times(scalar);
    }

    Point operator/ (const Point &p) const {
        return Point(*this).div(p);
    }

    Point operator/ (const int &scalar) const {
        return Point(*this).div(scalar);
    }

    Point operator% (const int &modScalar) const {
        return Point(*this).mod(modScalar);
    }

    bool operator>= (const int scalar) const {
        return x >= scalar && y >= scalar;
    }

    bool operator== (const Point &p) const {
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

    Point zeroX() {
        return Point(0, y);
    }

    Point zeroY() {
        return Point(x, 0);
    }
};

#endif
