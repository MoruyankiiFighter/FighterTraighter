#pragma once
#include "UserData.h"

//The punchingBag only has 
class PunchingBagOnHit : public UserData
{
public:
	PunchingBagOnHit(Entity* e) : UserData(e) {}
	~PunchingBagOnHit() {}
	//void onHit(b2Fixture* other) override {}
	//Decide the player who is the winner when its a draw
	virtual int drawWinner() { return 0; }
private:
	int winner;
};

