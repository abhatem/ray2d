#include "PointLine.h"


PointLine::PointLine(const Point &start, const Point &end):
    start(start), end(end)
{
    calcLineEquation();
    
}

LineEquation PointLine::calcLineEquation() const
{
    if(end.x - start.x == 0) {

        // double a = -1;
        // double b = 0;
        // double c = start.y - b * start.x;
        double a = 0;
        double b = -1;
        double c = start.x;
        
        return LineEquation(a, b, c);
        
    }
    
    double a = -1;
    
    double b = (end.y -start.y) / (end.x - start.x);

    double c = start.y - b * start.x;
    
    return LineEquation(a, b, c);
}




