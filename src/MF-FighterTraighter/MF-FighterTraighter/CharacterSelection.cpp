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
	// background

	Entity* background_ = entManager_.addEntity();
	background_->addComponent<Transform>(Vector2D(), Vector2D(), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h, 0);
	background_->addComponent<RenderAnimation>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight), 20);

	//panel

	Entity* centralP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Panel),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 8.5, 50), Vector2D(app_->getWindowManager()->getCurResolution().w / 5, 50),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 5, 50), (app_->getWindowManager()->getCurResolution().w / 20) * 16,
		(app_->getWindowManager()->getCurResolution().h / 15) * 10, 0);

	Entity* text_ = UIFactory::createText(app_, this, Vector2D(app_->getWindowManager()->getCurResolution().w / 3, 0), Vector2D(app_->getWindowManager()->getCurResolution().w/2, 0), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "Choose your character", 60, 300, 100, 500);

	//artwork of the character
	Entity* leftP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Banner),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, 100), Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, 100),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, 100), (app_->getWindowManager()->getCurResolution().w / 30) * 6, (app_->getWindowManager()->getCurResolution().h / 15) * 10, 0);

	Entity* rightP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Banner),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 20.5, 100),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 19.5, 100), Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 19.5, 100),
		(app_->getWindowManager()->getCurResolution().w / 30) * 6, (app_->getWindowManager()->getCurResolution().h / 15) * 10, 0);
	rightP_->getComponent<UITransform>(ecs::Transform)->setOrientation(-1);

	// buttons
	tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(60, -30),
		Vector2D(0, app_->getWindowManager()->getCurResolution().h),
		Vector2D(0, 100),
		300, 100, 0,
		nullptr, GoToFight, "Ready", 60, TextComponent::TextAlignment::Center);

	tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(-60, -30),
		Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h),
		Vector2D(300, 100),
		300, 100,
		0, nullptr, nullptr, "Ready", 60, TextComponent::TextAlignment::Center);

	//icons of the character
	tuple <Entity*, Entity*> flor_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Flor_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 6, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 6, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 6, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, setFlor, " ", 120, TextComponent::TextAlignment::Center);

	tuple <Entity*, Entity*> mkwhoop_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Ganonbot_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 9.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 9.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 9.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, setGanonbot, " ", 120, TextComponent::TextAlignment::Center);

	tuple <Entity*, Entity*> aisha_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Aisha_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 13, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 13, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 13, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, setAisha, " ", 120, TextComponent::TextAlignment::Center);

	tuple <Entity*, Entity*> mockinbird_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mock_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, setMockingBird, " ", 120, TextComponent::TextAlignment::Center);

	Entity* text_j1 = UIFactory::createText(app_, this, Vector2D(60, -30),
		Vector2D(0, app_->getWindowManager()->getCurResolution().h / 4 * 3),
		Vector2D(0, 50),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "description_ j1", 25,
		100, 100, 25);
	Entity* text_j2 = UIFactory::createText(app_, this, Vector2D(-360, -30),
		Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h / 4 * 3),
		Vector2D(0, 50),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "description_ j2", 25,
		100, 100, 25);

	//Entitys
	Entity* nav = entManager_.addEntity();
	NavigationController* ctrl = nav->addComponent<NavigationController>(4, 2, app_->getGameManager()->getPlayerInfo(1).hid);
	ctrl->SetElementInPos(std::get<0>(flor_)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl->SetElementInPos(std::get<0>(mkwhoop_)->getComponent<UIElement>(ecs::UIElement), 1, 0);
	ctrl->SetElementInPos(std::get<0>(aisha_)->getComponent<UIElement>(ecs::UIElement), 2, 0);
	ctrl->SetElementInPos(std::get<0>(mockinbird_)->getComponent<UIElement>(ecs::UIElement), 3, 0);
	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 0, 1);

	Entity* nav_ = entManager_.addEntity();
	NavigationController* ctrl_ = nav_->addComponent<NavigationController>(4, 2, app_->getGameManager()->getPlayerInfo(2).hid);
	ctrl_->SetElementInPos(std::get<0>(flor_)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl_->SetElementInPos(std::get<0>(mkwhoop_)->getComponent<UIElement>(ecs::UIElement), 1, 0);
	ctrl_->SetElementInPos(std::get<0>(aisha_)->getComponent<UIElement>(ecs::UIElement), 2, 0);
	ctrl_->SetElementInPos(std::get<0>(mockinbird_)->getComponent<UIElement>(ecs::UIElement), 3, 0);
	ctrl_->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 0, 1);


	//logic of that for changing the artwork of each player 
	Entity* logic = entManager_.addEntity();
	logic->addComponent<CharacterSelectionLogic>(1,text_j1->getComponent<TextComponent>(ecs::TextComponent), leftP_->getComponent<RenderImage>(ecs::RenderImage), aisha_desc, mkwhoop_desc, flor_desc, mock_desc, nav->getComponent<NavigationController>(ecs::NavigationController),
		std::get<0>(aisha_)->getComponent<UIElement>(ecs::UIElement), std::get<0>(flor_)->getComponent<UIElement>(ecs::UIElement), std::get<0>(mkwhoop_)->getComponent<UIElement>(ecs::UIElement), std::get<0>(mockinbird_)->getComponent<UIElement>(ecs::UIElement),
		app_->getAssetsManager()->getTexture(AssetsManager::AishaArtwork), app_->getAssetsManager()->getTexture(AssetsManager::FlorArtwork), app_->getAssetsManager()->getTexture(AssetsManager::GanonArtwork), app_->getAssetsManager()->getTexture(AssetsManager::MockArtwork));
	Entity* logic_ = entManager_.addEntity();
	logic_->addComponent<CharacterSelectionLogic>(2,text_j2->getComponent<TextComponent>(ecs::TextComponent), rightP_->getComponent<RenderImage>(ecs::RenderImage), aisha_desc, mkwhoop_desc, flor_desc, mock_desc, nav_->getComponent<NavigationController>(ecs::NavigationController),
		std::get<0>(aisha_)->getComponent<UIElement>(ecs::UIElement), std::get<0>(flor_)->getComponent<UIElement>(ecs::UIElement), std::get<0>(mkwhoop_)->getComponent<UIElement>(ecs::UIElement), std::get<0>(mockinbird_)->getComponent<UIElement>(ecs::UIElement),
		app_->getAssetsManager()->getTexture(AssetsManager::AishaArtwork), app_->getAssetsManager()->getTexture(AssetsManager::FlorArtwork), app_->getAssetsManager()->getTexture(AssetsManager::GanonArtwork), app_->getAssetsManager()->getTexture(AssetsManager::MockArtwork));
}



