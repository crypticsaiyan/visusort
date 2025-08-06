#include "techniques.hpp"

void insertionSort(std::vector<int32_t> &v)
{
  for (size_t i = 1; i < v.size(); i++)
  {
    green = i;
    red = -1;
    runAnimation(i, i, v);
    size_t j = i;
    while (j > 0 && v[j] < v[j - 1])
    {
      comparisons++;
      red = j - 1;
      clear();
      runAnimation(j - 1, j, v);
      clear();
      swap(v[j], v[j - 1]);
      runAnimation(j, j - 1, v);
      j--;
    }
    if (i != v.size() - 1)
      clear();
  }
  red = -1;
  green = -1;
  comparisons = 0;
}