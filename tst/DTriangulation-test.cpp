#include "DTriangulation.cpp"
#include "gtest/gtest.h"

TEST(DTriangulation, Triangulation1_1)
{
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 2, 0, 0, 0, 0, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	std::vector<unsigned int> output1{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 1, 1, 1, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	auto algo = std::make_shared<DTriangulation>();
	auto mat = algo->Perform(input);
	EXPECT_EQ(mat, output1);
}