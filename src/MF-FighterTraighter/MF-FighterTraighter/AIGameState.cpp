#include "AIGameState.h"
#include "CharFactory.h"
#include "PhysicsTransform.h"
#include "AILogic.h"
#include "PlayerAttacks.h"
#include "F10RData.h"
#include "AIHID.h"
#include "AIController.h"
#include "AIAttacks.h"
#include "PlayerOnHit.h"
#include "Health.h"
#include "PlayerAnimation.h"

void AIGameState::init()
{
	GameState::init();
	doStep = true;

	//delete app_->getGameManager()->getPlayerInfo(2).hid;
	//*app_->getGameManager()->getPlayerInfo(2).hid = AIHID();

	//Floor
	Entity* floor = entManager_.addEntity();
	PhysicsTransform* FpT = floor->addComponent<PhysicsTransform>(Vector2D(960, 1200), Vector2D(0, 0), 1920, 450, 0, world, BOUNDARY, EVERYTHING, 2);
	/*floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));*/
	//floor->addComponent<FloorOnHit>();
	FpT->changeFriction(3);
	addHurtbox(FpT->getMainFixture());
	//Walls
	Entity* wall1 = entManager_.addEntity();
	PhysicsTransform* W1pT = wall1->addComponent<PhysicsTransform>(Vector2D(-50, 540), Vector2D(0, 0), 100, 1080, 0, world, WALLS, EVERYTHING, 2);
	W1pT->changeFriction(0);
	Entity* wall2 = entManager_.addEntity();
	PhysicsTransform* W2pT = wall2->addComponent<PhysicsTransform>(Vector2D(1970, 540), Vector2D(0, 0), 100, 1080, 0, world, WALLS, EVERYTHING, 2);
	W2pT->changeFriction(0);

	Entity* player1 = CharFactory::addCharacterToGame(app_, this, 1, world, &app_->getGameManager()->getPlayerInfo(1),
		PLAYER_1, PLAYER_2 | WALLS | BOUNDARY | BULLET, 0);
	entManager_.setHandler(player1, ecs::Player1);


	Entity* AI = entManager_.addEntity();
	PhysicsTransform* pT = AI->addComponent<PhysicsTransform>(Vector2D(1400, 700), Vector2D(), 500, 500, 0, world, PLAYER_2, PLAYER_1 | WALLS | BOUNDARY | BULLET, 0);
	pT->resetUserData(new PlayerOnHit(AI));
	pT->setOrientation(-1);
	pT->setColliderWidth(pT->getWidth() / 2);
	pT->getBody()->SetLinearDamping(10);	//friction
	addHurtbox(pT->getMainFixture());
	int orientation = pT->getOrientation();
	AI->addComponent<AILogic>(ecs::Player2, 5, Vector2D(400, 550));
	AI->addComponent<PlayerState>();
	AI->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::F10rSheet));
	AIController* aC = AI->addComponent<AIController>(-7, 4.5);
	PlayerData* pdata = AI->addComponent<F10RData>(pT->getWidth(), pT->getHeight(), pT->getRotation(), -7, Vector2D(-orientation * 100.0 + 200, 10), 4.5, 100, 1, 1, 1);
	AI->addComponent<AIAttacks>(pdata->getNormal_punch(), pdata->air_normal_punch(), pdata->getHard_punch(), pdata->air_hard_punch(),
		pdata->getNormal_kick(), pdata->air_normal_kick(), pdata->getHard_kick(), pdata->air_hard_kick(), pdata->guard_breaker());
	AI->addComponent<PlayerParticleSystem>(10);
	pT->resetUserData(new PlayerOnHit(AI));
	AI->addComponent<Health>(100);
	AI->addComponent<PlayerAnimation>();
	entManager_.setHandler(AI, ecs::Player2);
}

void AIGameState::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->Exit();
	}
	else GameState::handleInput();
}
