#include <iostream>



int main()

{

    std::cout << "I love C++!" << std::endl;

    std::cout << std::endl;



    int heightOfTriangle = 5;

    int b;

    for (int i = 0; i < heightOfTriangle; i++)

    {

        int b = i;

        while (b > -1)

        {

            std::cout << "*";

            b--;

        }

        std::cout << std::endl;

     }

}

