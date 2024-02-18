#include <iostream>
#include "vector2d.h"
#include "vector3d.h"

int main() {
    // Vector2d testing
    Vector2d v1(1.0, 2.0);
    Vector2d v2(3.0, 4.0);
    Vector2d v3(1.0, 2.0, 4.0, 6.0);

    std::cout << "Vector v1: " << v1 << std::endl;
    std::cout << "Vector v2: " << v2 << std::endl;
    std::cout << "Vector v3 (constructed from two points): " << v3 << std::endl;

    // Scalar product
    float dotProduct = v1.dotProduct(v2);
    std::cout << "Dot product of v1 and v2: " << dotProduct << std::endl;

    // Negate
    Vector2d negatedV1 = v1.negate();
    std::cout << "Negation of v1: " << negatedV1 << std::endl;

    // Relative state
    VectorRelativeState state = v1.getRelativeState(v2);
    std::cout << "Relative state of v1 and v2: ";
    switch (state) {
    case VectorRelativeState::Identical:
        std::cout << "Identical";
        break;
    case VectorRelativeState::coDirected:
        std::cout << "Co-directed";
        break;
    case VectorRelativeState::OppositeDirected:
        std::cout << "Opposite directed";
        break;
    case VectorRelativeState::AcuteAngle:
        std::cout << "Acute angle";
        break;
    case VectorRelativeState::ObtuseAngle:
        std::cout << "Obtuse angle";
        break;
    case VectorRelativeState::RightAngle:
        std::cout << "Right angle";
        break;
    }
    std::cout << std::endl;

    // Scaling
    v1.scale(2.0, 2.0);
    std::cout << "Scaled v1 by (2, 2): " << v1 << std::endl;

    // Vector3d testing
    Vector3d u(1.0, 2.0, 3.0);
    Vector3d v(4.0, 5.0, 6.0);

    // Cross product
    Vector3d cross = u.crossProduct(v);
    std::cout << "Cross product of u and v: " << cross << std::endl;

    return 0;
}
