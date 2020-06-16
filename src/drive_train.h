
#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include <stddef.h>
typedef struct DriveTrainCogs
{
  size_t length;
  int cogs[];
} DriveTrainCog;

#endif // DRIVE_TRAIN_H
