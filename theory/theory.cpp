#include "theory.hpp"
#include "../globals.hpp"
#include <iostream>
#include <iomanip>

void displayTheory(const std::string &algorithm)
{
  if (algorithm == "selection")
  {
    selectionSortTheory();
  }
  else if (algorithm == "insertion")
  {
    insertionSortTheory();
  }
  else if (algorithm == "bubble")
  {
    bubbleSortTheory();
  }
  else if (algorithm == "heap")
  {
    heapSortTheory();
  }
  else if (algorithm == "quick")
  {
    quickSortTheory();
  }
  else if (algorithm == "merge")
  {
    mergeSortTheory();
  }
  else if (algorithm == "counting")
  {
    countingSortTheory();
  }
  else
  {
    std::cout << "Theory not available for algorithm: " << algorithm << std::endl;
  }
}

void selectionSortTheory()
{
  std::cout << BLUE << "========== SELECTION SORT ==========" << RESET << std::endl;
  std::cout << "Finds minimum element and swaps with first, repeats for remaining array." << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Time Complexity:" << RESET << std::endl;
  std::cout << "Best/Average/Worst: " << "O(n²)" << std::endl;
  std::cout << BLUE << "Space Complexity:" << RESET << " O(1)" << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Properties:" << RESET << std::endl;
  std::cout << "In-place: " << BLUE << "Yes" << RESET << " | Stable: " << BLUE << "No" << RESET << " | Adaptive: " << BLUE << "No" << RESET << std::endl;
  std::cout << std::endl;
}

void insertionSortTheory()
{
  std::cout << BLUE << "========== INSERTION SORT ==========" << RESET << std::endl;
  std::cout << "Builds sorted array one element at a time by inserting each element into correct position." << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Time Complexity:" << RESET << std::endl;
  std::cout << "Best: " <<   "O(n)"   << " | Average/Worst: " <<   "O(n²)" << std::endl;
  std::cout << BLUE << "Space Complexity:" << RESET << " O(1)" << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Properties:" << RESET << std::endl;
  std::cout << "In-place: " << BLUE << "Yes" << RESET << " | Stable: " << BLUE << "Yes" << RESET << " | Adaptive: " << BLUE << "Yes" << RESET << std::endl;
  std::cout << std::endl;
}

void bubbleSortTheory()
{
  std::cout << BLUE << "========== BUBBLE SORT ==========" << RESET << std::endl;
  std::cout << "Repeatedly compares adjacent elements and swaps if wrong order. Largest 'bubbles' to end." << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Time Complexity:" << RESET << std::endl;
  std::cout << "Best: " <<  "O(n)" <<  " | Average/Worst: "  << "O(n²)"  << std::endl;
  std::cout << BLUE << "Space Complexity:" << RESET << " O(1)" << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Properties:" << RESET << std::endl;
  std::cout << "In-place: " << BLUE << "Yes" << RESET << " | Stable: " << BLUE << "Yes" << RESET << " | Adaptive: " << BLUE << "Yes" << RESET << std::endl;
  std::cout << std::endl;
}

void heapSortTheory()
{
  std::cout << BLUE << "========== HEAP SORT ==========" << RESET << std::endl;
  std::cout << "Uses binary heap structure. Builds max heap, then repeatedly extracts maximum." << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Time Complexity:" << RESET << std::endl;
  std::cout << "Best/Average/Worst: "  << "O(n log n)"  << std::endl;
  std::cout << BLUE << "Space Complexity:" << RESET << " O(1)" << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Properties:" << RESET << std::endl;
  std::cout << "In-place: " << BLUE << "Yes" << RESET << " | Stable: " << BLUE << "No" << RESET << " | Adaptive: " << BLUE << "No" << RESET << std::endl;
  std::cout << std::endl;
}

void quickSortTheory()
{
  std::cout << BLUE << "========== QUICK SORT ==========" << RESET << std::endl;
  std::cout << "Divide-and-conquer: picks pivot, partitions around it, recursively sorts sub-arrays." << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Time Complexity:" << RESET << std::endl;
  std::cout << "Best/Average: "  << "O(n log n)"  << " | Worst: "  << "O(n²)"  << std::endl;
  std::cout << BLUE << "Space Complexity:" << RESET << " O(log n) average, O(n) worst" << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Properties:" << RESET << std::endl;
  std::cout << "In-place: " << BLUE << "Yes" << RESET << " | Stable: " << BLUE << "No" << RESET << " | Adaptive: " << BLUE << "No" << RESET << std::endl;
  std::cout << std::endl;
}

void mergeSortTheory()
{
  std::cout << BLUE << "========== MERGE SORT ==========" << RESET << std::endl;
  std::cout << "Divide-and-conquer: divides array in half, recursively sorts, then merges sorted halves." << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Time Complexity:" << RESET << std::endl;
  std::cout << "Best/Average/Worst: "  << "O(n log n)"  << std::endl;
  std::cout << BLUE << "Space Complexity:" << RESET << " O(n)" << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Properties:" << RESET << std::endl;
  std::cout << "In-place: " << BLUE << "No" << RESET << " | Stable: " << BLUE << "Yes" << RESET << " | Adaptive: " << BLUE << "No" << RESET << std::endl;
  std::cout << std::endl;
}

void countingSortTheory()
{
  std::cout << BLUE << "========== COUNTING SORT ==========" << RESET << std::endl;
  std::cout << "Non-comparison sort. Counts occurrences of each value, then places elements in order." << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Time Complexity:" << RESET << std::endl;
  std::cout << "Best/Average/Worst: " << "O(n + k)"  << " where k = range of input" << std::endl;
  std::cout << BLUE << "Space Complexity:" << RESET << " O(k)" << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Properties:" << RESET << std::endl;
  std::cout << "In-place: " << BLUE << "No" << RESET << " | Stable: " << BLUE << "Yes" << RESET << " | Adaptive: " << BLUE << "No" << RESET << std::endl;
  std::cout << std::endl;

  std::cout << BLUE << "Best for:" << RESET << " Small range integers, when k ≤ n" << std::endl;
  std::cout << std::endl;
}
