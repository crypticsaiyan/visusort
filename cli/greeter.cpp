#include "greeter.hpp"
#include <iostream>

void greeter()
{
  std::cout << R"(
██╗   ██╗██╗███████╗██╗   ██╗███████╗ ██████╗ ██████╗ ████████╗
██║   ██║██║██╔════╝██║   ██║██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝
██║   ██║██║███████╗██║   ██║███████╗██║   ██║██████╔╝   ██║   
╚██╗ ██╔╝██║╚════██║██║   ██║╚════██║██║   ██║██╔══██╗   ██║   
 ╚████╔╝ ██║███████║╚██████╔╝███████║╚██████╔╝██║  ██║   ██║   
  ╚═══╝  ╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝
)" << "\n";
  if (theoryFlag)
    displayTheory(algorithm);
  if (algorithm == "selection")
    std::cout << BLUE << "\033[1m[Selection Sort]\033[0m" << RESET;
  else if (algorithm == "insertion")
    std::cout << BLUE << "\033[1m[Insertion Sort]\033[0m" << RESET;
  else if (algorithm == "bubble")
    std::cout << BLUE << "\033[1m[Bubble Sort]\033[0m" << RESET;
  else if (algorithm == "heap")
    std::cout << BLUE << "\033[1m[Heap Sort]\033[0m" << RESET;
  else if (algorithm == "quick")
    std::cout << BLUE << "\033[1m[Quick Sort]\033[0m" << RESET;
  else if (algorithm == "merge")
    std::cout << BLUE << "\033[1m[Merge Sort]\033[0m" << RESET;
  else if (algorithm == "counting")
    std::cout << BLUE << "\033[1m[Counting Sort]\033[0m" << RESET;
  std::cout << BLUE << "\t\tsteps: " << RESET << comparisons;
  std::cout << "\n\n";
}