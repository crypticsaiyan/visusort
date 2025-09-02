#include "utils/utilities.hpp"
#include "globals.hpp"
#include "techniques/techniques.hpp"
#include "cli/greeter.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <limits>
#include <cctype>
#include <stdexcept>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cerr << "Usage: " << argv[0] << " <algorithm> <displayTheory>" << std::endl;
    std::cerr << "Available algorithms: selection, insertion, bubble, quick, merge, heap, counting" << std::endl;
    return 1;
  }

  algorithm = argv[1];
  theoryFlag = (std::string(argv[2]) == "1");

  size_t n;
  int32_t max = 0;
  greeter();
  
  // Get array size with error handling
  while (true) {
    std::cout << "Enter the length of test array (positive integer > 1): ";
    std::string input;
    std::getline(std::cin, input);
    
    // Remove leading/trailing whitespace
    input.erase(0, input.find_first_not_of(" \t"));
    input.erase(input.find_last_not_of(" \t") + 1);
    
    // Check if input is empty
    if (input.empty()) {
      std::cout << "Error: No input provided. Please enter a positive integer greater than 1.\n";
      continue;
    }
    
    // Check if input contains only digits
    bool isValidNumber = true;
    for (char c : input) {
      if (!std::isdigit(c)) {
        isValidNumber = false;
        break;
      }
    }
    
    if (!isValidNumber) {
      std::cout << "Error: Invalid input '" << input << "'. Please enter only positive integers.\n";
      continue;
    }
    
    // Convert to size_t and check range
    try {
      n = std::stoull(input);
      if (n < 2) {
        std::cout << "Error: Array size must be greater than 1. You entered: " << n << "\n";
        continue;
      }
      if (n > 1000) {
        std::cout << "Warning: Large array size (" << n << ") may cause slow visualization. Continue? (y/n): ";
        std::string confirm;
        std::getline(std::cin, confirm);
        if (confirm != "y" && confirm != "Y" && confirm != "yes" && confirm != "Yes") {
          continue;
        }
      }
      break;
    } catch (const std::exception& e) {
      std::cout << "Error: Number too large. Please enter a smaller positive integer.\n";
      continue;
    }
  }
  
  std::cout << "Enter the values separated by spaces: ";
  std::vector<int32_t> v(n);
  
  // Get array values with error handling
  for (size_t i = 0; i < n; i++)
  {
    while (true) {
      if (std::cin >> v[i]) {
        break;
      } else {
        std::cout << "Invalid input! Please enter an integer for position " << (i + 1) << ": ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }
    
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
  else if (algorithm == "heap")
  {
    heapSort(v);
  }
  else if (algorithm == "quick")
  {
    quickSort(v);
  }
  else if (algorithm == "merge")
  {
    mergeSort(v);
  }
  else if (algorithm == "counting")
  {
    countingSort(v);
  }
  else
  {
    std::cerr << "Unknown algorithm: " << algorithm << std::endl;
    std::cerr << "Available algorithms: selection, insertion, bubble, merge, quick, counting" << std::endl;
    return 1;
  }
  resetGlobals();
  std::cout << "press any key to return to menu...\n";
  return 0;
}