#ifndef UTIL_H
#define UTIL_H

#include "Point.h"
#include <cmath>
namespace Util
{

    inline bool toRight( const Point &p1, const Point &p2, const Point &c )
    {
        int t = ( p1 - c ).cross( p2 - c );
        if ( t > 0 ) {
            return true;
        } else if ( t < 0 ) {
            return false;
        }

        int t1 = ( p1.x - c.x ) * ( p1.x - c.x ) + ( p1.y - c.y ) * ( p1.y - c.y );
        int t2 = ( p2.x - c.x ) * ( p2.x - c.x ) + ( p2.y - c.y ) * ( p2.y - c.y );

        return t1 < t2;
    }


    class CCWComparator
    {
    public:
        explicit CCWComparator( const Point &center )
            : m_center( center )
        {
        }


        
        bool operator()( const Point &p1, const Point &p2 )
        {
            return toRight( p1, p2, m_center );
        }
      private:
        Point m_center;

    };


    class CWComparator
    {
    public:
        explicit CWComparator( const Point &center )
            : m_center( center )
        {
        }

        
        bool operator()( const Point &p1, const Point &p2 )
        {
            return !toRight( p1, p2, m_center );
        }
      private:
        Point m_center;

    };

    
    inline double distance(const Point &p1, const Point &p2) 
    {
        return sqrt(((p1.x-p2.x)*(p1.x-p2.x)) + (p1.y-p2.y)*(p1.y-p2.y));
        
    }
    

    inline double distanceNoSquare(const Point &p1, const Point &p2)
    {
        return ((p1.x-p2.x)*(p1.x-p2.x)) + (p1.y-p2.y)*(p1.y-p2.y);
    }
    
    


} // Util


#endif /* UTIL_H */
