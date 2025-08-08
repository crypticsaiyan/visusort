#include "utilities.hpp"
#include <cmath>

std::vector<std::string> colorArray = {YELLOW, RED, GREEN, BLUE};

void printSymbol(size_t indexSelected, char ch, std::vector<int32_t> &v)
{
  int spaces = 0;
  for (size_t i = 0; i < indexSelected; i++)
  {
    spaces += ((v[i] == 0) ? 4 : (log10(abs(v[i])) + 4));
    if (v[i] < 0)
    {
      spaces++;
    }
  }
  spaces += (v[indexSelected] == 0) ? 1 : std::log10(abs(v[indexSelected])) / 2 + 1;
  if (v[indexSelected] < 0)
  {
    spaces++;
  }
  for (int i = 0; i < spaces; i++)
  {
    std::cout << ' ';
  }
  std::cout << ch << std::endl;
}

void printArr(std::vector<int32_t> &v)
{
  for (size_t i = 0; i < v.size(); i++)
  {
    if (isIndexSorted[i] == 1)
      std::cout << YELLOW << "[" << v[i] << "] " << RESET;
    else if (red == i)
      std::cout << RED << "[" << v[i] << "] " << RESET;
    else if (green == i)
      std::cout << GREEN << "[" << v[i] << "] " << RESET;
    else if (blueIndex.first <= i && blueIndex.second >= i)
      std::cout << BLUE << "[" << v[i] << "] " << RESET;
    else
      std::cout << "[" << v[i] << "] ";
  }
  std::cout << std::endl;
}

void printStorage(std::vector<std::vector<int32_t>> storage)
{
  clear();
  greeter();
  int colorIndex = 0;
  for (int i = 0; i < storage.size(); i++)
  {
    for (int j = 0; j < storage[i].size(); j++)
    {
      std::cout << colorArray[colorIndex] << "[" << storage[i][j] << "] " << RESET;
    }
    std::cout << "    ";
    colorIndex += storage[i].size();
    if (colorIndex > colorArray.size() - 1)
      colorIndex = colorIndex % (colorArray.size() - 1);
  }
  std::cout << std::endl;
  pause(1000);
}