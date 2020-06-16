#ifndef GEAR_RATIO_H
#define GEAR_RATIO_H

#include <stddef.h>

typedef struct GearRatio_drivetrain_configurations
{
  int front;
  int rear;
  float ratio;
} GearRatio_drivetrain_configuration;

float GearRatio_for(int front_crank_tooth_count, int rear_cassette_tooth_count);
GearRatio_drivetrain_configuration GearRatio_find(int front[], size_t front_length, int rear[], size_t rear_length, float target_ratio);

#endif // GEAR_RATIO_H
