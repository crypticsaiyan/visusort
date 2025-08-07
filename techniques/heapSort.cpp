#include "techniques.hpp"
#include "../cli/greeter.hpp"

bool showAni = 1;

void heapify(std::vector<int32_t> &v, size_t n, size_t i)
{
  size_t largest = i;
  size_t left = 2 * i + 1;
  size_t right = 2 * i + 2;
  showAni = 1;

  green = i;
  red = -1;
  runAnimation(i, i, v);
  clear();

  if (left < n)
  {
    runAnimation(left, i, v);
    clear();
    comparisons++;
    if (v[left] > v[largest])
    {
      largest = left;
      red = left;
    }
  }

  if (right < n)
  {
    runAnimation(right, i, v);
    clear();
    comparisons++;
    if (v[right] > v[largest])
    {
      largest = right;
      red = right;
    }
  }

  if (largest != i)
  {
    runAnimation(largest, i, v);
    clear();
    swap(v[i], v[largest]);
    runAnimation(i, largest, v);
    clear();
    heapify(v, n, largest);
  }
  else
    showAni = 0;
}

void heapSort(std::vector<int32_t> &v)
{
  size_t n = v.size();

  // build max-heap
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(v, n, i);
  }

  // std::cout << "Heapifying done";
  // pause(5000);

  for (size_t i = n - 1; i > 0; i--)
  {
    green = i;
    if (showAni)
    {
      runAnimation(i, i, v);
      clear();
    }
    red = 0;
    runCustomAnimation(i, 0, v, '.');
    clear();
    swap(v[0], v[i]);
    runCustomAnimation(i, 0, v, '.');
    clear();
    isIndexSorted[i] = 1;
    heapify(v, i, 0);
  }
  isIndexSorted.assign(isIndexSorted.size(), 1);
  runAnimation(0, 0, v);
  resetGlobals();
  resetGlobals();
}