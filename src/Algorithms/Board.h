#pragma once
#include "Strategy.h"
#include <iostream>

class Board {
public:
	virtual AlgoState PerformAlgorithm()=0;
	virtual void SetAlgorithm(AlgoType type)=0;

	virtual FieldRepresentation Representation()=0;
	virtual AlgoType GetAlgorithm()=0;
	virtual std::vector<unsigned int> GetCurrentState()=0; //SDF is not represented as double here, but by inside, outside, border
	//~Board();
};


class BoardImplementation: public Board {
public:
	AlgoState PerformAlgorithm() override;
	void SetAlgorithm(AlgoType type) override;
	void LoadNewData(std::vector<unsigned int> data);
	void ClearAlgorithm();

	AlgoType GetAlgorithm() override;
	FieldRepresentation  Representation() override;

	std::vector<unsigned int> GetCurrentState() override;
	
	BoardImplementation(std::shared_ptr<AlgorithmsKeeper> strategy, std::vector<unsigned int> input );
	BoardImplementation() = default;
private:
	std::vector<unsigned int> OutputRepresentation();

private:
	std::vector<unsigned int> matrix;
	std::shared_ptr<AlgorithmsKeeper> algorithmGetter=nullptr;
	std::shared_ptr<Algorithm> algo=nullptr;
	FieldRepresentation representation= FieldRepresentation::NONE;
};
