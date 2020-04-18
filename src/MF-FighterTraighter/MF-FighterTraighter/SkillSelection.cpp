#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"

void SkillSelection::init()
{

	///// Esto es para los submenus-----new entity para que no se añada a la escena

	///HABILIDADES QUE TENGAMOS QUE AÑADIR AL SUBMENU, DE MOMENTO ASI

	Entity* pollo = new Entity();
	pollo->addComponent<Transform>(Vector2D(0, 0), Vector2D(0, 0), 50, 50, 0);
	pollo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Pollo));
	Entity* mina = new Entity();
	mina->addComponent<Transform>(Vector2D(60, 0), Vector2D(0, 0), 50, 50, 0);
	mina->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Mina));
	Entity* hielo = new Entity();
	hielo->addComponent<Transform>(Vector2D(120, 0), Vector2D(0, 0), 50, 50, 0);
	hielo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Hielo));

}

void SkillSelection::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->popState();
	}
	else
		GameState::handleInput();
}