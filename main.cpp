#include "utils/utilities.hpp"
#include "globals.hpp"
#include "techniques/techniques.hpp"
#include "cli/greeter.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <algorithm>" << std::endl;
    std::cerr << "Available algorithms: selection, insertion, bubble, quick, merge, heap" << std::endl;
    return 1;
  }

  algorithm = argv[1];

  size_t n;
  int32_t max = 0;
  greeter();
  std::cout << "Enter the value of n: ";
  std::cin >> n;
  std::vector<int32_t> v(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> v[i];
    if (abs(v[i]) > max)
    {
      max = abs(v[i]);
      if (v[i] < 0)
        max++;
    }
  }
  isIndexSorted.assign(n, 0);
  clear();
  int maxLength = (max == 0) ? 1 : std::log10(max) + 1;
  std::cout << "\033[?25l"; // Hide cursor

  // Call the appropriate sorting algorithm
  if (algorithm == "selection")
  {
    selectionSort(v);
  }
  else if (algorithm == "insertion")
  {
    insertionSort(v);
  }
  else if (algorithm == "bubble")
  {
    bubbleSort(v);
  }
  else if (algorithm == "merge")
  {
    // mergeSort(v); // TODO: Implement merge sort
    std::cerr << "Merge sort not yet implemented" << std::endl;
    return 1;
  }
  else if (algorithm == "quick")
  {
    // quickSort(v); // TODO: Implement quick sort
    std::cerr << "Quick sort not yet implemented" << std::endl;
    return 1;
  }
  else
  {
    std::cerr << "Unknown algorithm: " << algorithm << std::endl;
    std::cerr << "Available algorithms: selection, insertion, bubble, merge, quick" << std::endl;
    return 1;
  }
  resetGlobals();
  std::cout << "press any key to return to menu...\n";
  return 0;
}