void CharacterSelection::setAisha(App* app)
{
	//preguntar player
	
	app->getGameManager()->setCharacter(app->getGameManager()->Aisha, 1);
	cout << app->getGameManager()->getPlayerInfo(1).character;
}

void CharacterSelection::setFlor(App* app)
{

	//preguntar player
	app->getGameManager()->setCharacter(app->getGameManager()->F10R,1);
	cout << app->getGameManager()->getPlayerInfo(1).character;
}

void CharacterSelection::setGanonbot(App* app)
{

	//preguntar player
	app->getGameManager()->setCharacter(app->getGameManager()->MKWh00p, 1);
	cout << app->getGameManager()->getPlayerInfo(1).character;
}

void CharacterSelection::setMockingBird(App* app)
{
	//preguntar player
	app->getGameManager()->setCharacter(app->getGameManager()->Mockingbird,1);
	cout << app->getGameManager()->getPlayerInfo(1).character;
}

void CharacterSelection::setRandomCharacter(App* app)
{
	//generar un random
	int n = 3;

	switch (n) {
	case 0:
		app->getGameManager()->setCharacter(app->getGameManager()->F10R,1);
		break;
	case 1:
		app->getGameManager()->setCharacter(app->getGameManager()->Aisha,1);
		break;
	case 2:
		app->getGameManager()->setCharacter(app->getGameManager()->MKWh00p,1);
		break;
	case 3:
		app->getGameManager()->setCharacter(app->getGameManager()->Mockingbird,1);
		break;
	default:
		app->getGameManager()->setCharacter(app->getGameManager()->None,1);
	}
}

void CharacterSelection::GoToFight(App* app)
{
	if (app->getGameManager()->getPlayerInfo(1).character != app->getGameManager()->None) {

		app->getStateMachine()->pushState(new Fight(app));
	}
}
