#include "CharacterSelection.h"

#include "Entity.h"
#include "UIFactory.h"
#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"
#include "TextComponent.h"
#include "NavigationController.h"
#include "Font.h"

void CharacterSelection::init()
{
	// background

	Entity* background_= UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), ancho, alto, 0);
	
	//panel

	Entity* centralP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D(50, 50), Vector2D(ancho / 2, 0), Vector2D(ancho / 2, 0), (ancho / 2) - 100, (alto)-100, 0);

	Entity* leftP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D((ancho / 2) + 50, 50), Vector2D(ancho / 2, 0), Vector2D((ancho / 2), 0), (ancho / 2) - 100, (alto)-100, 0);

	Entity* rightP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D((ancho / 2) + 50, 50), Vector2D(ancho / 2, 0), Vector2D((ancho / 2), 0), (ancho / 2) - 100, (alto)-100, 0);

	// buttons
	tuple <Entity*, Entity*> exitBJ1_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0, 
		nullptr,  nullptr, "Done J1", letra, TextComponent::TextAlignment::Center);
	
	tuple <Entity*, Entity*> exitBJ2_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0,
		nullptr, nullptr, "Done J2", letra, TextComponent::TextAlignment::Center);
	
	//icons of the character
	tuple <Entity*, Entity*> flor_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0,
		nullptr, nullptr, " ", letra, TextComponent::TextAlignment::Center);
	tuple <Entity*, Entity*> mkwhoop_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0,
		nullptr, nullptr, " ", letra, TextComponent::TextAlignment::Center);
	tuple <Entity*, Entity*> aisha_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0,
		nullptr, nullptr, " ", letra, TextComponent::TextAlignment::Center);
	tuple <Entity*, Entity*> mockinbird_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0,
		nullptr, nullptr, " ", letra, TextComponent::TextAlignment::Center);


	//artwork of the character

	Entity* j1_ = entManager_.addEntity();
	Entity* j2 = entManager_.addEntity();
	Entity* text_j1 = UIFactory::createText(app_, this, Vector2D(), Vector2D(), Vector2D(), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "description_ j1", 10, 100,100);
	Entity* text_j2 = UIFactory::createText(app_, this, Vector2D(), Vector2D(), Vector2D(), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "description_ j2", 10, 100,100);

	//Entitys


	//Entity* navEnt = entManager_.addEntity();
	//NavigationController* nav = navEnt->addComponent<NavigationController>(5, 2);

	//logic of that for changing the artwork of each player 
}
