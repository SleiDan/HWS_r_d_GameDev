#pragma once
#include <iostream>
#include <cmath>


class Vector2d
{
private:
    float x;
    float y;
    static int numOfInstances;
public:
    Vector2d();
    Vector2d(float x, float y);
    ~Vector2d();
    Vector2d& operator=(const Vector2d& other);
    Vector2d& operator+=(const Vector2d& secondVector);
    Vector2d& operator-=(const Vector2d& secondVector);
    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);
    float operator()();
    float& operator[](int i);
    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector);
    friend std::istream& operator>>(std::istream& is, Vector2d& vec);
    static int get_num_of_instances();
};

