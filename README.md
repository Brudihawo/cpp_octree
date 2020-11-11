# cpp_octree
Octree Implementation in C++

Contains Boundary, Point and OcTreeNode classes

---

## Minimal Example
```c++
Point lower_boundary(0.0f, 0.0f, 0.0f);
Point upper_boundary(1.0f, 1.0f, 1.0f);

OcTreeNode<8> tree(low_boundary, high_boundary);

for (int i = 0; i < 20; i++) {
    tree.AddPoint(Point(randfloat(0.0f, 1.0f),
                        randfloat(0.0f, 1.0f), 
                        randfloat(0.0f, 1.0f));
}
```
A tree will add subnodes (subdivide) if its capacity is reached. Currently, added Points will be tried to be inserted into all subnodes (nodes will skip the actual insertion process if they are not inside the nodes' boundary).