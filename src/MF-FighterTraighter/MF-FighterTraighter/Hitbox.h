#pragma once
#include "Box2D/Box2D.h"

class hitbox : public b2Fixture
{
public:
	hitbox(int damage,int time,b2Body* body):b2Fixture(),damage_(damage),time_(time),body_(body){
		init();
	}
	~hitbox();
	void init();
	void update();

private:
	int damage_, time_;
	b2Body* body_;

};

