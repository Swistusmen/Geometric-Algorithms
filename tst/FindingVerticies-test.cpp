#include "../src/Algorithms/FindingVerticies.cpp"
#include "gtest/gtest.h"

TEST(FindingVerticies, Shape_1)
{
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 1, 1, 1, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	std::vector<unsigned int> output1{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 2, 1, 1, 1, 1, 2, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 2, 1, 1, 1, 1, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	auto algo = std::make_shared<FindingVerticies>();
	auto mat = algo->Perform(input);
	EXPECT_EQ(mat, output1);
}

TEST(FindingVerticies, Shape_2)
{
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 1, 1, 1, 0, 0,
		0, 0, 1, 0, 0, 1, 0, 0,
		0, 0, 1, 0, 0, 1, 0, 0,
		0, 1, 1, 0, 0, 1, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	std::vector<unsigned int> output1{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 2, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 0, 1, 0, 0,
		0, 0, 1, 0, 0, 1, 0, 0,
		0, 2, 2, 0, 0, 2, 2, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 2, 1, 1, 1, 1, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	auto algo = std::make_shared<FindingVerticies>();
	auto mat = algo->Perform(input);
	EXPECT_EQ(mat, output1);
}

TEST(FindingVerticies, Shape_3)
{
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 0, 0, 0,
		0, 0, 1, 0, 0, 1, 0, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 0, 1, 0, 0, 1, 0, 0,
		0, 0, 0, 1, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	std::vector<unsigned int> output1{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 2, 2, 0, 0, 0,
		0, 0, 1, 0, 0, 1, 0, 0,
		0, 2, 0, 0, 0, 0, 2, 0,
		0, 2, 0, 0, 0, 0, 2, 0,
		0, 0, 1, 0, 0, 1, 0, 0,
		0, 0, 0, 2, 2, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	auto algo = std::make_shared<FindingVerticies>();
	auto mat = algo->Perform(input);
	EXPECT_EQ(mat, output1);
}

TEST(FindingVerticies, Shape_4)
{
	std::vector<unsigned int> input{
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
	};

	std::vector<unsigned int>output1{
		2, 1, 1, 1, 1, 1, 1, 1, 2,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		2, 1, 1, 1, 1, 1, 1, 1, 2,
	};

	auto algo = std::make_shared<FindingVerticies>();
	auto mat = algo->Perform(input);
	EXPECT_EQ(mat, output1);
}