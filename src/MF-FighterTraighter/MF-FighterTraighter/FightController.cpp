#include "FightController.h"
#include "Entity.h"
#include "UITransform.h"
#include "TextComponent.h"
#include "PlayerController.h"
#include "PlayerAttacks.h"

void FightController::update()
{
	if (playerLost_ != -1) {
		if (timer > 0) {
			--timer;
		}
		else {
			timer = 0;
			app_->getGameManager()->playerLost(playerLost_);
		}
	}
}

void FightController::PlayerLost(int playerNumber)
{
	if (playerLost_ != -1) return;

	SDL_Rect wSize = app_->getWindowManager()->getCurResolution();
	Entity* e = state_->getEntityManager().addEntity();
	e->addComponent<UITransform>(Vector2D(), Vector2D(wSize.w / 2, wSize.h / 2), Vector2D(), Vector2D());
	e->addComponent<TextComponent>("Player " + to_string(playerNumber == 0 ? 2 : 1) + " wins!", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 150, TextComponent::Center);
	state_->getEntityManager().getHandler(ecs::Player1)->getComponent<PlayerController>(ecs::PlayerController)->setDisabled(true);
	state_->getEntityManager().getHandler(ecs::Player1)->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->setDisabled(true);
	state_->getEntityManager().getHandler(ecs::Player2)->getComponent<PlayerController>(ecs::PlayerController)->setDisabled(true);
	state_->getEntityManager().getHandler(ecs::Player2)->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->setDisabled(true);

	playerLost_ = playerNumber;
	timer = roundEndTime_;
}
