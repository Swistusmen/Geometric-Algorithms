#include "FindingWay.h"

FindingWay::FindingWay()
{
	robotMoves.insert({ Direction::TOP,[](int robot,int dimension) { return robot -= dimension; } });
	robotMoves.insert({ Direction::TOP_RIGHT,[](int robot,int dimension) { return robot -= (dimension+1); }});
	robotMoves.insert({ Direction::RIGHT,[](int robot,int dimension) { return robot+=1; } });
	robotMoves.insert({ Direction::BOTTOM_RIGHT,[](int robot,int dimension) { return robot += (dimension+1); } });
	robotMoves.insert({ Direction::BOTTOM,[](int robot,int dimension) { return robot += dimension; } });
	robotMoves.insert({ Direction::BOTTOM_LEFT,[](int robot,int dimension) { return robot += (dimension-1); } });
	robotMoves.insert({ Direction::LEFT,[](int robot,int dimension) { return robot -=1; } });
	robotMoves.insert({ Direction::TOP_LEFT,[](int robot,int dimension) { return robot -= (dimension-1); } });

	directions=std::array<Direction,8>{
		Direction::TOP,
		Direction::TOP_RIGHT,
		Direction::RIGHT,
		Direction::BOTTOM_RIGHT,
		Direction::BOTTOM,
		Direction::BOTTOM_LEFT,
		Direction::LEFT,
		Direction::TOP_LEFT };
}

std::vector<unsigned int> FindingWay::Perform(std::vector<unsigned int> data)
{
	auto size = data.size();
	int dimension = static_cast<int>(sqrt(size));
	int robot = std::find(data.begin(), data.end(), 3)-data.begin();
	std::transform(data.begin(), data.end(),data.begin(),[](auto a) {return a == 4 ? 5 : a; });
	auto scan = ScanForAWay(data, dimension,robot);
	std::transform(data.begin(), data.end(), data.begin(),[](auto a) {return a == 5 ? 0 : a; });
	return MakeAMove(robot,scan.second,dimension,data);
}

std::pair<FindingWay::RobotAction, int> FindingWay::ScanForAWay(std::vector<unsigned int> board, int dimension,int robot)
{
	std::array<int, 8> distances{ 0 }; //top, top right, right, bottom right, .....
	int founded = -1;
	int size = std::pow(dimension, 2);
	state = AlgoState::PERFORMING;

	for (int i = 0; i < 8; i++)
	{
		auto fun = robotMoves.find(directions.at(i))->second;
		int tempRobot = robot;
		int previousRobot;
		while(board[tempRobot]==0||board[tempRobot]==3|| board[tempRobot] == 2)
		{
			previousRobot = tempRobot;
			tempRobot = fun(tempRobot, dimension);
			if (tempRobot<0 || tempRobot>=size)
				break;
			if (board[tempRobot]== 0|| board[tempRobot] == 2)
			{
				distances[i]++;
				if (board[tempRobot] == 2)
				{
					founded = i;
					std::cout << "Founded\n";
					break;
				}
				if((tempRobot%dimension==0&&(previousRobot+1)%dimension==0) || (previousRobot % dimension == 0 && (tempRobot + 1) % dimension == 0))
					break;
			}
		}
	}


	int rightEdge = dimension - (robot % dimension)-1;
	int leftEdge = dimension - rightEdge -1;
	distances[1] = distances[1] > rightEdge ? rightEdge : distances[1];
	distances[6] = distances[6] > leftEdge ? leftEdge : distances[6];

	if (founded != -1)
	{
		auto fun = robotMoves.find(directions[founded])->second;
		int tempRobot = robot;
		for (int i = 0; i < distances[founded]; i++)
		{
			tempRobot = fun(tempRobot, dimension);
		}
		if (board[tempRobot] == 2)
		{
			currentDirection = directions[founded];
			state = AlgoState::FINISHED_SUCCESS;
			return { RobotAction::SUCESS,distances[founded] };
		}
	}
	
	int longest = std::max_element(distances.begin(), distances.end()) - distances.begin();
	auto fun = robotMoves.find(directions[longest])->second;
	int tempRobot = robot;
	for (int i = 0; i < distances[longest]; i++)
	{
		tempRobot = fun(tempRobot, dimension);
	}
	currentDirection = directions[longest];
	return { RobotAction::MOVE,distances[longest] };
}


std::vector<unsigned int> FindingWay::MakeAMove(int robot,int distance,int dimension, std::vector<unsigned int> board)
{
	auto fun = this->robotMoves.find(currentDirection)->second;
	
	while (distance > 0)
	{
		board[robot] = 4;
		robot = fun(robot, dimension);
		distance--;
	}
	board[robot] = 3;
	currentDirection = Direction::NONE;
	return board;
}

std::vector<double> FindingWay::Perform(std::vector<double> data)
{
	return data;
}

AlgoType FindingWay::Type()
{
	return type;
}

AlgoState FindingWay::State()
{
	return state;
}

void FindingWay::ClearMemory()
{
	state = AlgoState::NONE;
	currentDirection = Direction::NONE;
}
