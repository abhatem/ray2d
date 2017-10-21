#include "BoundingBox.h"


BoundingBox::BoundingBox(double x, double y, double w, double h):
    x(x), y(y), w(w), h(h)
{
    
}

bool BoundingBox::collidesWith(const BoundingBox &o)
{
    if(x > o.x + o.w) return false;
    if(y > o.y+o.h) return false;
    if(o.x > x + w) return false;
    if(o.y > y + h) return false;

    return true;
}


bool BoundingBox::isPointInside(const Point &p)
{
    if(p.x > x + w || p.x < x) return false;
    if(p.y < y || p.y > y + h) return false;

    return true;
    
}
