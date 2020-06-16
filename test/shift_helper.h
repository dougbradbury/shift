
#ifndef SHIFT_HELPER_H
#define SHIFT_HELPER_H

#define TEST_ASSERT_EQUAL_DRIVETRAIN(expected, actual) \
  TEST_ASSERT_EQUAL_INT(expected.front, actual.front); \
  TEST_ASSERT_EQUAL_INT(expected.rear, actual.rear);\
  TEST_ASSERT_EQUAL_FLOAT(expected.ratio, actual.ratio);

#endif //SHIFT_HELPER_H
