#include "techniques.hpp"

void selectionSort(std::vector<int32_t> &v)
{
  for (size_t i = 0; i < v.size() - 1; i++)
  {
    int32_t min = v[i]; // Initialize min to the first element of unsorted portion
    red = i;
    green = i;
    size_t minIndex = i;
    runAnimation(i, i, v);
    clear();
    for (size_t j = i + 1; j < v.size(); j++)
    {
      comparisons++;
      runAnimation(j, i, v);
      clear();
      bool changed = 0;
      if (v[j] < min)
      {
        min = v[j];
        minIndex = j;
        changed = 1;
        green = j;
      }
      if (changed)
      {
        runAnimation(j, i, v);
        clear();
      }
    }
    runAnimation(v.size() - 1, i, v);
    if (i != minIndex)
    {
      clear();
      swap(v[i], v[minIndex]);
      runAnimation(v.size() - 1, i, v);
    }
    isIndexSorted[i] = 1;
    clear();
    if (i == v.size() - 2)
    {
      isIndexSorted.assign(isIndexSorted.size(), 1);
      runAnimation(0, 0, v);
      resetGlobals();
      break;
    }
  }
}