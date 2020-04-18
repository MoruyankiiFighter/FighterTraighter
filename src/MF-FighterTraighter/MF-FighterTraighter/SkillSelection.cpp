#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"

void SkillSelection::init()
{

	///// Esto es para los submenus-----new entity para que no se añada a la escena
	Entity* pollo = new Entity();
	pollo->addComponent<Transform>(Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0);
	pollo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Pollo));
	Entity* mina = new Entity();
	mina->addComponent<Transform>(Vector2D(60, 0), Vector2D(0, 0), 50, 50, 0);
	mina->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Mina));
	Entity* hielo = new Entity();
	hielo->addComponent<Transform>(Vector2D(120, 0), Vector2D(0, 0), 50, 50, 0);
	hielo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Hielo));

	UIFactory::createSubMenu(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo), app_->getAssetsManager()->getTexture(AssetsManager::Button),
		pollo, mina, hielo, Vector2D(100, 50), (app_->getWindowManager()->getCurResolution().w/2)-100 , (app_->getWindowManager()->getCurResolution().h) - 100 );
}

void SkillSelection::render()
{
	GameState::render();
}

void SkillSelection::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->popState();
	}
	else
		GameState::handleInput();
}