#include "basic.h"
inline double sq(double x) {return x*x;}
Rect Circle::boundingBox() const {
    Rect bb;
    bb.llc.x = c.x - radius - thickness;
    bb.llc.y = c.y - radius - thickness;
    bb.urc.x = c.x + radius + thickness;
    bb.urc.y = c.x + radius + thickness;
    return bb;
}

bool Circle::has_point(const Point& p) const {
    double dst2 = sq(p.x - c.x) + sq(p.y - c.y);
    bool hasPtn = sq(radius - thickness) <= dst2;
    hasPtn = hasPtn && dst2 <= sq(radius + thickness);
    return hasPtn;
}

void Group::add(const GraphicalElement& e) {
    Node *c = new Node;
    c->e = e.clone();
    c->next = head;
    head = e;
}

Group::Group(const Group& other)
    :head(0) {
        for (Node *c = other.head; c; c = c->next)
            add(*c->e);
    }


Group::~Group() {
    for(Node *tmp, c = *head; c; c=tmp) {
        tmp = c->next;
        delete c->e;
        delete c;
    }
}

bool Group::has_point(const Point& p) const {
    for(Node *c = head; c; c = c->next)
        if(c->e->has_point(p))
            return true;
    return false;
}

Rect Group::boundingBox() const {
    Rect bb, aux;
    Node *c = head;
    if(c) {
        bb = c->e->boundingBox(); //Can I do this?
    }

    for(Node *c = head; c; c = c->next) {
        aux = c->e->boundingBox();
        if(aux.llc.x < bb.llc.x)
            bb.llc.x = aux.llc.x;
        if(aux.llc.y < bb.llc.y)
            bb.llc.y = aux.llc.y;
        if(aux.urc.x > bb.urc.x)
            bb.urc.x = aux.urc.x;
        if(aux.urc.x > bb.urc.x)
            bb.urc.y = aux.urc.y;
    }
    return bb;
}
