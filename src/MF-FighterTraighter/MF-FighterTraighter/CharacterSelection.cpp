#include "CharacterSelection.h"

#include "Entity.h"
#include "UIFactory.h"
#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"
#include "TextComponent.h"
#include "NavigationController.h"
#include "Font.h"
#include "RenderAnimation.h"
#include "UITransform.h"
#include "CharacterSelectionLogic.h"

#include "Fight.h"
void CharacterSelection::init()
{
	// Background
	Entity* background = entManager_.addEntity();
	background->addComponent<Transform>(Vector2D(), Vector2D(), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h, 0);
	background->addComponent<RenderAnimation>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight), 20);

	// CenterInfo
	Entity* centralP = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Panel),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 8.5, 50), Vector2D(app_->getWindowManager()->getCurResolution().w / 5, 50),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 5, 50), (app_->getWindowManager()->getCurResolution().w / 20) * 16,
		(app_->getWindowManager()->getCurResolution().h / 15) * 10, 0);
	Entity* text = UIFactory::createText(app_, this, Vector2D(app_->getWindowManager()->getCurResolution().w / 3, 0),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "Choose your character", 60, 300, 100, 500);





	// Icons of all characters
	// TODO: change to panels
	Entity* flor = UIFactory::createButton(2, app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Flor_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 6, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 6, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 6, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, nullptr);
	Entity* mkwhoop = UIFactory::createButton(2, app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Ganonbot_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 9.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 9.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 9.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, nullptr);
	Entity* aisha = UIFactory::createButton(2, app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Aisha_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 13, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 13, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 13, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, nullptr);
	Entity* mockinbird = UIFactory::createButton(2, app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mock_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, nullptr);
	Entity* random = UIFactory::createButton(2, app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Random_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, nullptr);




	// TODO: give all characterElements an UITransform to use it to set the selection icon
	// Player 1
	Entity* leftP = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Banner),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, 100), Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, 100),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, 100), (app_->getWindowManager()->getCurResolution().w / 30) * 6,
		(app_->getWindowManager()->getCurResolution().h / 15) * 10, 0);
	Entity* text_j1 = UIFactory::createText(app_, this, Vector2D(60, -30),
		Vector2D(0, app_->getWindowManager()->getCurResolution().h / 4 * 3),
		Vector2D(0, 50),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "description_ j1", 25,
		100, 100, 25);
	Entity* florElement1 = entManager_.addEntity();
	florElement1->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(1).hid);
	Entity* mockElement1 = entManager_.addEntity();
	mockElement1->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(1).hid);
	Entity* MKElement1 = entManager_.addEntity();
	MKElement1->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(1).hid);
	Entity* aishaElement1 = entManager_.addEntity();
	aishaElement1->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(1).hid);
	Entity* randElement1 = entManager_.addEntity();
	randElement1->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(1).hid);
	tuple <Entity*, Entity*> button1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(60, -30),
		Vector2D(0, app_->getWindowManager()->getCurResolution().h),
		Vector2D(0, 100),
		300, 100, 0,
		nullptr, GoToFight, "Ready", 60, TextComponent::TextAlignment::Center);
	Entity* nav1 = entManager_.addEntity();
	NavigationController* ctrl1 = nav1->addComponent<NavigationController>(5, 2, app_->getGameManager()->getPlayerInfo(1).hid);
	ctrl1->SetElementInPos(florElement1->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl1->SetElementInPos(MKElement1->getComponent<UIElement>(ecs::UIElement), 1, 0);
	ctrl1->SetElementInPos(aishaElement1->getComponent<UIElement>(ecs::UIElement), 2, 0);
	ctrl1->SetElementInPos(mockElement1->getComponent<UIElement>(ecs::UIElement), 3, 0);
	ctrl1->SetElementInPos(randElement1->getComponent<UIElement>(ecs::UIElement), 4, 0);
	ctrl1->SetElementInPos(std::get<0>(button1)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	Entity* logic1 = entManager_.addEntity();
	logic1->addComponent<CharacterSelectionLogic>(1, text_j1->getComponent<TextComponent>(ecs::TextComponent), leftP->getComponent<RenderImage>(ecs::RenderImage), aisha_desc, mkwhoop_desc, flor_desc, mock_desc, nav1->getComponent<NavigationController>(ecs::NavigationController),
		(aishaElement1)->getComponent<UIElement>(ecs::UIElement), (florElement1)->getComponent<UIElement>(ecs::UIElement), (MKElement1)->getComponent<UIElement>(ecs::UIElement), (mockElement1)->getComponent<UIElement>(ecs::UIElement), randElement1->getComponent<UIElement>(ecs::UIElement),
		app_->getAssetsManager()->getTexture(AssetsManager::AishaArtwork), app_->getAssetsManager()->getTexture(AssetsManager::FlorArtwork), app_->getAssetsManager()->getTexture(AssetsManager::GanonArtwork), app_->getAssetsManager()->getTexture(AssetsManager::MockArtwork), app_->getAssetsManager()->getTexture(AssetsManager::RandomArtwork));



	// Player 2
	Entity* rightP = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Banner),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 20.5, 100),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 19.5, 100), Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 19.5, 100),
		(app_->getWindowManager()->getCurResolution().w / 30) * 6, (app_->getWindowManager()->getCurResolution().h / 15) * 10, 0);
	rightP->getComponent<UITransform>(ecs::Transform)->setOrientation(-1);
	Entity* text_j2 = UIFactory::createText(app_, this, Vector2D(-360, -30),
		Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h / 4 * 3),
		Vector2D(0, 50),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "description_ j2", 25,
		100, 100, 25);
	Entity* florElement2 = entManager_.addEntity();
	florElement2->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(2).hid);
	Entity* mockElement2 = entManager_.addEntity();
	mockElement2->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(2).hid);
	Entity* MKElement2 = entManager_.addEntity();
	MKElement2->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(2).hid);
	Entity* aishaElement2 = entManager_.addEntity();
	aishaElement2->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(2).hid);
	Entity* randElement2 = entManager_.addEntity();
	randElement2->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(2).hid);
	tuple <Entity*, Entity*> button2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(-60, -30),
		Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h),
		Vector2D(300, 100),
		300, 100,
		0, nullptr, nullptr, "Ready", 60, TextComponent::TextAlignment::Center);
	Entity* nav_ = entManager_.addEntity();
	NavigationController* ctrl2 = nav_->addComponent<NavigationController>(5, 2, app_->getGameManager()->getPlayerInfo(2).hid);
	ctrl2->SetElementInPos((florElement2)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl2->SetElementInPos((MKElement2)->getComponent<UIElement>(ecs::UIElement), 1, 0);
	ctrl2->SetElementInPos((aishaElement2)->getComponent<UIElement>(ecs::UIElement), 2, 0);
	ctrl2->SetElementInPos((mockElement2)->getComponent<UIElement>(ecs::UIElement), 3, 0);
	ctrl2->SetElementInPos((randElement2)->getComponent<UIElement>(ecs::UIElement), 4, 0);
	ctrl2->SetElementInPos(std::get<0>(button2)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	Entity* logic2 = entManager_.addEntity();
	logic2->addComponent<CharacterSelectionLogic>(2, text_j2->getComponent<TextComponent>(ecs::TextComponent), rightP->getComponent<RenderImage>(ecs::RenderImage), aisha_desc, mkwhoop_desc, flor_desc, mock_desc, nav_->getComponent<NavigationController>(ecs::NavigationController),
		(aishaElement2)->getComponent<UIElement>(ecs::UIElement), (florElement2)->getComponent<UIElement>(ecs::UIElement), (MKElement2)->getComponent<UIElement>(ecs::UIElement), (mockElement2)->getComponent<UIElement>(ecs::UIElement), randElement2->getComponent<UIElement>(ecs::UIElement),
		app_->getAssetsManager()->getTexture(AssetsManager::AishaArtwork), app_->getAssetsManager()->getTexture(AssetsManager::FlorArtwork), app_->getAssetsManager()->getTexture(AssetsManager::GanonArtwork), app_->getAssetsManager()->getTexture(AssetsManager::MockArtwork), app_->getAssetsManager()->getTexture(AssetsManager::RandomArtwork));
}

void CharacterSelection::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getGameManager()->pressedStart();
	}
	else
		GameState::handleInput();

}

