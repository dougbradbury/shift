#include "unity.h"

#include "utilities.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_utilities_index_of(void)
{
  int test_array[] = {9, 3, 0};
  TEST_ASSERT_EQUAL(1, index_of(3, test_array, 3));
  TEST_ASSERT_EQUAL(0, index_of(9, test_array, 3));
  TEST_ASSERT_EQUAL(2, index_of(0, test_array, 3));
}
