#ifndef POINT_H
#define POINT_H
#include <cmath>


#define EPS 0.0000001
class Point
{
    
public:
    
    Point(){}
    Point(double x, double y): x(x), y(y){}
    double x;
    double y;



    double mag() const {
	return sqrt(mag2());
    }

    double mag2() const {
	return x*x + y*y;
    }

    Point norm() {
	double m = mag();
	return Point(x/m, y/m);
    }
    

    double cross(const Point &o) const {
	return x * o.y - y * o.x;
    }
    
    Point operator+ (const Point &o) const {
	return Point(x+o.x, y+o.y);
    }
    
    Point operator- (const Point &o) const {
	return Point(x-o.x, y-o.y);
    }

    Point operator* (double s) const {
	return Point(x*s, y*s);
    }

    Point operator/ (double d) const {
	return Point(x/d, y/d);
    }

    bool operator== (const Point &o) const {
	return std::abs(x-o.x) < EPS && std::abs(y-o.y) < EPS;
    }

};

#endif /* POINT_H */


