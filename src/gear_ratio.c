#include "gear_ratio.h"

float GearRatio_for(int front_crank_tooth_count, int rear_cassette_tooth_count)
{
  return (float) front_crank_tooth_count / (float) rear_cassette_tooth_count;
}

