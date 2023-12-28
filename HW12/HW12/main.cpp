#include <iostream>
#include <algorithm>

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

constexpr unsigned int ROWS = 3;
constexpr unsigned int COLUMNS = 3;

enum class SortingDirection
{
    ByRows,
    ByColumns
};

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    int pointerIdx = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            pointerIdx++;
            std::swap(array[pointerIdx], array[j]);
        }
    }

    std::swap(array[pointerIdx + 1], array[high]);

    return (pointerIdx + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int partition_idx = partition(array, low, high);
        quickSort(array, low, partition_idx - 1);
        quickSort(array, partition_idx + 1, high);
    }
}

void sort(int arr[ROWS][COLUMNS], SortingDirection direction)
{
    if (direction == SortingDirection::ByRows)
    {
        for (int i = 0; i < ROWS; ++i)
        {
            quickSort(arr[i], 0, COLUMNS - 1);
        }
    }
    else if (direction == SortingDirection::ByColumns)
    {
        for (int i = 0; i < COLUMNS; ++i)
        {
            int column[ROWS];
            for (int j = 0; j < ROWS; ++j)
            {
                column[j] = arr[j][i];
            }

            quickSort(column, 0, ROWS - 1);

            for (int j = 0; j < ROWS; ++j)
            {
                arr[j][i] = column[j];
            }
        }
    }
}

int main()
{
    int array[] = {5, 1, 9, 7, 3};
    int size = sizeof(array) / sizeof(array[0]);

    bubbleSort(array, size);
    std::cout << std::endl;

    std::cout << "Sorted array using Bubble Sort: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    int array2D[ROWS][COLUMNS] = {
        {1, 5, 4},
        {3, 8, 6},
        {9, 5, 1}};

    sort(array2D, SortingDirection::ByRows);

    std::cout << "Sorted 2D array by rows: " << std::endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            std::cout << array2D[i][j] << " ";
        }
        std::cout << std::endl;
    }

    sort(array2D, SortingDirection::ByColumns);

    std::cout << "Sorted 2D array by columns: " << std::endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            std::cout << array2D[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
