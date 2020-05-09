#include "SkillSelection.h"
#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
#include "NavigationController.h"

void SkillSelection::init()
{
	//crear fondo 

	Entity* b = entManager_.addEntity();
	b->addComponent<UITransform>(Vector2D(), Vector2D(), Vector2D(), Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h));
	b->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight));

	//j1
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h, 0);


	//crear habilidades

	//nav1

	//boton


	//j2
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D(50, 50), Vector2D(ancho / 2, 0), Vector2D(ancho / 2, 0), (ancho / 2) - 100, (alto)-100, 0);


}
