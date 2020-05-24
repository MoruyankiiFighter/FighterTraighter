#pragma once
#include "FightController.h"
class ArcadeController : public FightController
{

public:
	ArcadeController(int roundIniTime, int roundEndTime, int round=0) : FightController(roundIniTime, roundEndTime), round_(round) {}

	
	virtual ~ArcadeController() {}
protected:
	void end() override;
	void disablePlayers(bool mode) override;
	int round_;

};

