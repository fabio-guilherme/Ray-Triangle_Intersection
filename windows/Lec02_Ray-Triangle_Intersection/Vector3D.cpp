#include "Vector3D.hpp"
#include <cmath>

Vector3D::Vector3D(float x, float y, float z)
    : x_(x), y_(y), z_(z)
{
}

float Vector3D::getX() const
{
    return x_;
}

float Vector3D::getY() const
{
    return y_;
}

float Vector3D::getZ() const
{
    return z_;
}

void Vector3D::setX(float x) 
{ 
    x_ = x; 
}

void Vector3D::setY(float y) 
{ 
    y_ = y; 
}

void Vector3D::setZ(float z) 
{ 
    z_ = z; 
}

float Vector3D::length() const
{
    return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

void Vector3D::normalize()
{
    float len = length();
    x_ /= len;
    y_ /= len;
    z_ /= len;
}

Vector3D Vector3D::operator+(const Vector3D& other) const
{
    return Vector3D(x_ + other.x_, y_ + other.y_, z_ + other.z_);
}

Vector3D Vector3D::operator-(const Vector3D& other) const
{
    return Vector3D(x_ - other.x_, y_ - other.y_, z_ - other.z_);
}

Vector3D Vector3D::operator*(float scalar) const
{
    return Vector3D(x_ * scalar, y_ * scalar, z_ * scalar);
}

float Vector3D::dotProduct(const Vector3D& other) const
{
    return x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
}

Vector3D Vector3D::crossProduct(const Vector3D& other) const
{
    float x = y_ * other.z_ - z_ * other.y_;
    float y = z_ * other.x_ - x_ * other.z_;
    float z = x_ * other.y_ - y_ * other.x_;
    return Vector3D(x, y, z);
}