void CharacterSelection::setAisha(App* app, int n)
{
	app->getGameManager()->setCharacter(app->getGameManager()->Aisha, n);
	cout << app->getGameManager()->getPlayerInfo(1).character;
}

void CharacterSelection::setFlor(App* app, int n)
{
	//preguntar player
	app->getGameManager()->setCharacter(app->getGameManager()->F10R, n);
	cout << app->getGameManager()->getPlayerInfo(1).character;
}

void CharacterSelection::setGanonbot(App* app, int n)
{
	app->getGameManager()->setCharacter(app->getGameManager()->MKWh00p, n);
	cout << app->getGameManager()->getPlayerInfo(1).character;
}

void CharacterSelection::setMockingBird(App* app, int n)
{
	app->getGameManager()->setCharacter(app->getGameManager()->Mockingbird, n);
	cout << app->getGameManager()->getPlayerInfo(1).character;
}

void CharacterSelection::setRandomCharacter(App* app, int n)
{
	//generar un random
	int n_ = 3;

	switch (n_) {
	case 0:
		app->getGameManager()->setCharacter(app->getGameManager()->F10R, n);
		break;
	case 1:
		app->getGameManager()->setCharacter(app->getGameManager()->Aisha, n);
		break;
	case 2:
		app->getGameManager()->setCharacter(app->getGameManager()->MKWh00p, n);
		break;
	case 3:
		app->getGameManager()->setCharacter(app->getGameManager()->Mockingbird, n);
		break;
	default:
		app->getGameManager()->setCharacter(app->getGameManager()->None, n);
	}
}

void CharacterSelection::GoToFight(App* app)
{
	if (app->getGameManager()->getPlayerInfo(1).character != app->getGameManager()->None) {

		app->getStateMachine()->pushState(new Fight(app));
	}
}
