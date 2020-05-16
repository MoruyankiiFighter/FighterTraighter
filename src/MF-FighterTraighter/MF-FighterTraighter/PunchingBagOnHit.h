#pragma once
#include "UserData.h"


class PunchingBagOnHit : public UserData
{
public:
	PunchingBagOnHit(Entity* e) : UserData(e) {}
	~PunchingBagOnHit() {}
	void onHit(b2Fixture* other) override;
private:
	int winner;
};

