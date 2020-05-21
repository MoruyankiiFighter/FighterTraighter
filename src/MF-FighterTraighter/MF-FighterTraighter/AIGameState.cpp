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

	//Entity* AI1 = CharFactory::addAICharacterToGame(app_, this, 1, world, GameManager::F10R, 5, Vector2D(350, 450),
	//	PLAYER_1, PLAYER_2 | WALLS | BOUNDARY | BULLET, 0);
	//entManager_.setHandler(AI1, ecs::Player1);

	Entity* AI2 = CharFactory::addAICharacterToGame(app_, this, -1, world, GameManager::F10R, 500, Vector2D(350, 450),
		PLAYER_2, PLAYER_1 | WALLS | BOUNDARY | BULLET, 1);
	entManager_.setHandler(AI2, ecs::Player2);
}

void AIGameState::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->Exit();
	}
	else GameState::handleInput();
}
