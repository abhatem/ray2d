#ifndef RAY_H
#define RAY_H
#include "Point.h"
#include "Polygon.h"
#include "RayHit.h"
#include "LineEquation.h"
class Ray : PointLine
{
  public:
    Ray():PointLine(){};
    Ray(const Point &origin, const Point &dir);
    
    virtual ~Ray(){};
    std::vector<RayHit> cast(std::vector<Polygon*> inputPolygons);
    std::vector<RayHit> cast(const std::vector<Polygon> &inputPolygons);
    RayHit cast(const Polygon &polygon);
    Point dir;
    
  private:
    bool intersectsWith(const LineEquation &le);
    Point intersectionPoint(const LineEquation &le);
    Point* intersectsLine(const PointLine &pl);
    
    
};


#endif /* RAY_H */
