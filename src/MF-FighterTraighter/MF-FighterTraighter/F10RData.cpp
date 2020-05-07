#include "F10RData.h"
#include "AbilityFactory.h"

F10RData::F10RData(double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, double speed, double ini_health, double attack, double defense, int playerNumber):
	PlayerData(width, height, rotation, jump_impulse, ini_pos, speed, ini_health, attack, defense, playerNumber) {
	animLength_ = { {4, true, 12}, {3, true, 15}, {2, true, 3}, {1, true, 15}, {2, false, 2}, {4, false, 10}, {6, false, 10}, {5, false, 12},
	{3, false, 7}, {4, false, 13}, {4, false, 10}, {4, false, 7}, {5, false, 15}, {2, true, 15}, {2, false, 10}, {2, true, 4}, {2, false, 10},
	{2, false, 3}, {2, true, 12}, {2, false, 7}, {3, false, 7}, {4, true, 15}, {3, true, 10} };
}

void F10RData::init()
{
	std::vector<Move*> vecMov;

	vecMov.push_back(new Move(15, nullptr, NP1, entity_));
	vecMov.push_back(new Move(25, nullptr, nullptr, entity_));
	normal_punch_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(29, nullptr, HP1, entity_));
	vecMov.push_back(new Move(36, nullptr, nullptr, entity_));
	hard_punch_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(25, nullptr, NK1, entity_));
	vecMov.push_back(new Move(35, nullptr, nullptr, entity_));
	normal_kick_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(35, nullptr, HK1, entity_));
	vecMov.push_back(new Move(45, nullptr, nullptr, entity_));
	hard_kick_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(32, nullptr, ANP1, entity_));
	vecMov.push_back(new Move(35, nullptr, nullptr, entity_));
	air_normal_punch_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(45, nullptr, AHP1, entity_));
	vecMov.push_back(new Move(45, nullptr, nullptr, entity_));
	air_hard_punch_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(27, nullptr, ANK1, entity_));
	vecMov.push_back(new Move(39, nullptr, nullptr, entity_));
	air_normal_kick_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(32, nullptr, AHK1, entity_));
	vecMov.push_back(new Move(55, nullptr, nullptr, entity_));
	air_hard_kick_ = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(30, nullptr, GB, entity_));
	vecMov.push_back(new Move(50, nullptr, nullptr, entity_));
	guard_breaker_ = new AnimationChain(vecMov);
	vecMov.clear();
}

void F10RData::NP1(Entity* ent)
{
#ifdef _DEBUG
	std::cout << "Nibble" << endl;
#endif // _DEBUG

	double hitbox_X = np1.position.getX();
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	PlayerData* pD = ent->getComponent<PlayerData>(ecs::PlayerData);
	int orientation_ = pT->getOrientation();
	if (orientation_ == -1)
		hitbox_X += np1.width;
	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox(
		{ (double)orientation_ * hitbox_X, np1.position.getY() }, np1.width, np1.height, np1.time, pD->getAttack() * np1.damage, np1.hitstun, 
		{ (double)orientation_ * np1.knockBack.getX(), np1.knockBack.getY() }, pT->getBody(), pD->getPlayerNumber(), ent, pT->getCategory(), pT->getMask());
}

PlayerData::CallbackData F10RData::np1 = PlayerData::CallbackData{
	{ 110, -10 },
	{ 50, 0 },
	125,
	95,
	10,
	7,
	18 };

void F10RData::HP1(Entity* ent)
{
#ifdef _DEBUG
	std::cout << "Do it for the vine" << endl;
#endif // _DEBUG

	GameState* currentState = ent->getApp()->getStateMachine()->getCurrentState();
	Texture* texture = ent->getApp()->getAssetsManager()->getTexture(AssetsManager::F10RHp);
	PhysicsTransform* phtr = ent->getComponent<PhysicsTransform>(ecs::Transform);

	uint16 mask;
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	PlayerData* pD = ent->getComponent<PlayerData>(ecs::PlayerData);
	if (pD->getPlayerNumber() == 0) {
		mask = currentState->PLAYER_2;
	}
	else {
		mask = currentState->PLAYER_1;
	}

	int projX = phtr->getPosition().getX() + (phtr->getWidth() * 3 / 4) + (hp1.width / 2) + hp1.position.getX();
	if (orientation_ == -1) projX = phtr->getPosition().getX() + (phtr->getWidth() * 1 / 4) - (hp1.width / 2) - hp1.position.getX();

	Vector2D pos = Vector2D(projX, phtr->getPosition().getY() + hp1.position.getY());
	AbilityFactory::createProyectile(ent, hp1.width, hp1.height, pos, { 0, 0 }, hp1.damage, hp1.hitstun, { (double)orientation_ * hp1.knockBack.getX(), hp1.knockBack.getY() }, 
		hp1.time, mask, ent->getState(), ent->getApp(), texture, false);
}

PlayerData::CallbackData F10RData::hp1 = PlayerData::CallbackData{
	{ 0, 320 },
	{ 12, 0 },
	325,
	70,
	20,
	12,
	28 };

void F10RData::NK1(Entity* ent)
{
#ifdef _DEBUG
	std::cout << "Kik in the Kök" << endl;
#endif // _DEBUG

	double hitbox_X = nk1.position.getX();
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	PlayerData* pD = ent->getComponent<PlayerData>(ecs::PlayerData);
	int orientation_ = pT->getOrientation();
	if (orientation_ == -1)
		hitbox_X += nk1.width;
	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox(
		{ (double)orientation_ * hitbox_X, nk1.position.getY() }, nk1.width, nk1.height, nk1.time, pD->getAttack() * nk1.damage, nk1.hitstun,
		{ (double)orientation_ * nk1.knockBack.getX(), nk1.knockBack.getY() }, pT->getBody(), pD->getPlayerNumber(), ent, pT->getCategory(), pT->getMask());
}

PlayerData::CallbackData F10RData::nk1 = PlayerData::CallbackData{
	{ 105, 95 },
	{ 500, -200 },
	100,
	100,
	15,
	15,
	31 };

void F10RData::HK1(Entity* ent)
{
}

PlayerData::CallbackData F10RData::hk1 = PlayerData::CallbackData{
	{ 80, -150 },
	{ 300, -360 },
	150,
	200,
	20,
	9,
	42 };

void F10RData::ANP1(Entity* ent)
{
}

PlayerData::CallbackData F10RData::anp1 = PlayerData::CallbackData{
	{ 100, -150 },
	{ 300, -360 },
	150,
	200,
	20,
	9,
	42 };

void F10RData::AHP1(Entity* ent)
{
}

PlayerData::CallbackData F10RData::ahp1 = PlayerData::CallbackData{
	{ 100, -150 },
	{ 300, -360 },
	150,
	200,
	20,
	9,
	42 };

void F10RData::ANK1(Entity* ent)
{
}

PlayerData::CallbackData F10RData::ank1 = PlayerData::CallbackData{
	{ 100, -150 },
	{ 300, -360 },
	150,
	200,
	20,
	9,
	42 };

void F10RData::AHK1(Entity* ent)
{
}

PlayerData::CallbackData F10RData::ahk1 = PlayerData::CallbackData{
	{ 100, -150 },
	{ 300, -360 },
	150,
	200,
	20,
	9,
	42 };

void F10RData::GB(Entity* ent)
{
}

PlayerData::CallbackData F10RData::gb = PlayerData::CallbackData{
	{ 100, -150 },
	{ 300, -360 },
	150,
	200,
	20,
	9,
	42 };
