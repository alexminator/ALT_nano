#ifndef SENSOR_MATH_H
#define SENSOR_MATH_H

#include <stdint.h>

namespace SensorMath {

inline bool isValidReading(float distanceCm, int deadZoneCm, int topDistanceCm)
{
  return distanceCm >= deadZoneCm && distanceCm <= topDistanceCm;
}

inline int liquidColumnCm(int topDistanceCm, int distanceCm)
{
  return topDistanceCm - distanceCm;
}

// Match Arduino map() integer arithmetic while keeping the multiplication 32-bit on AVR.
inline int levelPercent(int liquidColumn, int maximumLiquidColumn)
{
  if (maximumLiquidColumn <= 0) {
    return 0;
  }

  return static_cast<int>((static_cast<int32_t>(liquidColumn) * 100L) / maximumLiquidColumn);
}

inline float partitionVolumeCm3(float partitionWidthCm, float partitionLengthCm, float liquidColumn)
{
  return partitionWidthCm * partitionLengthCm * liquidColumn;
}

inline float grossTankVolumeCm3(float tankWidthCm, float tankLengthCm, float liquidColumn)
{
  return tankWidthCm * tankLengthCm * liquidColumn;
}

inline float waterVolumeLiters(float grossVolumeCm3, float partitionVolumeCm3)
{
  return (grossVolumeCm3 - partitionVolumeCm3) / 1000.0f;
}

} // namespace SensorMath

#endif // SENSOR_MATH_H
