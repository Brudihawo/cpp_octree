#include "boundary.h"
#include "point.h"

// Boundary::Boundary(Boundary& b) {
//     m_min = Point(b.m_min);
//     m_max = Point(b.m_max);
// }

Boundary::Boundary(Point min, Point max): m_min(min), m_max(max) {
    float tmp;
    if (m_min.m_z > m_max.m_z) {
        tmp = m_min.m_z;
        m_min.m_z = m_max.m_z;
        m_max.m_z = tmp;
    }
    if (m_min.m_y > m_max.m_y) {
        tmp = m_min.m_y;
        m_min.m_y = m_max.m_y;
        m_max.m_y = tmp;
    }
    if (m_min.m_x > m_max.m_x) {
        tmp = m_min.m_x;
        m_min.m_x = m_max.m_x;
        m_max.m_x = tmp;
    }
}

Boundary::~Boundary() {   
}

bool Boundary::Contains(Point p) {
    return p < m_max && p >= m_min;
}

Point Boundary::GetRadii() {
    return m_max - m_min;
}