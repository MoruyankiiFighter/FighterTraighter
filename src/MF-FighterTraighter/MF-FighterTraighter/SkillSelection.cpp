#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
#include "NavigationController.h"
void SkillSelection::init()
{
	// Fondo?

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::FSGente),
		Vector2D(0, 0),Vector2D(0,0),Vector2D(0,0), ancho, alto, 0);

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo),
		Vector2D(50, 50), Vector2D(ancho / 2, 0), Vector2D(ancho / 2, 0), (ancho / 2) - 100, (alto) - 100, 0);

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo),
		Vector2D((ancho/2) + 50, 50),Vector2D(ancho/2,0),Vector2D((ancho / 2),0), (ancho /2)-100, (alto)-100, 0);
	createInventoryMenu();
	//createFirstMenu();

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

		tuple<Entity*, Entity*> hf_win = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12)*2.5, (alto / 6) * 2), Vector2D((ancho / 12)*2.5, (alto / 6) * 2), Vector2D((ancho / 12)*2.5, (alto / 6) * 2),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Fija perdedor

		tuple<Entity*, Entity*> hf_lose=UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 8.5, (alto / 6) * 2), Vector2D((ancho / 12) * 8.5, (alto / 6) * 2), Vector2D((ancho / 12) * 8.5, (alto / 6) * 2),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales ganador

		tuple<Entity*, Entity*> hop_win =UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 1, (alto / 12) * 1.7), Vector2D((ancho / 12) * 1, (alto / 12) * 1.7), Vector2D((ancho / 12) * 1, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		tuple<Entity*, Entity*> hop_win2 =UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Toxic), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 4, (alto / 12) * 1.7), Vector2D((ancho / 12) * 4, (alto / 12) * 1.7), Vector2D((ancho / 12) * 4, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales perdedor

		tuple<Entity*, Entity*> hop_lose =UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Buff), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 8.5, (alto / 12)*1.7), Vector2D((ancho / 12) * 8.5, (alto / 12)*1.7), Vector2D((ancho / 12) * 8.5, (alto / 12)*1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	//winner
	/*Entity* nav_win = entManager_.addEntity();
	NavigationController* ctrl = nav_win->addComponent<NavigationController>(2, 3);
	ctrl->SetElementInPos(std::get<0>(hop_win)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl->SetElementInPos(std::get<0>(hop_win2)->getComponent<UIElement>(ecs::UIElement), 1, 0);
	ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 1, 1);
	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 0, 2);
	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 1, 2);*/
	
	//loser
	Entity* nav_loser = entManager_.addEntity();
	NavigationController* ctrl_ = nav_loser->addComponent<NavigationController>(1, 3);
	ctrl_->SetElementInPos(std::get<0>(hop_lose)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl_->SetElementInPos(std::get<0>(hf_lose)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	ctrl_->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 0, 2);

	
	}
	else { //gana player 2

		   // Fija ganador
		tuple<Entity*, Entity*> hf_win =UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 8.5, (alto / 6) * 2), Vector2D((ancho / 12) * 8.5, (alto / 6) * 2), Vector2D((ancho / 12) * 8.5, (alto / 6) * 2),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Fija perdedor
		tuple<Entity*, Entity*> hf_lose= UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Toxic), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 2.5, (alto / 6) * 2), Vector2D((ancho / 12) * 2.5, (alto / 6) * 2), Vector2D((ancho / 12) * 2.5, (alto / 6) * 2),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales ganador

		tuple<Entity*, Entity*> hop_win= UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 7, (alto / 12) * 1.7), Vector2D((ancho / 12) * 7, (alto / 12) * 1.7), Vector2D((ancho / 12) * 7, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		tuple<Entity*, Entity*> hop_win2= UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 10, (alto / 12) * 1.7), Vector2D((ancho / 12) * 10, (alto / 12) * 1.7), Vector2D((ancho / 12) * 10, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales perdedor

		tuple<Entity*, Entity*> hop_lose= UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Buff), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 2.5, (alto / 12) * 1.7), Vector2D((ancho / 12) * 2.5, (alto / 12) * 1.7), Vector2D((ancho / 12) * 2.5, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		//winner
		/*Entity* nav_win = entManager_.addEntity();
		NavigationController* ctrl = nav_win->addComponent<NavigationController>(2, 3);
		ctrl->SetElementInPos(std::get<0>(hop_win)->getComponent<UIElement>(ecs::UIElement), 0, 0);
		ctrl->SetElementInPos(std::get<0>(hop_win2)->getComponent<UIElement>(ecs::UIElement), 1, 0);
		ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 0, 1);
		ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 1, 1);
		ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 0, 2);
		ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 1, 2);*/

		//loser
		Entity* nav_loser = entManager_.addEntity();
		NavigationController* ctrl_ = nav_loser->addComponent<NavigationController>(1, 3);
		ctrl_->SetElementInPos(std::get<0>(hop_lose)->getComponent<UIElement>(ecs::UIElement), 0, 0);
		ctrl_->SetElementInPos(std::get<0>(hf_lose)->getComponent<UIElement>(ecs::UIElement), 0, 1);
		ctrl_->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 0, 2);

	}

}

