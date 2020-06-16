#include "unity.h"
#include "shift_helper.h"

#include "shift_sequence.h"
#include "drive_train.h"
#include "gear_ratio.h"
#include "utilities.h"

static GearRatio_drivetrain_configuration initial;
static GearRatio_drivetrain_configuration target;
static GearRatio_drivetrain_configuration expected;

void setUp(void)
{
}

void tearDown(void)
{
}

static DriveTrainCog front = {
   2,
  {38, 30}
};

static DriveTrainCog rear = {
   4,
  {28, 23, 19, 16}
};


void test_shift_sequence_no_change(void)
{
  GearRatio_drivetrain_configuration results[10];
  size_t result_length = 10;

  GearRatio_drivetrain_configuration_init(&initial, 30, 19);
  GearRatio_drivetrain_configuration_init(&target, 30, 19);
  ShiftSequence_optimal(initial, 1.6, &front, &rear, results, &result_length);

  TEST_ASSERT_EQUAL_INT(1, result_length);
  TEST_ASSERT_EQUAL_DRIVETRAIN(target, results[0]);
}

void test_shift_sequence_one_step(void)
{
  GearRatio_drivetrain_configuration results[10];
  size_t result_length = 10;

  GearRatio_drivetrain_configuration_init(&initial, 30, 16);
  GearRatio_drivetrain_configuration_init(&target, 30, 19);

  ShiftSequence_optimal(initial, 1.6, &front, &rear, results, &result_length);

  TEST_ASSERT_EQUAL_INT(2, result_length);
  TEST_ASSERT_EQUAL_DRIVETRAIN(initial, results[0]);
  TEST_ASSERT_EQUAL_DRIVETRAIN(target, results[1]);
}

void test_shift_sequence_two_steps(void)
{
  GearRatio_drivetrain_configuration results[10];
  size_t result_length = 10;

  GearRatio_drivetrain_configuration_init(&initial, 30, 28);
  GearRatio_drivetrain_configuration_init(&target, 30, 19);

  ShiftSequence_optimal(initial, 1.6, &front, &rear, results, &result_length);

  TEST_ASSERT_EQUAL_INT(3, result_length);

  TEST_ASSERT_EQUAL_DRIVETRAIN(initial, results[0]);

  GearRatio_drivetrain_configuration_init(&expected, 30, 23);
  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, results[1]);

  TEST_ASSERT_EQUAL_DRIVETRAIN(target, results[2]);
}

void test_shift_sequence_step_front_and_rear(void)
{
  GearRatio_drivetrain_configuration results[10];
  size_t result_length = 10;

  GearRatio_drivetrain_configuration_init(&initial, 38, 28);

  ShiftSequence_optimal(initial, 1.6, &front, &rear, results, &result_length);

  TEST_ASSERT_EQUAL_INT(4, result_length);
  TEST_ASSERT_EQUAL_DRIVETRAIN(initial, results[0]);

  GearRatio_drivetrain_configuration_init(&expected, 30, 28);
  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, results[1]);

  GearRatio_drivetrain_configuration_init(&expected, 30, 23);
  TEST_ASSERT_EQUAL_DRIVETRAIN(expected, results[2]);

  GearRatio_drivetrain_configuration_init(&target, 30, 19);
  TEST_ASSERT_EQUAL_DRIVETRAIN(target, results[3]);
}

