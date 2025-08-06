#include "techniques.hpp"

void selectionSort(std::vector<int32_t> &v)
{
  for (size_t i = 0; i < v.size() - 1; i++)
  {
    int32_t min = v[i]; // Initialize min to the first element of unsorted portion
    red = i;
    green = i;
    size_t minIndex = i;
    for (size_t j = i; j < v.size(); j++)
    {
      runAnimation(min, minIndex, j, i, v);
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
        runAnimation(min, minIndex, j, i, v);
        clear();
      }
    }
    runAnimation(min, minIndex, v.size() - 1, i, v);
    clear();
    if (i != minIndex )
    {
      swap(v[i], v[minIndex]);
      runAnimation(min, minIndex, v.size() - 1, i, v);
      if(i!=(v.size()-2)) clear();
    }
  }
  green = -1;
  red = -1;
}