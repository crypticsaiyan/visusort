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

// For Merge Sort
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


//For Counting Sort
void printCount(std::vector<int32_t> &count, size_t highlightIndex, char x)
{
  for (size_t i = 0; i < count.size(); i++)
  {
    if (i == highlightIndex)
    {
      if (x == 'G')
        std::cout << GREEN << "[" << count[i] << "] " << RESET;
      else if (x == 'B')
        std::cout << BLUE << "[" << count[i] << "] " << RESET;
      else if (x == 'R')
        std::cout << RED << "[" << count[i] << "] " << RESET;
      else if (x == 'Y')
        std::cout << YELLOW << "[" << count[i] << "] " << RESET;
      else
        std::cout << "[" << count[i] << "] ";
    }
    else
      std::cout << "[" << count[i] << "] ";
  }
  std::cout << std::endl;
}

void runCountingAnimation(std::vector<int32_t> &v, size_t vIndex, std::vector<int32_t> &count, size_t highlightIndex, char x, std::vector<int32_t> output, size_t oIndex)
{
  clear();
  greeter();
  if (vIndex != -1)
  {
    printCount(v, vIndex, 'B');
    printSymbol(vIndex, '^', v);
  }
  else
  {
    printCount(v, vIndex, 'x');
    std::cout << std::endl;
  }
  if (prefixFlag == 1)
    std::cout << "Making the Prefix Array:" << std::endl;
  else if (prefixFlag == 0)
    std::cout << "Counting the number of occurances:" << std::endl;
  else
    std::cout << "Prefix Array:" << std::endl;

  if (prefixFlag == 1)
  {
    // Temporarily resize isIndexSorted for count array printing
    size_t originalSize = isIndexSorted.size();
    isIndexSorted.resize(count.size(), 0);
    printArr(count);
    isIndexSorted.resize(originalSize);
  }
  else
    printCount(count, highlightIndex, x);
  std::cout << std::endl;

  // Temporarily save and clear blueIndex for output array printing
  std::pair<int, int> tempBlueIndex = blueIndex;
  blueIndex = {-1, -1};
  printArr(output);
  // Restore blueIndex only if we're in prefix phase
  if (prefixFlag == 1)
    blueIndex = tempBlueIndex;
    
  if (oIndex != -1)
  {
    printSymbol(oIndex, '^', v);
  }
  else
  {
    std::cout << std::endl;
  }
  pause(pause_duration);
}
