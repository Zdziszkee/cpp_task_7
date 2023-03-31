#include <iostream>
#include <vector>
#include "random"

void quickSort(std::vector<int> &integers, int left, int right);


int main() {
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 10000);
    std::vector<int> integers;
    for (int i = 0; i < 10000; ++i) {
        integers.push_back(distrib(gen));
    }
    for (const auto &element: integers) {
        std::cout << element << " ";
    }
    quickSort(integers, 0, integers.size() - 1);
    std::cout << std::endl << "after sort" << std::endl;
    for (const auto &element: integers) {
        std::cout << element << " ";
    }
}


void quickSort(std::vector<int> &integers, int left, int right) {
    int i = left, j = right;
    int pivot = integers[(left + right) / 2];

    while (i <= j) {
        while (integers[i] < pivot) {
            i++;
        }
        while (integers[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(integers[i], integers[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort(integers, left, j);
    }
    if (i < right) {
        quickSort(integers, i, right);
    }
}

