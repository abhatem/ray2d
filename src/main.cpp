#include "Ray.h"

#include <iostream>

int main()
{
    // cast ray on single polygon
    Polygon polygon;
    
    polygon.setPoints(std::vector<Point> {Point(0, 0), Point(3, 3), Point(3, 0)});

    Ray r(Point(0.5, 0.5), Point(1, 0));
    RayHit rh = r.cast(polygon);
    std::cout << "cast ray on single polygon ans see result: " << std::endl;
    std::cout << "did it hit: " <<  rh.hit << std::endl;
    std::cout << "# of hits: " << rh.numHits << std::endl;
    std::cout << "# pointer to hit polygon: " << rh.hitPolygon << std::endl;
    // check if a point is inside a polygon
    std::cout << "is point inside polygon: " <<
	polygon.isPointInside(Point(1, 2)) << std::endl;

    // check if a point is inside bounding box of polygon
    std::cout << "is point inside bounding box of polygon: " <<
	polygon.getBox().isPointInside(Point(1, 2)) << std::endl;
    
    
    // cast ray on vector of polygons
    std::vector<Polygon> polygons;
    polygons.push_back(Polygon(std::vector<Point> {Point(0, 0), Point(3, 3), Point(3, 0)}));
    polygons.push_back(Polygon(std::vector<Point> {Point(0, 0), Point(7.28, 819.2), Point(7, 7)}));
    polygons.push_back(Polygon(std::vector<Point> {Point(6, 0), Point(6, 10), Point(10, 0)}));
    
    std::vector<RayHit> rhs = r.cast(polygons);

    int numAllHits = 0;
    
    for(auto it: rhs) {
	numAllHits += it.numHits;
    }
    std::cout << std::endl << "cast ray on multiple polygons: " << std::endl;
    std::cout << "# of hit polygons: " << rhs.size() << std::endl;
    std::cout << "# of hits: " << numAllHits << std::endl;
    std::cout << "hit polygons ids(pointers): ";;
    for(auto it : rhs) {
	std::cout << it.hitPolygon << " ";
    }

    std::cout << std::endl;


    
    return 0;
}
