#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
void SkillSelection::init()
{
	// Fondo?

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::FSGente),
		Vector2D(0, 0),Vector2D(0,0),Vector2D(0,0), ancho, alto, 0);

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo),
		Vector2D(50, 50), Vector2D(ancho / 2, 0), Vector2D(ancho / 2, 0), (ancho / 2) - 100, (alto) - 100, 0);

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo),
		Vector2D((ancho/2) + 50, 50),Vector2D(ancho/2,0),Vector2D((ancho / 2),0), (ancho /2)-100, (alto)-100, 0);
	//createInventoryMenu();
	createFirstMenu();

	}

void SkillSelection::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->pushState(new Fight(app_));
	}
	else
		GameState::handleInput();
}

void SkillSelection::createFirstMenu()
{
	Entity* text_ = entManager_.addEntity();
	//Vector2D pos, Vector2D anchor, Vector2D pivot, Vector2D size
	text_->addComponent<UITransform>(Vector2D(0, 0), Vector2D((ancho * 2) / 4, 0), Vector2D((ancho * 2) / 4 , 0), Vector2D(ancho - (2 * letra), (alto / 20) + (2 * letra)));
	text_->addComponent<TextComponent>("Elige tu habilidad", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), letra, TextComponent::TextAlignment::Center); 

	//pos anchor pivot
	// boton de cambio de estado

	tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(ancho/12, (alto/2)*1.5), Vector2D(ancho / 12, (alto/2)*1.5), Vector2D(ancho / 12, (alto/2)*1.5), (ancho / 6)*2, (alto / 15) * 2.5, 0, nullptr, nullptr, "Continue", letra, TextComponent::TextAlignment::Center);
	std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Center;
	tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((ancho / 12)*7, (alto / 2) * 1.5), Vector2D((ancho / 12)*7, (alto / 2) * 1.5), Vector2D((ancho/12)*7, (alto / 2) * 1.5), (ancho / 6) * 2, (alto / 15) * 2.5, 0, nullptr, nullptr, "Continue_", letra, TextComponent::TextAlignment::Center);
	std::get<1>(boton2)->getComponent<UITransform>(ecs::Transform)->Center;
		
	if (win1) {
		// Fija ganador

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12)*2.5, (alto / 6) * 2), Vector2D((ancho / 12)*2.5, (alto / 6) * 2), Vector2D((ancho / 12)*2.5, (alto / 6) * 2),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Fija perdedor

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 8.5, (alto / 6) * 2), Vector2D((ancho / 12) * 8.5, (alto / 6) * 2), Vector2D((ancho / 12) * 8.5, (alto / 6) * 2),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales ganador

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 1, (alto / 12) * 1.7), Vector2D((ancho / 12) * 1, (alto / 12) * 1.7), Vector2D((ancho / 12) * 1, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 4, (alto / 12) * 1.7), Vector2D((ancho / 12) * 4, (alto / 12) * 1.7), Vector2D((ancho / 12) * 4, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales perdedor

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 8.5, (alto / 12)*1.7), Vector2D((ancho / 12) * 8.5, (alto / 12)*1.7), Vector2D((ancho / 12) * 8.5, (alto / 12)*1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	}
	else { //gana player 2
		// Fija ganador

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 8.5, (alto / 6) * 2), Vector2D((ancho / 12) * 8.5, (alto / 6) * 2), Vector2D((ancho / 12) * 8.5, (alto / 6) * 2),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Fija perdedor

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 2.5, (alto / 6) * 2), Vector2D((ancho / 12) * 2.5, (alto / 6) * 2), Vector2D((ancho / 12) * 2.5, (alto / 6) * 2),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales ganador

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 7, (alto / 12) * 1.7), Vector2D((ancho / 12) * 7, (alto / 12) * 1.7), Vector2D((ancho / 12) * 7, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 10, (alto / 12) * 1.7), Vector2D((ancho / 12) * 10, (alto / 12) * 1.7), Vector2D((ancho / 12) * 10, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales perdedor

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 2.5, (alto / 12) * 1.7), Vector2D((ancho / 12) * 2.5, (alto / 12) * 1.7), Vector2D((ancho / 12) * 2.5, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	}

}

void SkillSelection::createInventoryMenu()
{
	Entity* text_ = entManager_.addEntity();
	text_->addComponent<UITransform>(Vector2D(-20, 40), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(app_->getWindowManager()->getCurResolution().w / 5, 0), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 200));
	text_->addComponent<TextComponent>("Set your skills", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 75, TextComponent::TextAlignment::Center);

	// boton de cambio de estado

	//habilidades j1

	//ranuras
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(-150 , 100), Vector2D((app_->getWindowManager()->getCurResolution().w / 4), 0), Vector2D(0, 0),
		100, 100, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(150 , 100), Vector2D((app_->getWindowManager()->getCurResolution().w / 4), 0), Vector2D(0, 0),
		100, 100, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	//inventario
		/*
		.
		.
		.
		.
		.
		.
		*/


	//description
		UIFactory::createText(app_, this, Vector2D(-50, 2 * app_->getWindowManager()->getCurResolution().h / 3), Vector2D(3*app_->getWindowManager()->getCurResolution().w / 4, 0), Vector2D(300, 50), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "descripcion", 50, 600, 200);

	//button
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(-50, 5 * app_->getWindowManager()->getCurResolution().h / 6), Vector2D(app_->getWindowManager()->getCurResolution().w / 4, 0), Vector2D(150, 32), 300, 75, 0, nullptr, nullptr, "Continue", 50, TextComponent::TextAlignment::Center);



	//habilidades j2
		/* for con 2 filas de habilidades
		.
		.
		.
		.
		.
		.
		*/

	//ranuras
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(-150, 100), Vector2D((3*app_->getWindowManager()->getCurResolution().w / 4), 0), Vector2D(0, 0),
			100, 100, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(150, 100), Vector2D((3*app_->getWindowManager()->getCurResolution().w / 4), 0), Vector2D(0, 0),
			100, 100, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		//inventario
		
		//description
		UIFactory::createText(app_, this, Vector2D(-50,2*app_->getWindowManager()->getCurResolution().h/3), Vector2D(app_->getWindowManager()->getCurResolution().w/4,0), Vector2D(300,50), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "descripcion", 50, 600, 200);

		//button
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(-50, 5 * app_->getWindowManager()->getCurResolution().h / 6), Vector2D(3 * app_->getWindowManager()->getCurResolution().w / 4, 0), Vector2D(150, 32), 300, 75, 0, nullptr, nullptr, "Continue_", 50, TextComponent::TextAlignment::Center);

}

