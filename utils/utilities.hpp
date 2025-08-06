#pragma once

#include "../globals.hpp"
#include <iostream>
#include <vector>

void printArr(std::vector<int32_t> &v);
void printSymbol(size_t indexSelected, char ch, std::vector<int32_t> &v);
void swap(int32_t &x, int32_t &y);
void runAnimation(int32_t min, size_t minIndex, size_t currentIndex, size_t startIndex, std::vector<int32_t> &v);
void pause(int timeInMilliseconds);
void clear();