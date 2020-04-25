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

	Entity* background_= UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::FSGente),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), ancho, alto, 0);
	//Entity* background_ = entManager_.addEntity();
	//background_->addComponent<Transform>(Vector2D(), Vector2D(), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h,0);
	//background_->addComponent<RenderImage>(); //añadir textura

	//panel


	Entity* centralP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo),
		Vector2D(50, 50), Vector2D(ancho / 2, 0), Vector2D(ancho / 2, 0), (ancho / 2) - 100, (alto)-100, 0);

	Entity* leftP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo),
		Vector2D((ancho / 2) + 50, 50), Vector2D(ancho / 2, 0), Vector2D((ancho / 2), 0), (ancho / 2) - 100, (alto)-100, 0);

	Entity* rightP_ = UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo),
		Vector2D((ancho / 2) + 50, 50), Vector2D(ancho / 2, 0), Vector2D((ancho / 2), 0), (ancho / 2) - 100, (alto)-100, 0);

	// buttons
	tuple <Entity*, Entity*> exitBJ1_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0, 
		nullptr,  nullptr, "Done J1", letra, TextComponent::TextAlignment::Center);
	tuple <Entity*, Entity*> exitBJ2_ = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0,
		nullptr, nullptr, "Done J1", letra, TextComponent::TextAlignment::Center);
	//icons of the character

	//artwork of the character


	//Entitys


	//Entity* navEnt = entManager_.addEntity();
	//NavigationController* nav = navEnt->addComponent<NavigationController>(5, 2);

	//logic of that for changing the artwork of each player 
}
