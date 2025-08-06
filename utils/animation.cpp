#include "utils.hpp"

void runAnimation(int32_t min, size_t minIndex, size_t currentIndex, size_t startIndex, std::vector<int32_t> &v)
{
  printSymbol(startIndex, '*', v);
  printArr(v);
  printSymbol(currentIndex, '^', v);
  pause(500);
}