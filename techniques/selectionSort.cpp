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
      std::cout << "\033[2J\033[1;1H"; // Clears screen and moves cursor to top-left
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
        std::cout << "\033[2J\033[1;1H"; // Clears screen and moves cursor to top-left
      }
    }
    runAnimation(min, minIndex, v.size() - 1, i, v);
    if (i != minIndex)
    {
      // std::cout
      //     << '[' << v[i] << ']' << " <-> " << '[' << v[minIndex] << ']' << std::endl;
      std::cout << "\033[2J\033[1;1H"; // Clears screen and moves cursor to top-left
      swap(v[i], v[minIndex]);
      int temp;
      temp = red;
      red = green;
      green = temp;
      runAnimation(min, minIndex, v.size() - 1, i, v);
    }
    pause(800);
    std::cout << "\033[2J\033[1;1H"; // Clears screen and moves cursor to top-left
  }
  green = -1;
  red = -1;
}