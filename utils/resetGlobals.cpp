#include "utilities.hpp"

void resetGlobals()
{
  green = -1;
  red = -1;
  comparisons = 0;
  isIndexSorted.assign(isIndexSorted.size(), 0);
  blueIndex = {-1, -1};
  prefixFlag = 0;
}