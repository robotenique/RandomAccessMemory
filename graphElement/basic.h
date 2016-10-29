#ifndef __BASIC_H__
#define __BASIC_H__
#include "graphel.h"
class Circle: public GraphicalElement{
    Point c;
    double radius;
    double thickness;
public:
    Circle(const Point &c, double radius, double thickness)
        : c(c), radius(radius), thickness(thickness) {}
    GraphicalElement * clone() const {
        return new Circle(*this);
    }
    bool has_point(const Point &p) const;
    Rect boundingBox() const;
};

#endif
