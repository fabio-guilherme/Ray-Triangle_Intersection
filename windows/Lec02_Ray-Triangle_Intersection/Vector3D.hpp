#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

class Vector3D
{
private:
    float x_, y_, z_;

public:
    Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(float x);
    void setY(float y);
    void setZ(float z);

    float length() const;
    void normalize();

    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(float scalar) const;

    float dotProduct(const Vector3D& other) const;
    Vector3D crossProduct(const Vector3D& other) const;
};

#endif // VECTOR3D_HPP