#include "vector2d.h"

int main()
{
    // Creating vectors
    Vector2d vector1;
    Vector2d vector2(2.0f, 3.0f);

    std::cout << "Initial Vectors:" << std::endl;
    std::cout << "vector1: " << vector1 << std::endl;
    std::cout << "vector2: " << vector2 << std::endl;

    // Copying vector2 to vector1
    vector1 = vector2;
    
    std::cout << "Vectors after copying vector2 to vector1:" << std::endl;
    std::cout << "vector1: " << vector1 << std::endl;
    std::cout << "vector2: " << vector2 << std::endl;
    
    // Creating vector3 and adding vector1 to it
    Vector2d vector3;
    vector3 += vector1;
    
    std::cout << "Vectors after adding vector1 to vector3:" << std::endl;
    std::cout << "vector1: " << vector1 << std::endl;
    std::cout << "vector3: " << vector3 << std::endl;

    // Creating vector4 and assigning the sum of vector3 and vector2 to it
    Vector2d vector4;
    vector4 = vector3 + vector2;

    std::cout << "Resultant Vector (vector3 + vector2):" << std::endl;
    std::cout << "vector4: " << vector4 << std::endl;

    // Printing the length of vector1
    std::cout << "Length of vector1: " << vector1() << std::endl;
    std::cout << "Printing values of vector4:" << std::endl << "vector4: " << vector4 << std::endl;
    std::cout << "Index 0: ";
    std::cout << vector4[0];
    std::cout << std::endl;
    std::cout << "Index 1: ";
    std::cout << vector4[1];
    std::cout << std::endl;
    std::cout << "Index 2: ";
    std::cout << vector4[2];
    std::cout << std::endl;
    Vector2d testVec{1.2f, 5.6f};
    std::cout << "Printing vector: "<< testVec << std::endl;
    Vector2d testVec2;
    std::cout << "Enter vector coordinates (x y): ";
    std::cin >> testVec;

    std::cout << "Entered vector: " << testVec << std::endl;
    std::cout << "Number of instances: " << Vector2d::get_num_of_instances() << std::endl;


}
