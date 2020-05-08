#include "Training.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "PauseMenu.h"
#include "SacoTimer.h"
#include "PunchingBagOnHit.h"
#include "FloorOnHit.h"
#include "UITransform.h"
#include "UITimer.h"
#include "UIHealthbar.h"
#include "CharFactory.h"

Training::Training(App* app) : GameState(app)
{
	init();
}

void Training::init()
{
	GameState::init();
	doStep = true;
	entManager_.setHandler(CharFactory::addCharacterToGame(app_, this, 1, world, &app_->getGameManager()->getPlayerInfo(1), PLAYER_1, BOUNDARY | P_BAG | WALLS, 0), ecs::Player1);
	entManager_.setHandler(CharFactory::addCharacterToGame(app_, this, -1, world, &app_->getGameManager()->getPlayerInfo(2), PLAYER_2, BOUNDARY | P_BAG | WALLS, 1), ecs::Player2);
	
	Entity* saco = entManager_.addEntity();
	PhysicsTransform* pBpT = saco->addComponent<PhysicsTransform>(Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h - 455), Vector2D(10, 10), 150, 500, 0, world, P_BAG, PLAYER_1 | PLAYER_2 | BULLET, 2);
	addHurtbox(pBpT->getMainFixture());
	pBpT->resetUserData(new PunchingBagOnHit(saco));
	pBpT->changeFriction(0);
	//addHurtbox()
	saco->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
	//saco->addComponent<PunchingBagOnHit>();
	Health* sacoHealth = saco->addComponent<Health>(200);
	//saco->addComponent<SacoTimer>(5000);
	entManager_.setHandler(saco, ecs::Saco);
	
	Entity* timer = entManager_.addEntity();
	timer->addComponent<UITransform>(Vector2D(0, 120), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(200, 50), Vector2D(400, 100));
	timer->addComponent<TextComponent>("0000", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 45, TextComponent::Center);
	timer->addComponent<UITimer>(UITimer::Minutes);

	Entity* healthbarBack = entManager_.addEntity();
	healthbarBack->addComponent<UITransform>(Vector2D(0, 40), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(850, 20), Vector2D(1700, 40));
	healthbarBack->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::HealthbarBack));

	Entity* healthbarL = entManager_.addEntity();
	healthbarL->addComponent<UITransform>(Vector2D(0, 40), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(0, 20), Vector2D(850, 40));
	healthbarL->addComponent<UIHealthbar>(sacoHealth, app_->getAssetsManager()->getTexture(AssetsManager::HealthbarSaco));
	Entity* healthbarR = entManager_.addEntity();
	healthbarR->addComponent<UITransform>(Vector2D(0, 40), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(850, 20), Vector2D(850, 40));
	healthbarR->addComponent<UIHealthbar>(sacoHealth, app_->getAssetsManager()->getTexture(AssetsManager::HealthbarSaco), true);

	Entity* character1 = entManager_.addEntity();
	character1->addComponent<UITransform>(Vector2D(100, 70), Vector2D(), Vector2D(70, 70), Vector2D(140, 140));
	character1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::CharacterSelection))->setFrame(2, 0);
	Entity* character2 = entManager_.addEntity();
	character2->addComponent<UITransform>(Vector2D(-100, 70), Vector2D(app_->getWindowManager()->getCurResolution().w, 0), Vector2D(70, 70), Vector2D(140, 140));
	character2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::CharacterSelection))->setFrame(2, 0);

	Entity* floor = entManager_.addEntity();
	PhysicsTransform* FpT = floor->addComponent<PhysicsTransform>(Vector2D(960, 1100), Vector2D(0, 0), 1920, 450, 0, world, BOUNDARY, EVERYTHING, 2);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
	//floor->addComponent<FloorOnHit>();

	//Walls
	Entity* wall1 = entManager_.addEntity();
	PhysicsTransform* W1pT = wall1->addComponent<PhysicsTransform>(Vector2D(-50, 540), Vector2D(0, 0), 100, 1080, 0, world, WALLS, EVERYTHING, 2);
	W1pT->changeFriction(0);

	Entity* wall2 = entManager_.addEntity();
	PhysicsTransform* W2pT = wall2->addComponent<PhysicsTransform>(Vector2D(1970, 540), Vector2D(0, 0), 100, 1080, 0, world, WALLS, EVERYTHING, 2);
	W2pT->changeFriction(0);

}

void Training::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getGameManager()->pressedStart();
	}
	GameState::handleInput();
}

Training::~Training()
{
}