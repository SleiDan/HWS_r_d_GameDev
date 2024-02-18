#include "vector2d.h"

int Vector2d::numOfInstances = 0;

Vector2d::Vector2d(float x, float y)
    : x(x), y(y) {    
    numOfInstances++;
}

Vector2d::Vector2d(float x0, float y0, float x1, float y1)
    : x(x1 - x0), y(y1 - y0) {
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

float Vector2d::operator()() const
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

float Vector2d::dotProduct(Vector2d& other) const
{
    return (x * other.x) + (y * other.y);
}

Vector2d Vector2d::negate() const
{
    return Vector2d(-x, -y);
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const
{
    float dot = this->dotProduct(const_cast<Vector2d&>(other));
    float thisMagnitude = (*this)();
    float otherMagnitude = other();
    float angleCos = dot / (thisMagnitude * otherMagnitude);

    if (angleCos == 1)
        return VectorRelativeState::Identical;
    else if (angleCos == -1)
        return VectorRelativeState::OppositeDirected;
    else if (angleCos == 0)
        return VectorRelativeState::RightAngle;
    else if (angleCos > 0)
        return VectorRelativeState::AcuteAngle;
    else
        return VectorRelativeState::ObtuseAngle;
}

void Vector2d::scale(float factorX, float factorY)
{
    x *= factorX;
    y *= factorY;
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
