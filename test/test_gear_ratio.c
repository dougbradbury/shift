#define UNITY_FLOAT_PRECISION 0.001f
#include "unity.h"

#include "gear_ratio.h"
#include "shift_helper.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_gear_ratio_for(void)
{
    TEST_ASSERT_EQUAL_FLOAT(1.578947, GearRatio_for(30, 19));
    TEST_ASSERT_EQUAL_FLOAT(2.375, GearRatio_for(38, 16));
}

void test_gear_ratio_target(void)
{
  int front[] = {30};
  int rear[] = {15};
  GearRatio_drivetrain_configuration expected = {30, 15, 2.0};

  GearRatio_drivetrain_configuration actual = GearRatio_find(front, 1, rear, 1, 2.0);

  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, actual);
}

void test_gear_ratio_target_multiple(void)
{
  int front[] = {15, 30};
  int rear[] = {15};
  GearRatio_drivetrain_configuration expected = {15, 15, 1.0};

  GearRatio_drivetrain_configuration actual = GearRatio_find(front,2, rear, 2, 1.0);

  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, actual);
}

void test_under_target_gear_ratio(void)
{
  int front[] = {30, 15};
  int rear[] = {19};
  GearRatio_drivetrain_configuration expected = {30, 19, 1.578947};

  GearRatio_drivetrain_configuration actual = GearRatio_find(front,2, rear, 2, 1.6);

  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, actual);
}

void test_under_target_gear_exact(void)
{
  int front[] = {30, 15};
  int rear[] = {19};
  GearRatio_drivetrain_configuration expected = {30, 19, 1.578947};

  GearRatio_drivetrain_configuration actual = GearRatio_find(front,2, rear, 2, 1.578947);

  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, actual);
}

void test_multple_rear_cassettes(void)
{
  int front[] = {38, 30};
  int rear[] = {28, 23, 19, 16};
  GearRatio_drivetrain_configuration expected = {30, 19, 1.578947};

  GearRatio_drivetrain_configuration actual = GearRatio_find(front,2, rear, 4, 1.6);

  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, actual);
}

void test_empty_cogs(void)
{
  int front[] = {};
  int rear[] = {};
  GearRatio_drivetrain_configuration expected = {0, 0, 0};

  GearRatio_drivetrain_configuration actual = GearRatio_find(front,0, rear, 0, 1.6);

  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, actual);
}

void test_exact_ratio_match(void)
{
  int front[] = {38, 30};
  int rear[] = {28, 23, 19, 16};
  GearRatio_drivetrain_configuration expected = {30, 19, 1.578947};

  GearRatio_drivetrain_configuration actual = GearRatio_find(front,2, rear, 4, 1.578947);

  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, actual);
}
