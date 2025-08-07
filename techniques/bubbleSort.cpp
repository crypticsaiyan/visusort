#include "techniques.hpp"

void bubbleSort(std::vector<int32_t> &v)
{
  bool swapped;
  for (size_t i = 0; i < v.size() - 1; i++)
  {
    swapped = false;
    green = 0;
    red = -1;
    runAnimation(0, 0, v);
    for (size_t j = 0; j < v.size() - i - 1; j++)
    {
      red = -1;
      green = j + 1;
      comparisons++;
      clear();
      runAnimation(j + 1, j, v);
      if (v[j + 1] < v[j])
      {
        clear();
        red = j;
        runAnimation(j + 1, j, v);
        clear();
        swap(v[j + 1], v[j]);
        swapped = true;
        runAnimation(j, j + 1, v);
      }
    }
    isIndexSorted[v.size() - i - 1] = 1;
    clear();
    if (!swapped || (i == v.size() - 2))
    {
      isIndexSorted.assign(isIndexSorted.size(), 1);
      runCustomAnimation(i, 0, v, ' ');
      resetGlobals();
      break;
    }
  }
}