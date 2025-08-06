#include "utils.hpp"

void swap(int32_t &x, int32_t &y)
{
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
}