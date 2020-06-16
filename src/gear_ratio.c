#include "gear_ratio.h"

float GearRatio_for(int front_crank_tooth_count, int rear_cassette_tooth_count)
{
  return (float) front_crank_tooth_count / (float) rear_cassette_tooth_count;
}

static void drivetrain_configuration_init(GearRatio_drivetrain_configuration * drivetrain, int front, int rear)
{
  drivetrain->front = front;
  drivetrain->rear = rear;
  drivetrain->ratio = GearRatio_for(front, rear);
}

GearRatio_drivetrain_configuration GearRatio_find(int front[], size_t front_length, int rear[], size_t rear_length, float target_ratio)
{
  GearRatio_drivetrain_configuration result;

  for (size_t i = 0; i < front_length; i++)
  {
    drivetrain_configuration_init(&result, front[i], rear[0]);
    if(target_ratio == result.ratio ) {
      return result;
    }
  }
  return result;
}
