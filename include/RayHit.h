#ifndef RAYHIT_H
#define RAYHIT_H

#include "PointLine.h"
#include "Polygon.h"
class RayHit
{
public:
    RayHit(){};
    virtual ~RayHit(){};
    const Polygon* hitPolygon;
    unsigned int numHits;
    bool hit;
private:	
    
};


#endif /* RAYHIT_H */
