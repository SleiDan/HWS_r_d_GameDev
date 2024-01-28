#include "vector2d.h"

int Vector2d::numOfInstances = 0;

Vector2d::Vector2d()
    : x(0.0f), y(0.0f){
    numOfInstances++;
}

// Parameterized constructor
Vector2d::Vector2d(float x, float y)
    : x(x), y(y) {    
    numOfInstances++;
}

Vector2d::~Vector2d()
{
    numOfInstances--;
}

Vector2d& Vector2d::operator=(const Vector2d& other)
{
    if(this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2d& Vector2d::operator+=(const Vector2d& secondVector)
{
    x += secondVector.x;
    y += secondVector.y;
    return *this;
}

Vector2d& Vector2d::operator-=(const Vector2d& secondVector)
{
    x -= secondVector.x;
    y -= secondVector.y;
    return *this;
}

float Vector2d::operator()()
{
    return std::sqrt(this->x * this->x + this->y * this->y);
}

float& Vector2d::operator[](int i)
{
    try {
        if(i == 0) return x;
        else if(i == 1) return y;
        else {
            throw std::out_of_range("Index out of range in Vector2d");
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Error in operator[]: " << e.what() << std::endl << "So using first value: ";
        return x;
    }
}

int Vector2d::get_num_of_instances()
{
    return numOfInstances;
}

std::ostream& operator<<(std::ostream& os, const Vector2d& vector)
{
    os << "{" << vector.x << "; " << vector.y << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2d& vec) {
    is >> vec.x >> vec.y;
    return is;
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector)
{
    Vector2d left_vector(leftVector);
    return left_vector += rightVector;
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector)
{
    Vector2d left_vector(leftVector);
    return left_vector -= rightVector;
}
