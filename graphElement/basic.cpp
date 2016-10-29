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

bool Circle::has_point(const Point &p) const {
    double dst2 = sq(p.x - c.x) + sq(p.y - c.y);
    bool hasPtn = sq(radius - thickness) <= dst2;
    hasPtn = hasPtn && dst2 <= sq(radius + thickness);
    return hasPtn;
}
