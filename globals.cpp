#include "globals.hpp"
#include <cstddef>

size_t red = -1;
size_t green = -1;
size_t comparisons = 0;
int pause_duration = 200;
std::string algorithm = "selection";
bool theoryFlag = 0;
std::vector<bool> isIndexSorted;
std::pair<int, int> blueIndex = {-1,-1};
int prefixFlag = 0;