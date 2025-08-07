#include "techniques.hpp"

size_t partition(std::vector<int32_t> &v, size_t low, size_t high)
{
  blueIndex = {low, high};
  int32_t pivot = v[high];
  ssize_t i = static_cast<ssize_t>(low) - 1;
  // Skip initial animation when i is -1
  clear();
  red = -1;
  green = -1;
  for (size_t j = low; j < high; j++)
  {
    red = -1;
    green = -1;
    comparisons++;
    runAnimation(j, high, v);
    clear();
    if (v[j] < pivot)
    {
      i++;
      if (static_cast<size_t>(i) != j)
      {
        red = static_cast<size_t>(i);
        green = j;
        runCustomAnimation(j, static_cast<size_t>(i), v, '.');
        clear();
        swap(v[static_cast<size_t>(i)], v[j]);
        runCustomAnimation(static_cast<size_t>(i), j, v, '.');
        clear();
      }
    }
  }

  if (static_cast<size_t>(i + 1) != high && v[static_cast<size_t>(i + 1)] != v[high])
  {
    red = static_cast<size_t>(i + 1);
    green = high;
    runAnimation(high, static_cast<size_t>(i + 1), v);
    clear();
    swap(v[static_cast<size_t>(i + 1)], v[high]);
    runAnimation(static_cast<size_t>(i + 1), high, v);
    clear();
  }
  isIndexSorted[static_cast<size_t>(i + 1)] = 1;
  blueIndex = {-1, -1};
  return static_cast<size_t>(i + 1);
}

void quickSortHelper(std::vector<int32_t> &v, size_t low, size_t high)
{
  if (low < high)
  {
    size_t pi = partition(v, low, high);

    if (pi > 0)
      quickSortHelper(v, low, pi - 1);
    quickSortHelper(v, pi + 1, high);
  }
  else if (low == high)
  {
    // Single element is already sorted
    isIndexSorted[low] = 1;
  }
}

void quickSort(std::vector<int32_t> &v)
{
  if (!v.empty())
  {
    quickSortHelper(v, 0, v.size() - 1);
    // Mark all elements as sorted at the end
    for (size_t i = 0; i < v.size(); i++)
    {
      isIndexSorted[i] = 1;
    }
  }
  runCustomAnimation(0, 0, v, ' ');
  resetGlobals();
}