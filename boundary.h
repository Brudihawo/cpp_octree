#pragma once
 
#include "point.h"

class Boundary {
    private:
        Point m_min;
        Point m_max;

    public:
        Boundary(Point min, Point max);
        ~Boundary();

        bool Contains(Point p);
        Point GetRadii();
        inline Point GetMin() { return m_min; }
        inline Point GetMax() { return m_max; }
};