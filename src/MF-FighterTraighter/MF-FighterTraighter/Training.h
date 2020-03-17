#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"
#include "SDLDebugDraw.h"
#include "PunchingBagListener.h"
#include "Jump.h"
#include "PlayerAttacks.h"
#include <vector>
class Training: public GameState
{
public:
	Training(App* app);
	void init() override;
	virtual void handleInput() override;
	virtual void update() override;
	virtual void render() override;
	virtual ~Training();
	void addToRemove(b2Fixture* fixture);
private:
	int i = 0;
	std::vector<Move*> vecMov;
	b2World* world;
	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
	PunchingBagListener* pbListener = nullptr;
	vector<b2Fixture*> fListRemove;

};

