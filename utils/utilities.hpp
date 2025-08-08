#pragma once

#include "../globals.hpp"
#include "../cli/greeter.hpp"
#include <iostream>
#include <vector>

void printArr(std::vector<int32_t> &v);
void printSymbol(size_t indexSelected, char ch, std::vector<int32_t> &v);
void swap(int32_t &x, int32_t &y);
void runAnimation(size_t currentIndex, size_t startIndex, std::vector<int32_t> &v);
void pause(int timeInMilliseconds);
void clear();
void resetGlobals();
void runCustomAnimation(size_t currentIndex, size_t startIndex, std::vector<int32_t> &v, char symbol);
void printStorage(std::vector<std::vector<int32_t>> storage);