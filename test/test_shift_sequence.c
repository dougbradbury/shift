#include "unity.h"

#include "shift_sequence.h"
#include "drive_train.h"
#include "gear_ratio.h"

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

static GearRatio_drivetrain_configuration results[10];

void test_shift_sequence_no_change(void)
{

  GearRatio_drivetrain_configuration initial;
  GearRatio_drivetrain_configuration_init(&initial, 30, 19);

  GearRatio_drivetrain_configuration target;
  GearRatio_drivetrain_configuration_init(&target, 30, 19);

  size_t result_length = 10;
  ShiftSequence_optimal(initial, 1.6, front, rear, results, &result_length);

  TEST_ASSERT_EQUAL_INT(1, result_length);



}
