#include "FactoryMk.h"
#include "App.h"
#include "PhysicsTransform.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "Crouch.h"
#include "PlayerAttacks.h"
#include "PlayerState.h"
#include "Health.h"
#include "PlayerOnHit.h"
#include "MkWH00PData.h"
Entity* FactoryMk::addMkToGame(App* app, GameState* state, int orientation, std::vector<SDL_Scancode> keys, b2World* world,uint16 cBits, uint16 mBits, bool dyn, int playerNumber)
{
	Entity* e = state->getEntityManager().addEntity();
	PhysicsTransform* pT = e->addComponent<PhysicsTransform>(Vector2D(-orientation * 100 + 960, 600), Vector2D(0, 0), 500, 500, 0, world,cBits, mBits, dyn);
	pT->setOrientation(orientation);
	pT->setColliderWidth(pT->getWidth() / 2);
	state->addHurtbox(pT->getMainFixture());

	PlayerController* pC =e->addComponent<PlayerController>(keys[0], keys[1], keys[8], -1500, keys[2], keys[3]);
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::Player));
	//e->addComponent<Jump>(-1000, keys[2]);
	//e->addComponent<Crouch>(keys[3]);
	e->addComponent<PlayerState>();
	Health* h = e->addComponent<Health>(110);
	e->addComponent<PlayerOnHit>();
	PlayerData* p_data_ = e->addComponent<MkWH00PData>(keys, pT->getWidth(), pT->getHeight(), pT->getRotation(), pC->getJumpImpulse(), Vector2D(-orientation * 100 + 200, 10), pT->getSpeed(), h->getHealth(), 50, 50, playerNumber);

	
	//std::vector<AnimationChain*> chains = app_->getAssetsManager()->getMoveParser()->parseFile("../../../../assets/Assets/Config/MovesMK.txt");
	e->addComponent<PlayerAttacks>(p_data_->getNormal_punch(), p_data_->air_normal_punch(), keys[4], p_data_->getHard_punch(), p_data_->air_hard_punch(), keys[5], p_data_->getNormal_kick(), p_data_->air_normal_kick(), keys[6], p_data_->getHard_kick(), p_data_->air_hard_kick(), keys[7],p_data_->guard_breaker(), keys[9], keys[10], keys[11]);

	return e;
}

