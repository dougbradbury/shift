#include "shift_sequence.h"
#include "stdbool.h"
#include "utilities.h"

_Bool equals(GearRatio_drivetrain_configuration const * left,
    GearRatio_drivetrain_configuration const * right)
{
  return left->front == right->front && left->rear == right->rear;
}

static size_t find(int n, DriveTrainCog const * const drive_train)
{
  return index_of(n, drive_train->cogs, drive_train->length);
}

void ShiftSequence_optimal(
    GearRatio_drivetrain_configuration initial,
    float target_ratio,
    DriveTrainCog const * const front,
    DriveTrainCog  const * const rear,
    GearRatio_drivetrain_configuration * output,
    size_t * output_length
    )
{
  int max_output_length = *output_length;
  GearRatio_drivetrain_configuration current = initial;

  GearRatio_drivetrain_configuration target =
    GearRatio_find(front->cogs, front->length, rear->cogs, rear->length, target_ratio);

  output[0] = current;
  *output_length = 1;

  size_t current_front_index = find(current.front, front);
  size_t current_rear_index = find(current.rear, rear);

  size_t target_front_index = find(target.front, front);
  size_t target_rear_index = find(target.rear, rear);

  size_t i = 1;
  while (!equals(&current, &target) && i < max_output_length)
  {
    if (current_front_index < target_front_index)
    {
      current_front_index++;
    }
    else if (current_front_index > target_front_index)
    {
      current_front_index--;
    }
    else if (current_rear_index < target_rear_index)
    {
      current_rear_index++;
    }
    else if (current_rear_index > target_rear_index)
    {
      current_rear_index--;
    }

    GearRatio_drivetrain_configuration_init(&current, front->cogs[current_front_index], rear->cogs[current_rear_index]);

    output[i] = current;
    (*output_length)++;
    i++;
  }
}
