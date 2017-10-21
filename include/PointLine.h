#ifndef POINTLINE_H
#define POINTLINE_H
#include "LineEquation.h"
class PointLine
{
  public:
    PointLine(): start(0, 0), end(0, 0)
    {
    }
    
    PointLine(const Point &start, const Point &end );
    virtual ~PointLine()
    {
    }




    LineEquation getLineEquation() const
    {
        return calcLineEquation();
    }

    Point start;
    Point end;
  private:
    

  protected:
    LineEquation calcLineEquation() const;
};


#endif /* POINTLINE_H */
