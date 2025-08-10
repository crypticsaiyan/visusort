#include "techniques.hpp"
#include <algorithm>

void countingSort(std::vector<int32_t> &v)
{
  std::vector<int32_t> output(v.size(), 0);
  int32_t minVal = *std::min_element(v.begin(), v.end());
  int32_t maxVal = *std::max_element(v.begin(), v.end());

  int32_t range = maxVal - minVal + 1;
  std::vector<int32_t> count(range, 0);

  runCountingAnimation(v, 0, count, 0, 'G', output, 0);

  for (size_t i = 0; i < v.size(); i++)
  {
    comparisons++;
    size_t countIndex = v[i] - minVal;
    runCountingAnimation(v, i, count, countIndex, 'G', output, -1);
    count[countIndex]++;
    runCountingAnimation(v, i, count, countIndex, 'G', output, -1);
  }

  prefixFlag = 1;
  for (size_t i = 1; i < count.size(); i++)
  {
    comparisons++;
    blueIndex = {0, i - 1};
    runCountingAnimation(v, -1, count, i, 'B', output, -1);
    count[i] += count[i - 1];
    blueIndex = {0, i};
    runCountingAnimation(v, -1, count, i, 'B', output, -1);
  }

  prefixFlag = 2;
  for (int32_t i = static_cast<int32_t>(v.size()) - 1; i >= 0; i--)
  {
    comparisons++;
    clear();
    int32_t num = v[i];
    output[--count[num - minVal]] = num;
    isIndexSorted[count[num - minVal]] = 1;
    runCountingAnimation(v, i, count, num - minVal, 'R', output, count[num - minVal]);
  }
}