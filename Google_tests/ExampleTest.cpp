#include "gtest/gtest.h"
#include "ExampleClass.h"

TEST(ExampleSuite, ExampleTest) {
    ExampleClass e = ExampleClass();

    EXPECT_EQ(1, e.doSomething());
}

TEST(ExampleSuite2, ExampleTest) {
	ExampleClass e = ExampleClass();

	EXPECT_EQ(5, e.sum(2,3));
}