void SkillSelection::createInventoryMenu()
{
	Entity* text_ = entManager_.addEntity();
	text_->addComponent<UITransform>(Vector2D(0, 0), Vector2D((ancho * 2) / 4, 0), Vector2D((ancho * 2) / 4, 0), Vector2D(ancho - (2 * letra), (alto / 20) + (2 * letra)));
	text_->addComponent<TextComponent>("Set your skills", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), letra, TextComponent::TextAlignment::Center);
	// boton de cambio de estado
	//buttons
		//UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			//Vector2D(-50, 5 * app_->getWindowManager()->getCurResolution().h / 6), Vector2D(app_->getWindowManager()->getCurResolution().w / 4, 0), Vector2D(150, 32), 300, 75, 0, nullptr, nullptr, "Continue", 50, TextComponent::TextAlignment::Center);
		tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 25)*4, (alto / 14) * 11.5), Vector2D((ancho / 25) * 4, (alto / 14) * 11.5), Vector2D((ancho / 25) * 4, (alto / 14) * 11.5), (ancho / 25) * 4, (alto / 25) * 1.5, 0, nullptr, nullptr, "Continue", letra/2, TextComponent::TextAlignment::Center);
		std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Center;
		tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 25) * 17, (alto / 14) * 11.5), Vector2D((ancho / 25) * 17, (alto / 14) * 11.5), Vector2D((ancho / 25) * 17, (alto / 14) * 11.5), (ancho / 25) * 4, (alto / 25) * 1.5, 0, nullptr, nullptr, "Continue_", letra / 2, TextComponent::TextAlignment::Center);
		std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Center;
	//habilidades j1

	//ranuras
	
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((ancho / 12) * 1, (alto / 12) * 1.7), Vector2D((ancho / 12) * 1, (alto / 12) * 1.7), Vector2D((ancho / 12) * 1, (alto / 12) * 1.7),
		(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((ancho / 12) * 4, (alto / 12) * 1.7), Vector2D((ancho / 12) * 4, (alto / 12) * 1.7), Vector2D((ancho / 12) * 4, (alto / 12) * 1.7),
		(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	
	//inventario j1
		//pos anchor pivot
	//vector<tuple<Entity*, Entity*>> habj1; //SE SALE DEL VECTOR
	//Entity* nav_j1 = entManager_.addEntity();
	//NavigationController* ctrl = nav_j1->addComponent<NavigationController>(4, 3);
	for (int i = 0; i < 10; i++)//cambiar el hasta 10 por largo vector hab j1
	{//ACCESO A J1->ACCESO A HAB->RETURN ASSET()
		if (i < 5) {
			/*habj1[i] =*/ UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Toxic), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
				Vector2D(((ancho / 15) + i* (ancho / 15))+40, (alto / 15) * 4.7), Vector2D(((ancho / 15) + i * (ancho / 15)) + 40, (alto / 15) * 4.7), Vector2D(((ancho / 15) + i * (ancho / 15)) + 40, (alto / 15) * 4.7),
				(ancho / 15), (ancho / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
			//ctrl->SetElementInPos(std::get<0>(habj1[i])->getComponent<UIElement>(ecs::UIElement), i, 0);
		}
		else {
			/*habj1[i]=*/ UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
				Vector2D(((ancho / 15) + (i-5) * (ancho / 15)) + 40, (alto / 15) * 6.7), Vector2D(((ancho / 15) + (i - 5) * (ancho / 15)) + 40, (alto / 15) * 6.7), Vector2D(((ancho / 15) + (i - 5) * (ancho / 15)) + 40, (alto / 15) * 6.7),
				(ancho / 15), (ancho / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
			//ctrl->SetElementInPos(std::get<0>(habj1[i])->getComponent<UIElement>(ecs::UIElement), i-5, 1);
		}
	}
	// Navigation controller
	/*for (int i = 0; i < 5; i++) {
		ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), i, 2);
	}	*/
		
		

	//description
		//UIFactory::createText(app_, this, Vector2D((ancho / 25) * 3, (alto / 14) * 5), Vector2D((ancho / 25) * 3, (alto / 14) * 5), Vector2D((ancho / 25) * 3, (alto / 14) * 5),
			//app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), "descripcion", letra/2, (ancho / 25) * 5, (alto / 14) * 2);
		Entity* habDefinitionText_ = entManager_.addEntity();
		habDefinitionText_->addComponent<UITransform>(Vector2D((ancho / 25) * 1.5, (alto / 14) * 8), Vector2D((ancho / 25) * 1.5, (alto / 14) * 8), Vector2D((ancho / 25) * 1.5, (alto / 14) * 8), Vector2D((ancho/25)*8,(alto / 14) *2));
		habDefinitionText_->addComponent<TextComponent>("Esto es una descripcion de la habilidad selecci", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), letra/3, TextComponent::TextAlignment::Left);
		
		vector<tuple<Entity*, Entity*>> habj2;

		//inventario j2
			//pos anchor pivot
		//for (int i = 0; i < 10; i++)//cambiar el hasta 10 por largo vector hab j1
		//{//ACCESO A J1->ACCESO A HAB->RETURN ASSET()
		//	if (i < 5) {
		//		habj2[i] = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Buff), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		//			Vector2D(((ancho / 15) + i * (ancho / 15)) + 1000, (alto / 15) * 4.7), Vector2D(((ancho / 15) + i * (ancho / 15)) + 1000, (alto / 15) * 4.7), Vector2D(((ancho / 15) + i * (ancho / 15)) + 1000, (alto / 15) * 4.7),
		//			(ancho / 15), (ancho / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		//	}
		//	else {
		//		habj2[i] = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		//			Vector2D(((ancho / 15) + (i - 5) * (ancho / 15)) + 1000, (alto / 15) * 6.7), Vector2D(((ancho / 15) + (i - 5) * (ancho / 15)) + 1000, (alto / 15) * 6.7), Vector2D(((ancho / 15) + (i - 5) * (ancho / 15)) + 1000, (alto / 15) * 6.7),
		//			(ancho / 15), (ancho / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		//	}
		//}
		//// Navigation controller
		//Entity* nav_j2 = entManager_.addEntity();
		//NavigationController* ctrl_ = nav_j2->addComponent<NavigationController>(0, 0);
		//ctrl_->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	//ranuras
		///Player2
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 7, (alto / 12) * 1.7), Vector2D((ancho / 12) * 7, (alto / 12) * 1.7), Vector2D((ancho / 12) * 7, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((ancho / 12) * 10, (alto / 12) * 1.7), Vector2D((ancho / 12) * 10, (alto / 12) * 1.7), Vector2D((ancho / 12) * 10, (alto / 12) * 1.7),
			(ancho / 12), (ancho / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		//inventario
		
		//description
		Entity* habDefinitionText2_ = entManager_.addEntity();
		habDefinitionText2_->addComponent<UITransform>(Vector2D((ancho / 25) * 14, (alto / 14) * 8), Vector2D((ancho / 25) * 14, (alto / 14) * 8), Vector2D((ancho / 25) * 14, (alto / 14) * 8), Vector2D((ancho / 25) * 8, (alto / 14) * 2));
		habDefinitionText2_->addComponent<TextComponent>("Esto es una descripcion de la habilidad selec2", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), letra / 3, TextComponent::TextAlignment::Left);

}

