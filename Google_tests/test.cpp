#include "gtest/gtest.h"
#include "ExampleClass.h"
#include <cstdlib>

TEST(ExampleSuite, ExampleTest) {
    ExampleClass e = ExampleClass();

    EXPECT_EQ(1, e.doSomething());
}

TEST(ExampleSuite2, ExampleTest) {
	ExampleClass e = ExampleClass();

	EXPECT_EQ(5, e.sum(2,3));
}
/**************************/
#include "Pixel.h"
TEST(PIXEL_TEST, Default_constructor){
	Pixel p;
	EXPECT_EQ(0, p.get_r());
	EXPECT_EQ(0, p.get_b());
	EXPECT_EQ(0, p.get_g());
}
TEST(PIXEL_TEST_2, Default_constructor){
	for(int i = 0; i < 256; ++i){
		Pixel p(i, i, i);
		EXPECT_EQ(i, p.get_r());
		EXPECT_EQ(i, p.get_b());
		EXPECT_EQ(i, p.get_g());
	}
}