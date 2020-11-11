#include "point.h"
#include <string>

Point::Point(float x, float y, float z):m_x(x), m_y(y), m_z(z) {
}

Point::~Point() {    
}

Point Point::operator+(Point other) {
    return Point(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
}

Point Point::operator-(Point other) {
    return Point(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
}

bool Point::operator>(Point other) {
    return m_x > other.m_x && m_y > other.m_y && m_z > other.m_z;
}

bool Point::operator<(Point other) {
    return m_x < other.m_x && m_y < other.m_y && m_z < other.m_z;
}

bool Point::operator==(Point other) {
    return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
}

bool Point::operator<=(Point other) {
    return m_x <= other.m_x && m_y <= other.m_y && m_z <= other.m_z;
}

bool Point::operator>=(Point other) {
    return m_x >= other.m_x && m_y >= other.m_y && m_z >= other.m_z;
}

std::string Point::ToString() {
    char str[26];
    sprintf(str, "Point(%3.2f, %3.2f, %3.2f)", m_x, m_y, m_z);
    return std::string(str);
}