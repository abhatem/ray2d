#include "LineEquation.h"


LineEquation::LineEquation(double a, double b, double c):
    a(a), b(b), c(c)
{
    
}

LineEquation::LineEquation(const Point &start, const Point &end)
{
    if(end.x - start.x == 0) {

        
        a = 0;
        b = -1;
        c = start.x;
        return ;
        
    }


    a = -1;
    b = (end.y -start.y) / (end.x - start.x);
    c = start.y - b * start.x;
    
}

// LineEquation::LineEquation(const PointLine &pl)
// {
//     m = (pl.end.y - pl.start.y) / (pl.end.x - pl.start.x);
// }
