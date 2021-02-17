#include "BoundingBox.h"
#include "gtest/gtest.h"


TEST(BoundingBox, AlgorithmCorrectness1)
{
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 0,
		0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0
	};
	std::vector<unsigned int> wantedOutput{
		2, 2, 2, 2, 2, 2,
		2, 1, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 2,
		2, 0, 0, 1, 1, 2,
		2, 0, 0, 0, 1, 2,
		2, 2, 2, 2, 2, 2
	};
	std::shared_ptr<BoundingBox> bBox = std::make_shared<BoundingBox>();
	auto output = bBox->Perform(input);
	EXPECT_EQ(wantedOutput, output);
}

TEST(BoundingBox, AlgorithmCorrectness2)
{
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
		0, 0, 0, 1, 1, 0,
		0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0
	};
	std::vector<unsigned int> wantedOutput{
		0, 0, 0, 0, 0, 0,
		0, 2, 2, 2, 2, 2,
		0, 2, 1, 0, 0, 2,
		0, 2, 0, 1, 1, 2,
		0, 2, 0, 0, 1, 2,
		0, 2, 2, 2, 2, 2
	};
	std::shared_ptr<BoundingBox> bBox = std::make_shared<BoundingBox>();
	auto output = bBox->Perform(input);
	EXPECT_EQ(wantedOutput, output);
}

TEST(BoundingBox, AlgorithmCorrectness3)
{
	std::vector<unsigned int> input{
		 0, 0, 0,
		 0, 1, 0,
		 0, 0, 0
	};
	std::vector<unsigned int> wantedOutput{
		2, 2, 2,
		2, 1, 2,
		2, 2, 2
	};
	std::shared_ptr<BoundingBox> bBox = std::make_shared<BoundingBox>();
	auto output = bBox->Perform(input);
	EXPECT_EQ(wantedOutput, output);
}

TEST(BoundingBox, AlgorithmCorrectness4)
{
	std::vector<unsigned int> input{
		 0, 0, 0,
		 1, 1, 0,
		 0, 0, 0
	};
	std::vector<unsigned int> wantedOutput{
		0, 0, 0,
		1, 1, 0,
		0, 0, 0
	};
	std::shared_ptr<BoundingBox> bBox = std::make_shared<BoundingBox>();
	auto output = bBox->Perform(input);
	EXPECT_EQ(wantedOutput, output);
}