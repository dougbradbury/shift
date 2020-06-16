#include "utilities.h"

size_t index_of(int n, int const ary[], size_t len)
{
  for (size_t i = 0; i < len; i++)
  {
    if (ary[i] == n)
    {
      return i;
    }
  }

  return -1;
}
