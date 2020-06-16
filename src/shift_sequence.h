#ifndef SHIFT_SEQUENCE_H
#define SHIFT_SEQUENCE_H

#include "gear_ratio.h"
#include "drive_train.h"

  void ShiftSequence_optimal(
      GearRatio_drivetrain_configuration initial,
      float target_ratio,
      DriveTrainCog const * const front,
      DriveTrainCog  const * const rear,
      GearRatio_drivetrain_configuration * output,
      size_t * output_length
      );

#endif // SHIFT_SEQUENCE_H
