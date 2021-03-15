#include "VoronoiDiagram.cpp"
#include "gtest/gtest.h"

TEST(VoronoiDiagram, Diagram_1)
{
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 2, 1, 1, 1, 1, 2, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 2, 1, 1, 1, 1, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	std::vector<unsigned int> output1{
		3, 3, 3, 3, 4, 4, 4, 4,
		3, 2, 3, 3, 4, 4, 2, 4,
		3, 3, 3, 3, 4, 4, 4, 4,
		3, 3, 3, 3, 4, 4, 4, 4,
		5, 5, 5, 5, 6, 6, 6, 6,
		5, 5, 5, 5, 6, 6, 6, 6,
		5, 2, 5, 5, 6, 6, 2, 6,
		5, 5, 5, 5, 6, 6, 6, 6
	};

	auto algo = std::make_shared<VoronoiDiagram>();
	auto mat = algo->Perform(input);
	EXPECT_EQ(mat, output1);
}
