#pragma once
#include <iostream>


class Vector3d
{
private:
    float x;
    float y;
    float z;
public:
    Vector3d();
    Vector3d(float x, float y, float z);
    ~Vector3d();
    Vector3d crossProduct(const Vector3d& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Vector3d& vector);

};
