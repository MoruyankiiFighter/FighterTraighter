#include "MkWH00PData.h"

MkWH00PData::MkWH00PData(std::vector<SDL_Scancode> keys, double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, Vector2D speed, double ini_health, double attack, double defense, int playerNumber) :
	PlayerData(keys, width, height, rotation, jump_impulse, ini_pos, speed, ini_health, attack, defense, playerNumber) {
}

void MkWH00PData::init() {
	std::vector<Move*> vecMov;

	vecMov.push_back(new Move(27, nullptr, NP1, entity_));
	vecMov.push_back(new Move(90, nullptr, nullptr, entity_));
	normal_punch_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(29, nullptr, HP1, entity_));
	vecMov.push_back(new Move(46, nullptr, nullptr, entity_));
	hard_punch_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(25, nullptr, NK1, entity_));
	vecMov.push_back(new Move(20, nullptr, NK2, entity_));
	vecMov.push_back(new Move(35, nullptr, nullptr, entity_));
	normal_kick_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(35, nullptr, HK1, entity_));
	vecMov.push_back(new Move(100, nullptr, nullptr, entity_));
	hard_kick_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(40, nullptr, ANP1, entity_));
	vecMov.push_back(new Move(25, nullptr, ANP2, entity_));
	vecMov.push_back(new Move(35, nullptr, nullptr, entity_));
	air_normal_punch_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(49, nullptr, AHP1, entity_));
	vecMov.push_back(new Move(45, nullptr, nullptr, entity_));
	air_hard_punch_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(34, nullptr, ANK1, entity_));
	vecMov.push_back(new Move(17, nullptr, ANK2, entity_));
	vecMov.push_back(new Move(39, nullptr, nullptr, entity_));
	air_normal_kick_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(32, nullptr, AHK1, entity_));
	vecMov.push_back(new Move(95, nullptr, nullptr, entity_));
	air_hard_kick_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(72, nullptr, GB, entity_));
	vecMov.push_back(new Move(50, nullptr, nullptr, entity_));
	guard_breaker_ = new AnimationChain(vecMov);
	vecMov.clear();
}
//Esto es para geenrar hitboxes, habr? uno para cada hitbox generada
void MkWH00PData::NP1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Uppercut" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	//NO ME GUSTA AS� PERO NO S� C�MO HACERLO SI NO
	int width = 150;
	int hitboxX = 100;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX,-250 }, width, 200, 20, 9, 42, { (double)orientation_ * 10, -25 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::HP1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Hostia" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();


	//NO ME GUSTA AS� PERO NO S� C�MO HACERLO SI NO
	int width = 175;
	int hitboxX = 100;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX,-85 }, width, 150, 17, 15, 55, { (double)orientation_ * 4, 125 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::NK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Rodilla 1" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();


	//NO ME GUSTA AS� PERO NO S� C�MO HACERLO SI NO
	int width = 155;
	int hitboxX = 105;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX,125 }, width, 125, 13, 6, 16, { (double)orientation_ * 2.5, -2.5 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::NK2(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Rodilla 2" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();


	//NO ME GUSTA AS� PERO NO S� C�MO HACERLO SI NO
	int width = 140;
	int hitboxX = 135;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX, 100 }, width, 125, 17, 6, 35, { (double)orientation_ * 50, -15 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::HK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Falcon stomp" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width1 = 120;
	int hitboxX1 = 130;
	if (orientation_ == -1) hitboxX1 += width1;
	int width2 = 600;
	int hitboxX2 = 0;
	if (orientation_ == -1) hitboxX2 += width2;



	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX1, 105 }, width1, 150, 17, 17, 50, { (double)orientation_ * 5, 500 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
	std::cout << "Brrrrrjrnkrrbr" << endl;
	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX2, 220 }, width2, 50, 20, 5, 40, { (double)orientation_ * 500, -150 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::ANP1(Entity* ent)
{
	std::cout << "Speeeee-" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width = 350;
	int hitboxX = -165;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX, -65 }, width, 120, 35, 5, 16, { (double)orientation_ * 1, -1 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::ANP2(Entity* ent)
{
	std::cout << "-eeeeeeen" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width = 350;
	int hitboxX = -165;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX, -45 }, width, 120, 35, 8, 30, { (double)orientation_ * 75, -5 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::AHP1(Entity* ent)
{
	std::cout << "Get spiked son" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width = 125;
	int hitboxX = 115;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX, -65 }, width, 300, 25, 22, 65, { (double)orientation_ * 25, 1000000 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::ANK1(Entity* ent)
{
	std::cout << "Steppy" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width = 155;
	int hitboxX = 105;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX, 135 }, width, 155, 17, 4, 15, { (double)orientation_ * 5, -5 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::ANK2(Entity* ent)
{
	std::cout << "STEPPY!!!" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width = 155;
	int hitboxX = 105;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX, 135 }, width, 155, 17, 10, 28, { (double)orientation_ * 25, 12.5 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::AHK1(Entity* ent)
{
	std::cout << "Dropkick" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width = 250;
	int hitboxX = 50;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX, -75 }, width, 200, 50, 18, 55, { (double)orientation_ * 4000, 0 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
}

void MkWH00PData::GB(Entity* ent)
{
	std::cout << "BreakerGuard" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width = 250;
	int hitboxX = 50;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX, -75 }, width, 200, 50, 0, 2000, { (double)orientation_ * 200, -50 }, pT->getBody(), ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask(), true);

}