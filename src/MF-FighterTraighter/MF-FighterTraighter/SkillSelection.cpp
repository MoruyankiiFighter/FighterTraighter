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

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h, 0);

	//crear habilidades

	//nav1

	//boton

}
