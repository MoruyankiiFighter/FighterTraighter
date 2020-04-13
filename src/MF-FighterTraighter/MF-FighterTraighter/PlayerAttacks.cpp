#include "PlayerAttacks.h"
#include "PlayerController.h"

PlayerAttacks::PlayerAttacks(AnimationChain* highFist, AnimationChain* airHighFist, SDL_Scancode key1, AnimationChain* lowFist, AnimationChain* airLowFist,
	SDL_Scancode key2, AnimationChain* highKick, AnimationChain* airHighKick, SDL_Scancode key3, AnimationChain* lowKick, AnimationChain* airLowKick,
	SDL_Scancode key4, AnimationChain* testGB, SDL_Scancode key5, SDL_Scancode key6, SDL_Scancode key7) : Component(ecs::PlayerAttacks)
{
	attacksList.push_back(highFist);
	attacksList.push_back(lowFist);
	attacksList.push_back(highKick);
	attacksList.push_back(lowKick);
	attacksList.push_back(airHighFist);
	attacksList.push_back(airLowFist);
	attacksList.push_back(airHighKick);
	attacksList.push_back(airLowKick);
	highFistKey = key1;
	lowFistKey = key2;
	highKickKey = key3;
	lowKickKey = key4;
	guardBreaker_ = key5;
	abilityKey1 = key6;
	abilityKey2 = key7;

}

PlayerAttacks::~PlayerAttacks() {
	cout << "destruyendo ataques "<<endl;
	//hay que descomentar cuando las animaciones sean diferentes
	for (int i = 0; i < attacksList.size(); i++) {
		delete attacksList[i];
		attacksList[i] = nullptr;
	}
	attacksList.clear();

	for (int i = 0; i < abilityList.size(); i++) {
		delete abilityList[i];
		abilityList[i] = nullptr;
	}
	abilityList.clear();
}

void PlayerAttacks::handleInput() {
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	Transform* tr = entity_->getComponent<Transform>(ecs::Transform);
	PlayerController* ctrl = entity_->getComponent<PlayerController>(ecs::PlayerController);
	if (currState->isAbleToAttack()) {
		if (currState->isGrounded()) {
			if (app_->getInputManager()->isKeyDown(highFistKey_) || app_->getInputManager()->isControllerButtonPressed(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_BUTTON_A)) {
				activeAttack_ = attacksList[0];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
			else if (app_->getInputManager()->isKeyDown(lowFistKey_)) {
				activeAttack_ = attacksList[1];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
			else if (app_->getInputManager()->isKeyDown(highKickKey_)) {
				activeAttack_ = attacksList[2];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
			else if (app_->getInputManager()->isKeyDown(lowKickKey_)) {
				activeAttack_ = attacksList[3];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
			else if (app_->getInputManager()->isKeyDown(guardBreaker_)) {
				activeAttack_ = attacksList[8];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
		}
		else {
			if (app_->getInputManager()->isKeyDown(highFistKey_) || app_->getInputManager()->isControllerButtonPressed(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_BUTTON_A)) {
				activeAttack_ = attacksList[4];
				tr->setSpeed(0, tr->getSpeed().getY());
				currState->goAttack();
			}
			else if (app_->getInputManager()->isKeyDown(lowFistKey_)) {
				activeAttack_ = attacksList[5];
				tr->setSpeed(0, tr->getSpeed().getY());
				currState->goAttack();
			}
			else if (app_->getInputManager()->isKeyDown(highKickKey_)) {
				activeAttack_ = attacksList[6];
				tr->setSpeed(0, tr->getSpeed().getY());
				currState->goAttack();
			}
			else if (app_->getInputManager()->isKeyDown(lowKickKey_)) {
				activeAttack_ = attacksList[7];
				tr->setSpeed(0, tr->getSpeed().getY());
				currState->goAttack();
			}
		}
		if (app_->getInputManager()->isKeyDown(abilityKey1)) {
			if (abilityList[0] != nullptr) {
				activeAttack_ = abilityList[0];
				tr->setSpeed(0, tr->getSpeed().getY());
				currState->goAttack();
			}
		}
		else if (app_->getInputManager()->isKeyDown(abilityKey2)) {
			if (abilityList[1] != nullptr) {
				activeAttack_ = abilityList[1];
				tr->setSpeed(0, tr->getSpeed().getY());
				currState->goAttack();
			}
		}
	}
}

void PlayerAttacks::setAbility(AnimationChain* newAbility, int index)
{
	if (abilityList[index] != nullptr)delete abilityList[index]; //�Necesario? no s�
	abilityList[index] = newAbility;
}

void PlayerAttacks::interruptAttack()
{
	if(activeAttack_ != nullptr) activeAttack_->reset();
	activeAttack_ = nullptr;
	app_->getHitboxMng()->resetGroup((entity_->getComponent<PhysicsTransform>(ecs::Transform)->getMainFixture()->GetFilterData().categoryBits)>>2);
	
}
