#pragma once

#include "../globals.hpp"
#include "../utils/utilities.hpp"
#include <vector>
#include <cstdint>

void selectionSort(std::vector<int32_t> &v);
void insertionSort(std::vector<int32_t> &v);
void bubbleSort(std::vector<int32_t> &v);
void heapSort(std::vector<int32_t> &v);
void quickSort(std::vector<int32_t> &v);
void mergeSort(std::vector<int32_t> &v);
void countingSort(std::vector<int32_t> &v);