#pragma once

#include <vector>
#include <functional>
#include <iostream>
#include <memory>
#include "SDL2/sdl.h"
#include "point.h"
#include "boundary.h"

template<unsigned int capacity>
class OcTreeNode {
    private:
        std::vector<Point> m_points;
        unsigned int m_n_contained_points;
        
        Boundary* m_boundary;
        std::vector<OcTreeNode<capacity>> m_children;
        bool m_subdivided;

    public:
        OcTreeNode(Point lower, Point upper);
        ~OcTreeNode();

        OcTreeNode<capacity>* GetChild(unsigned int index) const;
        void AddPoint(Point p);

        void Subdivide();
};

template<unsigned int capacity>
OcTreeNode<capacity>::OcTreeNode(Point lower, Point upper): m_n_contained_points(0), m_subdivided(false) {
    m_boundary = new Boundary(lower, upper);
}

template<unsigned int capacity>
OcTreeNode<capacity>::~OcTreeNode() {
}

template<unsigned int capacity>
OcTreeNode<capacity>* OcTreeNode<capacity>::GetChild(unsigned int index) const {
    // Returns child at index 'index', or nullptr if index out of bounds
    if (index < capacity - 1 && m_subdivided)
        return m_children[index];
    else 
        return nullptr;
}

template<unsigned int capacity>
void OcTreeNode<capacity>::AddPoint(Point p) {
    if (m_n_contained_points < capacity) {
        if (m_boundary->Contains(p)) {
            m_points.push_back(p);
            std::cout << "Added " << p.ToString() << " to node with boundary min " << m_boundary->GetMin().ToString() << " and max " << m_boundary->GetMax().ToString() << "." << std::endl;
            m_n_contained_points++;
        }
    } else {
        if (!m_subdivided) {
            Subdivide();
        }
        for (int i = 0; i < 8; i++) {
            m_children[i].AddPoint(p);
        }
    }
}

template<unsigned int capacity>
void OcTreeNode<capacity>::Subdivide() {
    // 1 bit per coordinate: zyx in {0, 1}
    // 000 001 010 011 
    // 100 101 110 111
    float x0 = m_boundary->GetMin().m_x;
    float x1 = m_boundary->GetMax().m_x;
    float y0 = m_boundary->GetMin().m_y;
    float y1 = m_boundary->GetMax().m_y;
    float z0 = m_boundary->GetMin().m_z;
    float z1 = m_boundary->GetMax().m_z;
    float xm = x0 + (x1 - x0) / 2;
    float ym = y0 + (y1 - y0) / 2;
    float zm = z0 + (z1 - z0) / 2; 
    m_children.push_back(OcTreeNode<capacity>(Point(x0, y0, z0), Point(xm, ym, zm))); // 000
    m_children.push_back(OcTreeNode<capacity>(Point(x1, y0, z0), Point(xm, ym, zm))); // 001
    m_children.push_back(OcTreeNode<capacity>(Point(x0, y1, z0), Point(xm, ym, zm))); // 010
    m_children.push_back(OcTreeNode<capacity>(Point(x1, y1, z0), Point(xm, ym, zm))); // 011
    m_children.push_back(OcTreeNode<capacity>(Point(x0, y0, z1), Point(xm, ym, zm))); // 100
    m_children.push_back(OcTreeNode<capacity>(Point(x1, y0, z1), Point(xm, ym, zm))); // 101
    m_children.push_back(OcTreeNode<capacity>(Point(x0, y1, z1), Point(xm, ym, zm))); // 110
    m_children.push_back(OcTreeNode<capacity>(Point(x1, y1, z1), Point(xm, ym, zm))); // 111
    std::cout << "Created Children" << std::endl;
    m_subdivided = true;
}