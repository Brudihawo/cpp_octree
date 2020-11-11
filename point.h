#pragma once

#include <string>

class Point {
    public:
        float m_x;
        float m_y;
        float m_z;
    
        Point(float x, float y, float z);
        ~Point();

        Point operator+(Point other);
        Point operator-(Point other);
        bool operator>(Point other);
        bool operator<(Point other);
        bool operator==(Point other);
        bool operator<=(Point other);
        bool operator>=(Point other);

        std::string ToString();
};