#include "../src/Algorithms/Board.cpp"
#include "gtest/gtest.h"

class BoardTest : public ::testing :: Test{
public:
	BoardTest() {
		algorithms = std::make_shared<AlgorithmsKeeper>();
	}

	std::shared_ptr<AlgorithmsKeeper> algorithms;
};

TEST_F(BoardTest, HelloWorld)
{
	EXPECT_EQ(1, 1);
}

TEST_F(BoardTest, ConstructorProper)
{
	std::vector<unsigned int> input{ 1, 2, 3, 4 };
	BoardImplementation b(algorithms, input);
	auto output=b.GetCurrentState();
	EXPECT_EQ(input, output);
}

TEST_F(BoardTest, ConstructorInproper1)
{
	std::vector<unsigned int> input{ 1, 2, 3 };
	EXPECT_EXIT(BoardImplementation b(algorithms, input), ::testing::ExitedWithCode(1), "");
}

TEST_F(BoardTest, ConstructorInproper2)
{
	std::vector<unsigned int> input{ 1, 2 };
	EXPECT_EXIT(BoardImplementation b(algorithms, input), ::testing::ExitedWithCode(1), "");
}

TEST_F(BoardTest, ConstructorInproper3)
{
	std::vector<unsigned int> input{ 1 };
	EXPECT_EXIT(BoardImplementation b(algorithms, input), ::testing::ExitedWithCode(1), "");
}
