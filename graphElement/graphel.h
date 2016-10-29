struct Point {
    double x,y;
    Point(): x(0), y(0){}
    Point(double x, double y)
    :x(x),y(y) {}
};

struct Rect {
    Point llc, urc;
};

class GraphicalElement {
public:
    virtual ~GraphicalElement ();
    virtual GraphicalElement * clone() const = 0; /* Purely virtual function */
    virtual Rect boundingBox() const = 0;
    virtual bool has_point(const Point& p) cont = 0;
};
