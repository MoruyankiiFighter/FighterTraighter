#include "PlayerAttacks.h"
#include "PlayerController.h"

PlayerAttacks::PlayerAttacks(HID* hid, AnimationChain* highFist, AnimationChain* airHighFist, AnimationChain* lowFist, AnimationChain* airLowFist,
	AnimationChain* highKick, AnimationChain* airHighKick, AnimationChain* lowKick, AnimationChain* airLowKick,  AnimationChain* testGB) : Component(ecs::PlayerAttacks), inputSt_(hid)
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

void PlayerAttacks::init()
{
}

void PlayerAttacks::handleInput() {
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	Transform* tr = entity_->getComponent<Transform>(ecs::Transform);
	PlayerController* ctrl = entity_->getComponent<PlayerController>(ecs::PlayerController);
	if (currState->isAbleToAttack()) {
		if (currState->isGrounded()) {
			if (inputSt_->ButtonPressed(HID::RightPad_Down)) {

				activeAttack_ = attacksList[0];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack(0);
			}
			else if (inputSt_->ButtonPressed(HID::RightPad_Right)) {
				activeAttack_ = attacksList[1];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack(1);
			}
			else if (inputSt_->ButtonPressed(HID::RightPad_Left)) {
				activeAttack_ = attacksList[2];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack(2);
			}
			else if (inputSt_->ButtonPressed(HID::RightPad_Up)) {
				activeAttack_ = attacksList[3];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack(3);
			}
			else if (inputSt_->AxisChanged(HID::RTrigger)) {
				activeAttack_ = attacksList[8];
				if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
				else if (currState->isCrouch()) ctrl->uncrouch();
				currState->goAttack(4);
			}else if (inputSt_->ButtonPressed(HID::LeftBumper)) {
				if (abilityList[0] != nullptr && cooldowns[0] == 0) {
					activeAttack_ = abilityList[0];
					tr->setSpeed(0, tr->getSpeed().getY());
					if (currState->isCrouch()) ctrl->uncrouch();
					currState->goCasting();
				}
			}
			else if (inputSt_->ButtonPressed(HID::RightBumper)) {
				if (abilityList[1] != nullptr && cooldowns[1] == 0) {
					activeAttack_ = abilityList[1];
					tr->setSpeed(0, tr->getSpeed().getY());
					if (currState->isCrouch()) ctrl->uncrouch();
					currState->goCasting();
				}
			}
		}
		else {
			if (inputSt_->ButtonPressed(HID::RightPad_Down)) {
				activeAttack_ = attacksList[4];
				tr->setSpeed(tr->getSpeed().getX() * 0.65, tr->getSpeed().getY());
				currState->goAttack(0);
			}
			else if (inputSt_->ButtonPressed(HID::RightPad_Right)) {
				activeAttack_ = attacksList[5];
				tr->setSpeed(tr->getSpeed().getX() * 0.65, tr->getSpeed().getY());
				currState->goAttack(1);
			}
			else if (inputSt_->ButtonPressed(HID::RightPad_Left)) {
				activeAttack_ = attacksList[6];
				tr->setSpeed(tr->getSpeed().getX() * 0.65, tr->getSpeed().getY());
				currState->goAttack(2);
			}
			else if (inputSt_->ButtonPressed(HID::RightPad_Up)) {
				activeAttack_ = attacksList[7];
				tr->setSpeed(tr->getSpeed().getX() * 0.65, tr->getSpeed().getY());
				currState->goAttack(3);
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
	app_->getStateMachine()->getCurrentState()->resetGroup((entity_->getComponent<PhysicsTransform>(ecs::Transform)->getMainFixture()->GetFilterData().categoryBits)>>2);
}

int PlayerAttacks::getAbilityIndex()	//IN THEORY IT NEVER SHOULD RETURN -1
{										//BUT
	int index = -1;
	for (int i = 0; i < abilityList.size(); ++i) {
		if (activeAttack_ == abilityList[i]) index = i;
	}
	return index;
}
