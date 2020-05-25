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
#include "RenderAnimation.h"
#include "Shake.h"
#include "Camera.h"
#include "UIHealthbar.h"
#include "UITransform.h"

void AIGameState::init()
{
	GameState::init();
	doStep = true;

	//delete app_->getGameManager()->getPlayerInfo(2).hid;
	//*app_->getGameManager()->getPlayerInfo(2).hid = AIHID();

	// Background
	Entity* bg = entManager_.addEntity();
	bg->addComponent<Transform>(Vector2D(), Vector2D(), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h, 0);
	bg->addComponent<RenderAnimation>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFloor), 20);
	bg->addComponent<Shake>();

	entManager_.setHandler(bg, ecs::Camara);

	// Floor
	Entity* floor = entManager_.addEntity();
	PhysicsTransform* FpT = floor->addComponent<PhysicsTransform>(Vector2D(960, 1200), Vector2D(0, 0), 1920, 450, 0, world, BOUNDARY, EVERYTHING, 2);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::TextureNames::floorIA));
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

	Entity* AI2 = CharFactory::addAICharacterToGame(app_, this, -1, world, GameManager::F10R, 5, Vector2D(350, 450),
		PLAYER_2, PLAYER_1 | WALLS | BOUNDARY | BULLET, 1);
	entManager_.setHandler(AI2, ecs::Player2);

	// Background camera
	bg->addComponent<Camera>(player1->getComponent<Transform>(ecs::Transform), AI2->getComponent<Transform>(ecs::Transform));

	// Healthbar Player1
	Entity* healthbarBack1 = entManager_.addEntity();
	healthbarBack1->addComponent<UITransform>(Vector2D(460, 50), Vector2D(0, 0), Vector2D(365, 20), Vector2D(730, 40));
	healthbarBack1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::HealthbarBack));
	Entity* healthbar1 = entManager_.addEntity();
	healthbar1->addComponent<UITransform>(Vector2D(460, 50), Vector2D(0, 0), Vector2D(365, 20), Vector2D(730, 40));
	healthbar1->addComponent<UIHealthbar>(player1->getComponent<Health>(ecs::Health), app_->getAssetsManager()->getTexture(AssetsManager::Healthbar), true);
	// Player1 icon
	Entity* character1 = entManager_.addEntity();
	character1->addComponent<UITransform>(Vector2D(70, 70), Vector2D(), Vector2D(70, 70), Vector2D(140, 140));
	RenderImage* charIcon1 = character1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::CharacterSelection));
	switch (app_->getGameManager()->getPlayerInfo(1).character) {
	case GameManager::Aisha: charIcon1->setFrame(0, 0); break;
	case GameManager::Mockingbird: charIcon1->setFrame(3, 0); break;
	case GameManager::MKWh00p: charIcon1->setFrame(2, 0); break;
	case GameManager::F10R: charIcon1->setFrame(1, 0); break;
	default: break;
	}



	// Healthbar Player2
	Entity* healthbarBack2 = entManager_.addEntity();
	healthbarBack2->addComponent<UITransform>(Vector2D(-460, 50), Vector2D(app_->getWindowManager()->getCurResolution().w, 0), Vector2D(365, 20), Vector2D(730, 40));
	healthbarBack2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::HealthbarBack));
	Entity* healthbar2 = entManager_.addEntity();
	healthbar2->addComponent<UITransform>(Vector2D(-460, 50), Vector2D(app_->getWindowManager()->getCurResolution().w, 0), Vector2D(365, 20), Vector2D(730, 40));
	healthbar2->addComponent<UIHealthbar>(AI2->getComponent<Health>(ecs::Health), app_->getAssetsManager()->getTexture(AssetsManager::Healthbar));
	Entity* character2 = entManager_.addEntity();
	character2->addComponent<UITransform>(Vector2D(-70, 70), Vector2D(app_->getWindowManager()->getCurResolution().w, 0), Vector2D(70, 70), Vector2D(140, 140));
	RenderImage* charIcon2 = character2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::CharacterSelection));
	switch (app_->getGameManager()->getPlayerInfo(2).character) {
	case GameManager::Aisha: charIcon2->setFrame(0, 0); break;
	case GameManager::Mockingbird: charIcon2->setFrame(3, 0); break;
	case GameManager::MKWh00p: charIcon2->setFrame(2, 0); break;
	case GameManager::F10R: charIcon2->setFrame(1, 0); break;
	default: break;
	}

}

void AIGameState::handleInput()
{
	/*if (app_->getInputManager()->pressedStart()) {
		app_->Exit();
	}
	else*/ GameState::handleInput();
}
