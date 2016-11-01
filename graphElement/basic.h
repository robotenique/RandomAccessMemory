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

class Group: public GraphicalElement {
    struct Node {
        GraphicalElement *c;
        Node *next;
    };
    Node *head;
public:
    Group(): head(0){}
    Group(const Group &other);
    ~Group();
    void add(const GraphicalElement &e);
    GraphicalElement *clone() const {
        return new Group(*this);
    }
    bool has_point(const Point &p);
    Rect boundingBox() const;
};

class Segment: public GraphicalElement {
    Point a,b;
    double thickness;
public:
    Segment(const Point &a, const Point &b, double thickness)
        :a(a), b(b), thickness(thickness) {}
    GraphicalElement *clone() const {
        return new Segment(*this);
    }
    bool has_point(const Point &p) const;
    Rect boundingBox() const;
};

#endif
