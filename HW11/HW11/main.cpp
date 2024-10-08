#include <iostream>

constexpr unsigned int ROWS = 4;
constexpr unsigned int COLUMNS = 6;

bool find(int arr_2d[ROWS][COLUMNS], int toFind)
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (arr_2d[i][j] == toFind) {
                return true;
            }
        }
    }
    return false;
}

enum class SortingDirection
{
    Ascending,
    Descending
};

bool isSorted(const int* arr, int size, SortingDirection direction)
{
    if (size <= 1) {
        return true;
    }

    if (direction == SortingDirection::Ascending) {
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
    } else if (direction == SortingDirection::Descending) {
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }
    }

    return true;
}

void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
    for (int col = COLUMNS - 1; col >= 0; --col) {
        for (int row = 0; row < ROWS; ++row) {
            std::cout << arr_2d[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
    for (int row = ROWS - 1; row >= 0; --row) {
        if ((ROWS - 1 - row) % 2 == 0) {
            // Print from left to right for even rows
            for (int col = 0; col < COLUMNS; ++col) {
                std::cout << arr_2d[row][col] << " ";
            }
        } else {
            // Print from right to left for odd rows
            for (int col = COLUMNS - 1; col >= 0; --col) {
                std::cout << arr_2d[row][col] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int arr_2d[ROWS][COLUMNS] = {
        {11, 12, 13, 14, 15, 16},
        {21, 22, 23, 24, 25, 26},
        {31, 32, 33, 34, 35, 36},
        {41, 42, 43, 44, 45, 46}
    };

    std::cout << find(arr_2d, 24) << std::endl;
    std::cout << std::endl;

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};
    int arr3[] = {1, 2, 5, 4, 3};
    int arr4[] = {1};

    std::cout << "Ascending - " << std::boolalpha << isSorted(arr1, std::size(arr1), SortingDirection::Ascending) << ", ";
    std::cout << "Descending - " << std::boolalpha << isSorted(arr1, std::size(arr1), SortingDirection::Descending) << std::endl;

    std::cout << "Ascending - " << std::boolalpha << isSorted(arr2, std::size(arr2), SortingDirection::Ascending) << ", ";
    std::cout << "Descending - " << std::boolalpha << isSorted(arr2, std::size(arr2), SortingDirection::Descending) << std::endl;

    std::cout << "Ascending - " << std::boolalpha << isSorted(arr3, std::size(arr3), SortingDirection::Ascending) << ", ";
    std::cout << "Descending - " << std::boolalpha << isSorted(arr3, std::size(arr3), SortingDirection::Descending) << std::endl;

    std::cout << "Ascending - " << std::boolalpha << isSorted(arr4, std::size(arr4), SortingDirection::Ascending) << ", ";
    std::cout << "Descending - " << std::boolalpha << isSorted(arr4, std::size(arr4), SortingDirection::Descending) << std::endl;
    std::cout << std::endl;

    std::cout << "Traverse Top Down Right Left By Columns   :" << std::endl;
    traverseTopDownRightLeftByColumns(arr_2d);

    std::cout << "Traverse Left Right Down Top Switching By Rows:" << std::endl;
    traverseLeftRightDownTopSwitchingByRows(arr_2d);

    return 0;
}
