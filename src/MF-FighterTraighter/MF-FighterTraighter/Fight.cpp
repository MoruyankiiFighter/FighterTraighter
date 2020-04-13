#include "Fight.h"
#include "FloorOnHit.h"
#include "UITimer.h"
#include "UITransform.h"
#include "Health.h"
#include "UIHealthbar.h"
#include "UIRoundRenderer.h"
#include "AbilityFactory.h"

Fight::Fight(App* app) : GameState(app)
{
	init();
}

void Fight::init()
{
	world = new b2World(b2Vec2(0.0f, 18.0f));//inicializamos el mundo para las fisicas de b2D
	//---------Debuggear hitbox-------------------------------------------
	debugInstance = new SDLDebugDraw(app_->getRenderer());
	world->SetDebugDraw(debugInstance);
	debugInstance->SetFlags(b2Draw::e_aabbBit);
	//---------------------------------------------------------------
	resJumpListener = new ResetJumpListener();
	world->SetContactListener(resJumpListener);
	
	//Floor
	Entity* floor = entManager_.addEntity();
	PhysicsTransform* FpT = floor->addComponent<PhysicsTransform>(Vector2D(960, 1100), Vector2D(0,0), 1920, 450, 0, world, BOUNDARY, EVERYTHING, false);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
	//floor->addComponent<FloorOnHit>();
	app_->getHitboxMng()->addFloorHitbox(FpT->getMainFixture());

	//Walls
	Entity* wall1 = entManager_.addEntity();
	PhysicsTransform* W1pT = wall1->addComponent<PhysicsTransform>(Vector2D(-50, 540), Vector2D(0, 0), 100, 1080, 0, world, BOUNDARY, EVERYTHING, false);
	app_->getHitboxMng()->addFloorHitbox(W1pT->getMainFixture());

	Entity* wall2 = entManager_.addEntity();
	PhysicsTransform* W2pT = wall2->addComponent<PhysicsTransform>(Vector2D(1970, 540), Vector2D(0, 0), 100, 1080, 0, world, BOUNDARY, EVERYTHING, false);
	app_->getHitboxMng()->addFloorHitbox(W2pT->getMainFixture());

	//Player 1
	Entity* player1 = FactoryMk::addMkToGame(app_, this, world, 1, { SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_Q, SDL_SCANCODE_E, SDL_SCANCODE_Z, SDL_SCANCODE_X, 
		SDL_SCANCODE_SPACE, SDL_SCANCODE_R, SDL_SCANCODE_1, SDL_SCANCODE_2, }, PLAYER_1, PLAYER_2 | BOUNDARY);
	player1->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->setAbility(AbilityFactory::GiveMegatonGrip(player1), 0);

	//Player 2
	Entity* player2 = FactoryMk::addMkToGame(app_, this, world, -1, { SDL_SCANCODE_J, SDL_SCANCODE_L, SDL_SCANCODE_I, SDL_SCANCODE_K, SDL_SCANCODE_U, SDL_SCANCODE_O, SDL_SCANCODE_N, SDL_SCANCODE_M, 
		SDL_SCANCODE_0, SDL_SCANCODE_H, SDL_SCANCODE_8, SDL_SCANCODE_9 }, PLAYER_2, PLAYER_1 | BOUNDARY);

	Entity* timer = entManager_.addEntity();
	timer->addComponent<UITransform>(Vector2D(0, 75), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(200, 50), Vector2D(400, 100));
	timer->addComponent<TextComponent>("0000", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 45, TextComponent::Center);
	timer->addComponent<UITimer>(UITimer::Minutes);

	Entity* healthbarBack1 = entManager_.addEntity();
	healthbarBack1->addComponent<UITransform>(Vector2D(470, 50), Vector2D(0, 0), Vector2D(345, 20), Vector2D(690, 40));
	healthbarBack1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::HealthbarBack));
	Entity* healthbar1 = entManager_.addEntity();
	healthbar1->addComponent<UITransform>(Vector2D(470, 50), Vector2D(0, 0), Vector2D(345, 20), Vector2D(690, 40));
	healthbar1->addComponent<UIHealthbar>(player1->getComponent<Health>(ecs::Health), app_->getAssetsManager()->getTexture(AssetsManager::Healthbar), true);

	Entity* healthbarBack2 = entManager_.addEntity();
	healthbarBack2->addComponent<UITransform>(Vector2D(-470, 50), Vector2D(app_->getWindowManager()->getCurResolution().w, 0), Vector2D(345, 20), Vector2D(690, 40));
	healthbarBack2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::HealthbarBack));
	Entity* healthbar2 = entManager_.addEntity();
	healthbar2->addComponent<UITransform>(Vector2D(-470, 50), Vector2D(app_->getWindowManager()->getCurResolution().w, 0), Vector2D(345, 20), Vector2D(690, 40));
	healthbar2->addComponent<UIHealthbar>(player2->getComponent<Health>(ecs::Health), app_->getAssetsManager()->getTexture(AssetsManager::Healthbar));

	std::vector<Entity*> leftCounter;
	std::vector<Entity*> rightCounter;
	// Make a factory or something
	for (int i = 0; i < 3; ++i) {
		Entity* roundCounter1 = entManager_.addEntity();
		roundCounter1->addComponent<UITransform>(Vector2D(-173 - i * 40, 93), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(18, 18), Vector2D(36, 36));
		roundCounter1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::RoundCounter));
		leftCounter.push_back(roundCounter1);
		Entity* roundCounter2 = entManager_.addEntity();
		roundCounter2->addComponent<UITransform>(Vector2D(173 + i * 40, 93), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(18, 18), Vector2D(36, 36));
		roundCounter2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::RoundCounter));
		rightCounter.push_back(roundCounter2);
	}
	// Should be like a manager, or something
	Entity* gameController = entManager_.addEntity();
	gameController->addComponent<UIRoundRenderer>(leftCounter)->setRoundsWon(3);
	gameController->addComponent<UIRoundRenderer>(rightCounter);
}

void Fight::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->pushState(new PauseMenu(app_));
	}
	else
		GameState::handleInput();
}

void Fight::update()
{
	GameState::update();
	app_->getHitboxMng()->update();		//es posible que esto sea un sistema

	world->Step(1.0 / 30, 8, 3);//update box2d


}

void Fight::render() {
	SDL_RenderClear(app_->getRenderer());
	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		(*it)->render();
	}
	world->DrawDebugData();
	SDL_RenderPresent(app_->getRenderer());
}

Fight::~Fight()
{
	/*for (auto vec : vecMov) {
		delete vec;
	}*/
	app_->getHitboxMng()->clear();

	delete world;
	delete debugInstance;
	delete resJumpListener;
}
