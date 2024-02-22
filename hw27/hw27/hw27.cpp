#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <algorithm>

std::mutex mtx; // For synchronization if needed

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void threadedQuickSort(std::vector<int>& arr, int low, int high, int depth) {
    if (low < high) {
        int pi = partition(arr, low, high);

        if (depth > 0) {
            std::thread leftThread(threadedQuickSort, std::ref(arr), low, pi - 1, depth - 1);
            std::thread rightThread(threadedQuickSort, std::ref(arr), pi + 1, high, depth - 1);

            leftThread.join();
            rightThread.join();
        } else {
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
}

int main() {
    std::vector<int> sizes = {10'000, 100'000, 1'000'000, 10'000'000, 100'000'000};
    std::vector<int> threadCounts = {1, 2, static_cast<int>(std::thread::hardware_concurrency()), static_cast<int>(2 * std::thread::hardware_concurrency())};

    for (int size : sizes) {
        std::cout << "Array size: " << size << "\n";

        std::vector<int> baseArray(size);
        std::generate(baseArray.begin(), baseArray.end(), std::rand); // Fill with random numbers

        for (int threadCount : threadCounts) {
            std::vector<int> arr = baseArray; // Copy base array for each sort to ensure fairness

            auto start = std::chrono::high_resolution_clock::now();
            threadedQuickSort(arr, 0, arr.size() - 1, std::log2(threadCount));
            auto finish = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = finish - start;
            std::chrono::duration<double> time_of_1_thread;
            if(threadCount == 1)
            {
                time_of_1_thread = elapsed;
            }
            std::cout << "Threads: " << threadCount << ", Time taken: " << elapsed.count() << " seconds, " << "Boost: " << time_of_1_thread/elapsed << " seconds\n";
        }

        std::cout << std::endl;
    }

    return 0;
}
//Дима - 481 сек
//Ерема - 480 сек
//Даня - 479 сек
