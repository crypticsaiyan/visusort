#include "utilities.hpp"
#include <thread>
#include <chrono>

void pause(int timeInMilliseconds)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(timeInMilliseconds));
}