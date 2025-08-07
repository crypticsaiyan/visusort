#pragma once

#include <cstddef>
#include <string>
#include <vector>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define CLEAR "\033[2J\033[1;1H\033[3J"

extern size_t red;
extern size_t green;
extern size_t comparisons;
extern int pause_duration;
extern std::string algorithm;
extern std::vector<bool> isIndexSorted;