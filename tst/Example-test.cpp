#include "gtest/gtest.h"
#include "Example.h"
#include <string>

TEST(Example, test1)
{
    EXPECT_EQ(1,1);
}

TEST(Example, test2)
{
	std::string buffer = fun();
	EXPECT_EQ("Hello", buffer);
}

TEST(Example, test3)
{
	int c = num();
	EXPECT_EQ(c, 5);
}

