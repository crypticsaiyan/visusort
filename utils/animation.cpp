#include "utilities.hpp"

void runAnimation(size_t currentIndex, size_t startIndex, std::vector<int32_t> &v)
{
  greeter();
  printSymbol(startIndex, '*', v);
  printArr(v);
  printSymbol(currentIndex, '^', v);
  pause(pause_duration);
}

void runCustomAnimation(size_t currentIndex, size_t startIndex, std::vector<int32_t> &v, char symbol)
{
  greeter();
  printSymbol(startIndex, symbol, v);
  printArr(v);
  printSymbol(currentIndex, symbol, v);
  pause(pause_duration);
}
