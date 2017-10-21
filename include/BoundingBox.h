#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include "Point.h"
class BoundingBox
{
  public:
    BoundingBox(){};
    BoundingBox( double x, double y, double w, double h );
    virtual ~BoundingBox(){};
    double x, y, w, h;
    bool collidesWith( const BoundingBox &o );
    bool isPointInside( const Point &p );

  private:
};

#endif /* BOUNDINGBOX_H */
