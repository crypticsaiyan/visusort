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
  if (algorithm == "selection")
    std::cout << "\033[1m[Selection Sort]\033[0m";
  else if (algorithm == "insertion")
    std::cout << "\033[1m[Insertion Sort]\033[0m";
  else if(algorithm == "bubble")
    std::cout << "\033[1m[Bubble Sort]\033[0m";
  else if(algorithm == "heap")
    std::cout << "\033[1m[Heap Sort]\033[0m";
  else if(algorithm == "quick")
    std::cout << "\033[1m[Quick Sort]\033[0m";
  std::cout << "\t\t\tcomparisons: " << comparisons;
  std::cout << "\n\n";
}