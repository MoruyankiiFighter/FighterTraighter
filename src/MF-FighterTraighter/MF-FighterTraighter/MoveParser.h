#pragma once
#include "AnimationChain.h"

class MoveParser
{
public:
	MoveParser() {};
	~MoveParser() {};

	std::vector<AnimationChain*> parseFile(string filePath);
};

