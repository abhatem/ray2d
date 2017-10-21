#ifndef LINEEQUATION_H
#define LINEEQUATION_H

#include "Point.h"

class LineEquation
{
public:
    LineEquation(){}
    LineEquation(const Point &start, const Point &end);
    LineEquation(double a, double b, double c);
    
    virtual ~LineEquation(){}
    
    double a;
    double b;
    double c;
    
private:	

};


#endif /* EQUATIONLINE_H */
