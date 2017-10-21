#ifndef ISLAND_H
#define ISLAND_H

#include "Point.h"
#include "BoundingBox.h"
#include <vector>
class Polygon
{
  public:
    Polygon();
    Polygon(std::vector<Point> points);
    // Island(std::vector<cv::Point> points);
    virtual ~Polygon(){};
    std::vector<Point> getPoints() const{return m_points;}
    void setPoints(std::vector<Point> points){ m_points = points; calculateCenter(); calculateBoundingBox();}

    // void setPoints(std::vector<cv::Point> points);

    Point getCenter() const{return m_center;}
    void calculateCenter();
    
    double getArea();
    
    double getArchLength();

    void sortCCW();
    void sortCW();
    
    BoundingBox getBox() const{return m_box;}

    void calculateBoundingBox();
    
    bool isPointInside(const Point &p);
    
  private:
    static bool lessX(const Point &p1, const Point &p2);
    static bool lessY(const Point &p1, const Point &p2);
    
    std::vector<Point> m_points;
    Point m_center;
    BoundingBox m_box;
    
    
};

#endif /* ISLAND_H */
