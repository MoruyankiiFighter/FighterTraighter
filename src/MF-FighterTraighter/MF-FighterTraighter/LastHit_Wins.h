#pragma once
#include "PunchingBagOnHit.h"
class LastHit_Wins : public PunchingBagOnHit
{
public:
	LastHit_Wins(Entity* e) : PunchingBagOnHit(e) {}
	~LastHit_Wins() {}
	void onHit(b2Fixture* other) override;
	int drawWinner() override;
private:
	Entity* last_hit;
};

