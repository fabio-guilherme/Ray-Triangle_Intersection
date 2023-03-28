#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Vector3D.hpp"

class Triangle {
public:
    Triangle(Vector3D v0, Vector3D v1, Vector3D v2);
    Vector3D vertex0;
    Vector3D vertex1;
    Vector3D vertex2;
};

#endif // TRIANGLE_HPP

