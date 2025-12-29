#include "leap.h"

bool leap_year(int year) {
  bool isDivisibleBy4 = year % 4 == 0;
  bool isDivisibleBy100 = year % 100 == 0;
  bool isDivisibleBy400 = year % 400 == 0;

  return (isDivisibleBy4 && !isDivisibleBy100) ? 1 : isDivisibleBy400 ? 1 : 0;
}
