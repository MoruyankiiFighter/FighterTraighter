#include "FactoryMk.h"
#include "App.h"
#include "PhysicsTransform.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "Crouch.h"
#include "PlayerAttacks.h"

Entity* FactoryMk::addMkToGame(App* app, GameState* state, b2World* world, uint16 cBits, uint16 mBits)
{
	Entity* e = state->giveMeManager().addEntity();
	e->addComponent<PhysicsTransform>(Vector2D(10, 10), Vector2D(10, 10), 50, 50, 0, world, cBits, mBits);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(0));
	e->addComponent<Jump>(-1000);
	e->addComponent<Crouch>();

	std::vector<Move*> vecMov = std::vector<Move*>(2);
	vecMov[0] = new Move(100, nullptr, moveHurt, e);
	vecMov[1] = new Move(50, nullptr, nullptr, e);
	AnimationChain* testNP = new AnimationChain(vecMov);
	AnimationChain* testHP = new AnimationChain(vecMov);
	AnimationChain* testNK = new AnimationChain(vecMov);
	AnimationChain* testHK = new AnimationChain(vecMov);
	//std::vector<AnimationChain*> chains = app_->getAssetsManager()->getMoveParser()->parseFile("../../../../assets/Assets/Config/MovesMK.txt");
	e->addComponent<PlayerAttacks>(testNP, SDL_SCANCODE_Q, testHP, SDL_SCANCODE_E, testNK, SDL_SCANCODE_Z, testHK, SDL_SCANCODE_X);

	return e;
}

//Esto es para geenrar hitboxes, habrá uno para cada hitbox generada
void FactoryMk::moveHurt(Entity* ent)
{
	std::cout << "Golpe" << endl;
	//ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	ent->getApp()->getHitboxMng()->addHitbox({ 200,0 }, 50, 50, 500, 50, ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody());
}
