#include "utilities.hpp"
#include "../cli/greeter.hpp"

void runAnimation(size_t currentIndex, size_t startIndex, std::vector<int32_t> &v)
{
  greeter();
  printSymbol(startIndex, '*', v);
  printArr(v);
  printSymbol(currentIndex, '^', v);
  pause(pause_duration);
}