#include "FindingWay.cpp"
#include "gtest/gtest.h"

TEST(FindingWay, Labirynth_1)
{
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 0, 0, 0, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 1, 1, 1, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 3, 0, 0, 0, 0, 0
	};

	std::vector<unsigned int> output1{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 0, 0, 0, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 1, 1, 1, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 4, 4, 4, 4, 4, 3
	};

	std::vector<unsigned int> output2{
		0, 0, 0, 0, 0, 0, 0, 4,
		0, 1, 1, 0, 0, 0, 2, 4,
		0, 0, 0, 0, 0, 0, 0, 4,
		0, 0, 0, 1, 1, 1, 0, 4,
		0, 0, 0, 0, 0, 1, 0, 4,
		0, 1, 1, 1, 0, 1, 0, 4,
		0, 0, 0, 0, 0, 1, 0, 4,
		0, 0, 3, 0, 0, 0, 0, 4
	};

	std::vector<unsigned int> output3{
		0, 0, 0, 0, 0, 0, 0, 4,
		0, 1, 1, 0, 0, 0, 3, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 1, 1, 1, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 3, 0, 0, 0, 0, 0
	};
	
	auto algo = std::make_shared<FindingWay>();
	auto mat = algo->Perform(input);
	EXPECT_EQ(mat, output1);
	mat = algo->Perform(mat);
	EXPECT_EQ(mat, output2);
	mat = algo->Perform(mat);
	EXPECT_EQ(mat, output3);
}

TEST(FindingWay, Labirynth_2)
{
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 0, 0, 0, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 1, 1, 1, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 3, 0, 0, 0, 0, 0
	};

	std::vector<unsigned int> output1{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 0, 0, 0, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 1, 1, 1, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 4, 4, 4, 4, 4, 3
	};

	std::vector<unsigned int> output2{
		0, 0, 0, 0, 0, 0, 0, 4,
		0, 1, 1, 0, 0, 0, 2, 4,
		0, 0, 0, 0, 0, 0, 0, 4,
		0, 0, 0, 1, 1, 1, 0, 4,
		0, 0, 0, 0, 0, 1, 0, 4,
		0, 1, 1, 1, 0, 1, 0, 4,
		0, 0, 0, 0, 0, 1, 0, 4,
		0, 0, 3, 0, 0, 0, 0, 4
	};

	std::vector<unsigned int> output3{
		0, 0, 0, 0, 0, 0, 0, 4,
		0, 1, 1, 0, 0, 0, 3, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 1, 1, 1, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 3, 0, 0, 0, 0, 0
	};

	auto algo = std::make_shared<FindingWay>();
	auto mat = algo->Perform(input);
	EXPECT_EQ(mat, output1);
	mat = algo->Perform(mat);
	EXPECT_EQ(mat, output2);
	mat = algo->Perform(mat);
	EXPECT_EQ(mat, output3);
}