#include <unity.h>

#include "sensor_math.h"

void test_reading_is_valid_at_both_inclusive_boundaries()
{
  TEST_ASSERT_TRUE(SensorMath::isValidReading(20.0f, 20, 104));
  TEST_ASSERT_TRUE(SensorMath::isValidReading(104.0f, 20, 104));
}

void test_reading_is_invalid_below_dead_zone_and_above_empty_tank_distance()
{
  TEST_ASSERT_FALSE(SensorMath::isValidReading(19.0f, 20, 104));
  TEST_ASSERT_FALSE(SensorMath::isValidReading(105.0f, 20, 104));
}

void test_fractional_distance_is_checked_against_inclusive_boundaries()
{
  TEST_ASSERT_FALSE(SensorMath::isValidReading(19.99f, 20, 104));
  TEST_ASSERT_TRUE(SensorMath::isValidReading(20.01f, 20, 104));
  TEST_ASSERT_TRUE(SensorMath::isValidReading(103.99f, 20, 104));
  TEST_ASSERT_FALSE(SensorMath::isValidReading(104.01f, 20, 104));
}

void test_liquid_column_is_distance_from_empty_tank_reference()
{
  TEST_ASSERT_EQUAL_INT(0, SensorMath::liquidColumnCm(104, 104));
  TEST_ASSERT_EQUAL_INT(84, SensorMath::liquidColumnCm(104, 20));
}

void test_level_percent_matches_integer_mapping_and_bounds()
{
  TEST_ASSERT_EQUAL_INT(0, SensorMath::levelPercent(0, 84));
  TEST_ASSERT_EQUAL_INT(50, SensorMath::levelPercent(42, 84));
  TEST_ASSERT_EQUAL_INT(98, SensorMath::levelPercent(83, 84));
  TEST_ASSERT_EQUAL_INT(100, SensorMath::levelPercent(84, 84));
}

void test_level_percent_uses_wide_intermediate_and_guards_zero_range()
{
  TEST_ASSERT_EQUAL_INT(100, SensorMath::levelPercent(300, 300));
  TEST_ASSERT_EQUAL_INT(0, SensorMath::levelPercent(1, 0));
  TEST_ASSERT_EQUAL_INT(0, SensorMath::levelPercent(1, -1));
}

void test_partition_volume_is_subtracted_from_gross_volume()
{
  const float column = 10.0f;
  const float partition = SensorMath::partitionVolumeCm3(14.5f, 200.0f, column);
  const float gross = SensorMath::grossTankVolumeCm3(195.5f, 200.0f, column);

  TEST_ASSERT_FLOAT_WITHIN(0.01f, 29000.0f, partition);
  TEST_ASSERT_FLOAT_WITHIN(0.01f, 391000.0f, gross);
  TEST_ASSERT_FLOAT_WITHIN(0.001f, 362.0f, SensorMath::waterVolumeLiters(gross, partition));
}

void test_zero_water_column_has_zero_volume()
{
  const float partition = SensorMath::partitionVolumeCm3(14.5f, 200.0f, 0.0f);
  const float gross = SensorMath::grossTankVolumeCm3(195.5f, 200.0f, 0.0f);

  TEST_ASSERT_FLOAT_WITHIN(0.001f, 0.0f, SensorMath::waterVolumeLiters(gross, partition));
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_reading_is_valid_at_both_inclusive_boundaries);
  RUN_TEST(test_reading_is_invalid_below_dead_zone_and_above_empty_tank_distance);
  RUN_TEST(test_fractional_distance_is_checked_against_inclusive_boundaries);
  RUN_TEST(test_liquid_column_is_distance_from_empty_tank_reference);
  RUN_TEST(test_level_percent_matches_integer_mapping_and_bounds);
  RUN_TEST(test_level_percent_uses_wide_intermediate_and_guards_zero_range);
  RUN_TEST(test_partition_volume_is_subtracted_from_gross_volume);
  RUN_TEST(test_zero_water_column_has_zero_volume);
  return UNITY_END();
}
