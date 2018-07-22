#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "sample.h"
/* 定义个 TEST_GROUP, 名称为 sample */
TEST_GROUP(sample){};

/* 定义一个属于 TEST_GROUP 的 TEST, 名称为 ret_int_success */
TEST(sample, addition)
{
    int sum = add(1, 2);
    CHECK_EQUAL(sum, 3);
}

/* 定义一个属于 TEST_GROUP 的 TEST, 名称为 ret_int_failed */
TEST(sample, substition)
{
    int ret = sub(4, 2);
    CHECK_EQUAL(ret, 2);
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}
