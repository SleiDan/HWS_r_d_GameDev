#include "vector3d.h"

Vector3d::Vector3d()
    : x(0.0f), y(0.0f), z(0.0f) {}

Vector3d::Vector3d(float x, float y, float z)
    : x(x), y(y), z(z) {}

Vector3d::~Vector3d() {}

Vector3d Vector3d::crossProduct(const Vector3d& other) const
{
    float newX = y * other.z - z * other.y;
    float newY = z * other.x - x * other.z;
    float newZ = x * other.y - y * other.x;
    return Vector3d(newX, newY, newZ);
}

std::ostream& operator<<(std::ostream& os, const Vector3d& vector)
{
    os << "{" << vector.x << "; " << vector.y << "; " << vector.z << "}";
    return os;
}
