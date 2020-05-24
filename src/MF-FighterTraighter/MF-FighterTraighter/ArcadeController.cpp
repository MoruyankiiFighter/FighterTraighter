#include "ArcadeController.h"
#include "Entity.h"
#include "UITransform.h"
#include "TextComponent.h"
#include "PlayerController.h"
#include "PlayerAttacks.h"
#include "AIController.h"
#include "AIAttacks.h"
#include "AIGameState.h"
//void ArcadeController::init() {
//	SDL_Rect wSize = app_->getWindowManager()->getCurResolution();
//	//instanciar el timer en pantalla
//	msgEnt = state_->getEntityManager().addEntity();
//	msgEnt->addComponent<UITransform>(Vector2D(), Vector2D(wSize.w / 2, wSize.h / 2), Vector2D(), Vector2D());
//	msgEnt->addComponent<TextComponent>("0000", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 150, TextComponent::Center);
//	msgEnt->addComponent<UITimer>(UITimer::Seconds)->setCountdown((ini_timer / app_->getFrameRate()) * 1000);
//	disablePlayers(true);
//}
//void ArcadeController::update()
//{
//	if (showInitialMessage) {	//initial message timer
//		if (ini_timer > 60) {	//the one last frame says go
//			--ini_timer;
//		}
//		else if (ini_timer > 0) {
//			// removes the timer ent and replaces it with a go on the last second
//			if (ini_timer < 60) {
//				--ini_timer;
//			}
//			else {
//				app_->getStateMachine()->getCurrentState()->getEntityManager().removeEntity(msgEnt);
//				displayMessage("GO");
//				--ini_timer;
//			}
//		}
//		else {
//			ini_timer = 0;
//			app_->getStateMachine()->getCurrentState()->getEntityManager().removeEntity(msgEnt);
//			showInitialMessage = false;
//			disablePlayers(false);
//		}
//	}
//	if (playerLost_ != -2) {
//		if (end_timer > 0) {
//			--end_timer;
//		}
//		else {
//			end_timer = 0;
//			end();
//		}
//	}
//}
//
//void ArcadeController::PlayerLost(int playerNumber)
//{
//
//	//ir al menu final de AI en el que se muestra la puntuacion obtenida (numero rondas pasadas)
//	if (playerLost_ != -2) return;
//	string txt = "";
//	if (playerNumber == -1) { // tie
//		txt = "Both players lost!";
//	}
//	else {
//		txt = "Player " + to_string(playerNumber == 0 ? 2 : 1) + " wins!";
//	}
//	displayMessage(txt);
//	disablePlayers(true);
//
//	playerLost_ = playerNumber;
//	end_timer = roundEndTime_;
//}


void ArcadeController::end()
{
	if (playerLost_ != 0) {
		app_->getStateMachine()->popState();
		app_->getStateMachine()->pushState(new AIGameState(app_,round_+1));
	}
	else
		app_->getGameManager()->AIWin();

}

void ArcadeController::disablePlayers(bool mode) {
	state_->getEntityManager().getHandler(ecs::Player1)->getComponent<CharacterController>(ecs::CharacterController)->setDisabled(mode);
	state_->getEntityManager().getHandler(ecs::Player1)->getComponent<CharacterAttacks>(ecs::CharacterAttacks)->setDisabled(mode);
	state_->getEntityManager().getHandler(ecs::Player2)->getComponent<AIController>(ecs::CharacterController)->setDisabled(mode);
	state_->getEntityManager().getHandler(ecs::Player2)->getComponent<AIAttacks>(ecs::CharacterAttacks)->setDisabled(mode);
}

