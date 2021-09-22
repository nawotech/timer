#include <ArduinoFake.h>
#include <unity.h>
#include "timer.h"

using namespace fakeit;

void test_time_passed(void)
{
    // create test timer object
    Timer TestTmr;

    // test time not yet passed returns false
    When(Method(ArduinoFake(), millis)).Return(50);
    TEST_ASSERT_FALSE(TestTmr.time_passed(100));

    // test time not yet passed returns false
    When(Method(ArduinoFake(), millis)).Return(100);
    TEST_ASSERT_FALSE(TestTmr.time_passed(100));

    // test time passed returns true
    When(Method(ArduinoFake(), millis)).AlwaysReturn(101);
    TEST_ASSERT_TRUE(TestTmr.time_passed(100));

    // test that it resets itself
    When(Method(ArduinoFake(), millis)).Return(101);
    TEST_ASSERT_FALSE(TestTmr.time_passed(100));

    // test time passed returns true
    When(Method(ArduinoFake(), millis)).AlwaysReturn(202);
    TEST_ASSERT_TRUE(TestTmr.time_passed(100));
}

void test_reset(void)
{
    // create test timer object
    Timer TestTmr;

    // test time not yet passed returns false
    When(Method(ArduinoFake(), millis)).Return(50);
    TEST_ASSERT_FALSE(TestTmr.time_passed(100));

    // reset timer
    When(Method(ArduinoFake(), millis)).Return(100);
    TestTmr.reset();

    // check that after reset returns false still
    When(Method(ArduinoFake(), millis)).Return(200);
    TEST_ASSERT_FALSE(TestTmr.time_passed(100));

    // test time passed returns true
    When(Method(ArduinoFake(), millis)).AlwaysReturn(201);
    TEST_ASSERT_TRUE(TestTmr.time_passed(100));
}

void test_get_ms(void)
{
    // create test timer object
    Timer TestTmr;

    When(Method(ArduinoFake(), millis)).Return(50);
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(50, TestTmr.get_ms(), "Timer returns correct ms");

    // reset timer
    When(Method(ArduinoFake(), millis)).Return(100);
    TestTmr.reset();

    When(Method(ArduinoFake(), millis)).Return(123456789);
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(123456689, TestTmr.get_ms(), "Timer returns correct ms");
}

void setUp(void)
{
    ArduinoFakeReset();
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_time_passed);
    RUN_TEST(test_reset);
    RUN_TEST(test_get_ms);

    UNITY_END();

    return 0;
}