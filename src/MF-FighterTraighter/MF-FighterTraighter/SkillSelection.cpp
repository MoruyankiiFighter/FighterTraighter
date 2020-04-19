#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"

void SkillSelection::init()
{

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo), Vector2D(100, 100), (app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h) - 100, 0);

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo), Vector2D((app_->getWindowManager()->getCurResolution().w) + 100, 100), (app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h) - 100, 0);



}

void SkillSelection::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->popState();
	}
	else
		GameState::handleInput();
}