#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"

class Fight: public GameState
{
public:
	Fight(App* app);
	void init() override;
	virtual void update() override;
	virtual void render() override;
	virtual ~Fight();
private:
	b2Body* body_;
	b2Body* body2_;

	b2World* world;
	//void drawSquare(b2Vec2 points [4], b2Vec2 GetWorldCenter(), float32 GetAngle());

	b2Body* addRect(int x, int y, int w, int h, bool dyn=true);
};

