#include "utils/utils.hpp"
#include "globals.hpp"
#include "techniques/techniques.hpp"
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
  size_t n;
  int32_t max = 0;
  std::cout << "Enter the value of n: ";
  std::cin >> n;
  std::vector<int32_t> v(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> v[i];
    if (abs(v[i]) > max)
    {
      max = abs(v[i]);
    }
  }
  system("clear");
  int maxLength = (max == 0) ? 1 : std::log10(max) + 1;
  std::cout << "\033[?25l"; // Hide cursor
  selectionSort(v);
  printArr(v);
  std::cout << "\033[?25h"; // Show cursor
  return 0;
}