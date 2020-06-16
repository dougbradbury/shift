#include "gear_ratio.h"

float GearRatio_for(int front_crank_tooth_count, int rear_cassette_tooth_count)
{
  return (float) front_crank_tooth_count / (float) rear_cassette_tooth_count;
}

void GearRatio_drivetrain_configuration_init(GearRatio_drivetrain_configuration * drivetrain, int front, int rear)
{
  drivetrain->front = front;
  drivetrain->rear = rear;
  drivetrain->ratio = GearRatio_for(front, rear);
}

GearRatio_drivetrain_configuration GearRatio_find(int const front[], size_t front_length, int const rear[], size_t rear_length, float target_ratio)
{
  GearRatio_drivetrain_configuration best_match = { 0,0,0.0} ;
  if (front_length > 0 && rear_length > 0)
  {
    GearRatio_drivetrain_configuration_init(&best_match, front[0], rear[0]);

    for (size_t f = 0; f < front_length; f++)
    {
      for (size_t r = 0; r < rear_length; r++)
      {
        GearRatio_drivetrain_configuration result;
        GearRatio_drivetrain_configuration_init(&result, front[f], rear[r]);

        float ratio_diff = target_ratio - result.ratio;

        if(ratio_diff >= -0.001 && ratio_diff <= (target_ratio - best_match.ratio) ) {
          GearRatio_drivetrain_configuration_init(&best_match, front[f], rear[r]);
        }

      }
    }
  }
  return best_match;
}

