#pragma once
#include "OnHit.h"
class PlayerOnHit : public OnHit
{
public:
	PlayerOnHit() : OnHit() {}
	~PlayerOnHit() {}
	virtual void onHit(b2Fixture* fixture, b2Fixture* mainfixture) override;
	virtual void onHitAlt(b2Fixture* fixture);
};

