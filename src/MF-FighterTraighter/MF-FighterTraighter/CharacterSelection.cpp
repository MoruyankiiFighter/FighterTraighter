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
void CharacterSelection::init()
{
	// background

	Entity* background_ = entManager_.addEntity();	
	background_->addComponent<Transform>(Vector2D(), Vector2D(), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h, 0);
	background_->addComponent<RenderAnimation>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight), 20);

	//panel

	Entity* centralP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Panel),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 8.5, 50), Vector2D(app_->getWindowManager()->getCurResolution().w /5, 50), 
		Vector2D(app_->getWindowManager()->getCurResolution().w / 5, 50), (app_->getWindowManager()->getCurResolution().w / 20)*16, 
		(app_->getWindowManager()->getCurResolution().h /15)*10, 0);
	
	//artwork of the character
	Entity* leftP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Banner),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) *1, 100), Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, 100), 
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, 100), (app_->getWindowManager()->getCurResolution().w / 30) *6, (app_->getWindowManager()->getCurResolution().h /15)*10, 0);

	Entity* rightP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Banner),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 20.5, 100),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 19.5, 100), Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 19.5, 100),
		(app_->getWindowManager()->getCurResolution().w / 30) * 4.5, (app_->getWindowManager()->getCurResolution().h / 15) * 10, 0);

	// buttons
	tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, (app_->getWindowManager()->getCurResolution().h / 14) * 11.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, (app_->getWindowManager()->getCurResolution().h / 14) * 11.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 1, (app_->getWindowManager()->getCurResolution().h / 14) * 11.5),
		(app_->getWindowManager()->getCurResolution().w / 25) * 4, (app_->getWindowManager()->getCurResolution().h / 25) * 4, 0,
		nullptr, nullptr, "Continue", letra / 2, TextComponent::TextAlignment::Center);

	std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Center;

	tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 20, (app_->getWindowManager()->getCurResolution().h / 14) * 11.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 20, (app_->getWindowManager()->getCurResolution().h / 14) * 11.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 20, (app_->getWindowManager()->getCurResolution().h / 14) * 11.5),
		(app_->getWindowManager()->getCurResolution().w / 25) * 4, (app_->getWindowManager()->getCurResolution().h / 25) * 4,
		0, nullptr, nullptr, "Continue", letra / 2, TextComponent::TextAlignment::Center);

	std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Center;
	
	//icons of the character
	tuple <Entity*, Entity*> flor_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Flor_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 6, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 6, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 6, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3 ,0,
		nullptr, nullptr, " ", letra, TextComponent::TextAlignment::Center);

	tuple <Entity*, Entity*> mkwhoop_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Ganonbot_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 9.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 9.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 9.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, nullptr, " ", letra, TextComponent::TextAlignment::Center);

	tuple <Entity*, Entity*> aisha_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Aisha_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 13, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 13, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 13, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, nullptr, " ", letra, TextComponent::TextAlignment::Center);

	tuple <Entity*, Entity*> mockinbird_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mock_icon), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 16.5, (app_->getWindowManager()->getCurResolution().h / 14) * 2),
		(app_->getWindowManager()->getCurResolution().w / 25) * 3, (app_->getWindowManager()->getCurResolution().h / 14) * 3, 0,
		nullptr, nullptr, " ", letra, TextComponent::TextAlignment::Center);


	
	Entity* text_j1 = UIFactory::createText(app_, this, Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 5, (app_->getWindowManager()->getCurResolution().h / 14) * 7),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 5, (app_->getWindowManager()->getCurResolution().h / 14) * 7),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 5, (app_->getWindowManager()->getCurResolution().h / 14) * 7),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "description_ j1", 30, 
		(app_->getWindowManager()->getCurResolution().w / 25) * 5, (app_->getWindowManager()->getCurResolution().h / 14) * 2);
	
	Entity* text_j2 = UIFactory::createText(app_, this, Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 15, (app_->getWindowManager()->getCurResolution().h / 14) * 8),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 15, (app_->getWindowManager()->getCurResolution().h / 14) * 8),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 25) * 15, (app_->getWindowManager()->getCurResolution().h / 14) * 8),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "description_ j2", 30, 
		(app_->getWindowManager()->getCurResolution().w / 25) * 5, (app_->getWindowManager()->getCurResolution().h / 14) * 2);

	//Entitys

	Entity* nav = entManager_.addEntity();
	NavigationController* ctrl = nav->addComponent<NavigationController>(4, 2);
	ctrl->SetElementInPos(std::get<0>(flor_)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl->SetElementInPos(std::get<0>(mkwhoop_)->getComponent<UIElement>(ecs::UIElement), 1, 0);
	ctrl->SetElementInPos(std::get<0>(aisha_)->getComponent<UIElement>(ecs::UIElement), 2, 0);
	ctrl->SetElementInPos(std::get<0>(mockinbird_)->getComponent<UIElement>(ecs::UIElement), 3, 0);
	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 1, 1);
	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 2, 1);
	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 3, 1);
	

	//logic of that for changing the artwork of each player 
	Entity* logic = entManager_.addEntity();
	logic->addComponent<CharacterSelectionLogic>(text_j1->getComponent<TextComponent>(ecs::TextComponent),leftP_->getComponent<RenderImage>(ecs::RenderImage),aisha_desc, mkwhoop_desc, flor_desc, mock_desc, nav->getComponent<NavigationController>(ecs::NavigationController), 
		std::get<0>(aisha_)->getComponent<UIElement>(ecs::UIElement), std::get<0>(flor_)->getComponent<UIElement>(ecs::UIElement), std::get<0>(mkwhoop_)->getComponent<UIElement>(ecs::UIElement), std::get<0>(mockinbird_)->getComponent<UIElement>(ecs::UIElement),
		app_->getAssetsManager()->getTexture(AssetsManager::AishaArtwork),app_->getAssetsManager()->getTexture(AssetsManager::FlorArtwork), app_->getAssetsManager()->getTexture(AssetsManager::GanonArtwork), app_->getAssetsManager()->getTexture(AssetsManager::MockArtwork));
}
