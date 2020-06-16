#define UNITY_FLOAT_PRECISION 0.001f
#include "unity.h"

#include "gear_ratio.h"

void setUp(void)
{
}

void tearDown(void)
{
}

//output ratio = tooth count on selected front cog / tooth count on selected rear cog
void test_gear_ratio_for(void)
{
    TEST_ASSERT_EQUAL_FLOAT(1.578947, GearRatio_for(30, 19));
    TEST_ASSERT_EQUAL_FLOAT(2.375, GearRatio_for(38, 16));
}
