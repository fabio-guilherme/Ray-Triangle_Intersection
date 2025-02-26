#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

class Vector3D {
public:
    Vector3D(float x, float y, float z);
    float getX() const;
    float getY() const;
    float getZ() const;
    float length() const;
    void normalize();
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(float scalar) const;
    float dotProduct(const Vector3D& other) const;
    Vector3D crossProduct(const Vector3D& other) const;
private:
    float x_;
    float y_;
    float z_;
};

#endif // VECTOR3D_HPP