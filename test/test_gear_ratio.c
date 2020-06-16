#include "unity.h"

#include "gear_ratio.h"

void setUp(void)
{
}

void tearDown(void)
{
}

//output ratio = tooth count on selected front cog / tooth count on selected rear cog
void test_gear_ratio_NeedToImplement(void)
{
    TEST_ASSERT_EQUAL_FLOAT(1.579, GearRatio_for(30, 19));
}
