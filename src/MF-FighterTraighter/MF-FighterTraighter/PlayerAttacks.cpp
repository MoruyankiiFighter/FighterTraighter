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
	attacksList.push_back(testGB);
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
	PhysicsTransform* tr = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	PlayerController* ctrl = entity_->getComponent<PlayerController>(ecs::PlayerController);
	if (currState->isAbleToAttack()) {
		if (currState->isGrounded()) {
			if (app_->getInputManager()->KeyPressed(highFistKey) || app_->getInputManager()->isControllerButtonPressed(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_BUTTON_A)) {
				activeAttack_ = attacksList[0];
				if (currState->isMoving()) ctrl->stop();//tr->setSpeed(0, tr->getSpeed().getY()); 
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
			else if (app_->getInputManager()->KeyPressed(lowFistKey)) {
				activeAttack_ = attacksList[1];
				if (currState->isMoving()) ctrl->stop();
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
			else if (app_->getInputManager()->KeyPressed(highKickKey)) {
				activeAttack_ = attacksList[2];
				if (currState->isMoving())ctrl->stop();
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
			else if (app_->getInputManager()->KeyPressed(lowKickKey)) {
				activeAttack_ = attacksList[3];
				if (currState->isMoving()) ctrl->stop();
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
			else if (app_->getInputManager()->KeyPressed(guardBreaker_)) {
				activeAttack_ = attacksList[8];
				if (currState->isMoving()) ctrl->stop();
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack();
			}
		}
		else {
			if (app_->getInputManager()->KeyPressed(highFistKey) || app_->getInputManager()->isControllerButtonPressed(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_BUTTON_A)) {
				activeAttack_ = attacksList[4];
				ctrl->stop();
				currState->goAttack();
			}
			else if (app_->getInputManager()->KeyPressed(lowFistKey)) {
				activeAttack_ = attacksList[5];
				ctrl->stop();
				currState->goAttack();
			}
			else if (app_->getInputManager()->KeyPressed(highKickKey)) {
				activeAttack_ = attacksList[6];
				ctrl->stop();
				currState->goAttack();
			}
			else if (app_->getInputManager()->KeyPressed(lowKickKey)) {
				activeAttack_ = attacksList[7];
				ctrl->stop();
				currState->goAttack();
			}
		}
		if (app_->getInputManager()->KeyPressed(abilityKey1)) {
			if (abilityList[0] != nullptr) {
				activeAttack_ = abilityList[0];
				ctrl->stop();
				currState->goAttack();
			}
		}
		else if (app_->getInputManager()->KeyPressed(abilityKey2)) {
			if (abilityList[1] != nullptr) {
				activeAttack_ = abilityList[1];
				ctrl->stop();
				currState->goAttack();
			}
		}
	}
}

void PlayerAttacks::setAbility(AnimationChain* newAbility, int index)
{
	if (abilityList[index] != nullptr)delete abilityList[index]; //Necesario? no se
	abilityList[index] = newAbility;
}

void PlayerAttacks::interruptAttack()
{
	if(activeAttack_ != nullptr) activeAttack_->reset();
	activeAttack_ = nullptr;
	app_->getHitboxMng()->resetGroup((entity_->getComponent<PhysicsTransform>(ecs::Transform)->getMainFixture()->GetFilterData().categoryBits)>>2);
	
}
