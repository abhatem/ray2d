#include "Polygon.h"
#include "Util.h"
#include <algorithm>

#include "Ray.h"
#include "RayHit.h"

Polygon::Polygon()
{
}

Polygon::Polygon( std::vector<Point> points )
    : m_points( points )
{
    calculateCenter();
    calculateBoundingBox();
}

void Polygon::sortCCW()
{
    Util::CCWComparator comp( m_center );
    std::sort( m_points.begin(), m_points.end(), comp );
}

void Polygon::sortCW()
{
    Util::CWComparator comp( m_center );
    std::sort( m_points.begin(), m_points.end(), comp );
}



void Polygon::calculateCenter()
{
    double xsum = 0;
    double ysum = 0;

    for ( unsigned int i = 0; i < m_points.size(); i++ ) {
        xsum += m_points[i].x;
        ysum += m_points[i].y;
    }

    m_center.x = xsum / m_points.size();
    m_center.y = ysum / m_points.size();
}

void Polygon::calculateBoundingBox()
{
    typedef std::vector<Point>::iterator iter;

    // unsigned int minx =
    // std::vector<Point>::iterator minxi, maxxi, minyi, maxyi;
    iter xmax = std::max_element( m_points.begin(), m_points.end(), lessX );
    iter xmin = std::min_element( m_points.begin(), m_points.end(), lessX );
    iter ymax = std::max_element( m_points.begin(), m_points.end(), lessY );
    iter ymin = std::min_element( m_points.begin(), m_points.end(), lessY );

    m_box.x = xmin->x;
    m_box.y = ymin->y;
    m_box.w = xmax->x - xmin->x;
    m_box.h = ymax->y - ymin->y;
}


bool Polygon::isPointInside( const Point &p )
{
    Ray r( p, Point( 1, 0 ) );
    RayHit rh = r.cast( *this );
    if ( rh.numHits % 2 ) {
        return true;
    }

    return false;
}

bool Polygon::lessX( const Point &p1, const Point &p2 )
{
    return p1.x < p2.x;
}

bool Polygon::lessY( const Point &p1, const Point &p2 )
{
    return p1.y < p2.y;
}
