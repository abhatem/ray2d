#include "Ray.h"
#include "PointLine.h"
#include "Util.h"



Ray::Ray(const Point &origin, const Point &dir):
    PointLine(origin, origin + dir)
{
    Ray::dir = dir/dir.mag();
    // start = origin;
    // end = origin + dir;

}

std::vector<RayHit> Ray::cast(std::vector<Polygon*> polygons)
{
    std::vector<RayHit> rhs;
    
    for(unsigned int i = 0; i < polygons.size(); ++i) {
        RayHit rh = cast(*polygons[i]);
        if(rh.hit) {
            rhs.push_back(rh);
        }
        
    }
    return rhs;
}

std::vector<RayHit> Ray::cast(const std::vector<Polygon> &polygons)
{
    std::vector<RayHit> rhs;
    
    for(unsigned int i = 0; i < polygons.size(); ++i) {
        RayHit rh = cast(polygons[i]);
        if(rh.hit) {
            rhs.push_back(rh);
        }
        
    }
    return rhs;
}

RayHit Ray::cast(const Polygon &polygon)
{
    std::vector<Point> points;
    std::vector<Point> ip = polygon.getPoints();

    for(unsigned int i = 0; i < ip.size(); ++i) {
        points.push_back(Point(ip[i].x, ip[i].y));
        
    }
    

    
    RayHit rh;
    rh.hit = false;
    rh.hitPolygon = &polygon;
    rh.numHits = 0;
    


    RayHit rm;
    rm.hit = false;
    rm.hitPolygon = nullptr;
    rm.numHits = 0;
    
    for(unsigned int i = 0; i < points.size(); ++i) {
        Point *p;
        
        if(i != points.size()-1) 
            p = intersectsLine(PointLine(points[i], points[i+1]));
        else
            p = intersectsLine(PointLine(points[i], points[0]));
        
        
        if(!p) continue;
	// cout << "hello world" << endl;
        Point top = *p-start;
        if(top.norm() == dir.norm()){
	    rh.hitPolygon = &polygon;
            rh.numHits++;        
            // return rh;
        }

        delete p;
    }
    if(rh.numHits > 0) {
        rh.hit = true;
        return rh;
    }
    
    
    return rm;
}

// cv::Point Ray::getOrigin() const{return start;}
// void Ray::setOrigin(cv::Point origin){ start = origin;}

// cv::Point Ray::getDir() const{return end;}
// void Ray::setDir(cv::Point dir){ end = dir;}

// void Ray::calc()
// {
//     // m = (m_dir.y - m_origin.y) / (m_dir.x - m_origin.x);
//     // b = m_origin.y - m * m_origin.x;
    
// }

Point* Ray::intersectsLine(const PointLine &pl)
{
    LineEquation le1 = getLineEquation();
    LineEquation le2 = pl.getLineEquation();

    if(le1.b == le2.b) return nullptr;
    
    double nom;
    double x;
    double y;
    if(le1.b != 0) {
        double nom1 = (le2.b*le1.c/le1.b);
        double nom2 = -le1.c;
        nom = nom1 + nom2;

        double denom1 = le2.a;
        double denom2 = - (le2.b * le1.a / le1.b);
        double denom = denom1 + denom2;
    
        
        if(denom == 0) y = start.y;
        else y = nom / denom;
        
        x = (-le1.c - (le1.a * y))/ le1.b;
    } else {
        y = -le1.c / le1.a;
        x = (-le2.c + (le2.a * le1.c / le1.a)) / le2.b;
            
    }
    
    Point *p = new Point(x, y);
    using namespace Util;
    double eps = 0.00001;
    if(std::abs(distance(pl.start, *p) + distance(*p, pl.end) - distance(pl.start, pl.end)) < eps) return p;

    return nullptr;
}

// LineEquation Ray::calcLineEquation() const
// {
    
//     return PointLine::calcLineEquation()
// }
