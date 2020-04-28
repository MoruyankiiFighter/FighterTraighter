#include "FactoryMk.h"
#include "App.h"
#include "PhysicsTransform.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "Crouch.h"
#include "PlayerAttacks.h"
#include "PlayerState.h"
#include "Health.h"
#include "PlayerOnHit.h"
#include "MkWH00PData.h"
#include "PlayerAnimation.h"
#include "InpuState.h"
#include "KeyboardInput.h"
#include "GamepadInput.h"
#include "MockingbirdData.h"
Entity* FactoryMk::addMkToGame(App* app, GameState* state, int orientation, std::vector<SDL_Scancode> keys, b2World* world, bool gamePad, uint16 cBits, uint16 mBits, int playerNumber)
{
	Entity* e = state->getEntityManager().addEntity();
	PhysicsTransform* pT = e->addComponent<PhysicsTransform>(Vector2D(-orientation * 100 + 960, 600), Vector2D(0, 0), 500, 500, 0, world, cBits, mBits, 0);
	pT->getMainFixture()->SetUserData(new PlayerOnHit(e));
	pT->setOrientation(orientation);
	pT->setColliderWidth(pT->getWidth() / 2);
	state->addHurtbox(pT->getMainFixture());

	e->addComponent<InputState>();
	if (!gamePad) {
		e->addComponent<KeyboardInput>(keys);
	}
	else {
		e->addComponent<GamepadInput>();
	}

	PlayerController* pC = e->addComponent<PlayerController>(-7, 4.5);
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::GanonSheet));
	e->addComponent<PlayerState>();
	Health* h = e->addComponent<Health>(110);
	//e->addComponent<PlayerOnHit>();
	PlayerData* pdata = e->addComponent<MkWH00PData>(keys, pT->getWidth(), pT->getHeight(), pT->getRotation(), pC->getJumpImpulse(), Vector2D(-orientation * 100 + 200, 10), pC->getMovSpeed(), h->getHealth(), 1, 50, playerNumber);

	//std::vector<AnimationChain*> chains = app_->getAssetsManager()->getMoveParser()->parseFile("../../../../assets/Assets/Config/MovesMK.txt");
	e->addComponent<PlayerAttacks>(pdata->getNormal_punch(), pdata->air_normal_punch(), pdata->getHard_punch(), pdata->air_hard_punch(),
		pdata->getNormal_kick(), pdata->air_normal_kick(), pdata->getHard_kick(), pdata->air_hard_kick(), pdata->guard_breaker());
	e->addComponent<PlayerAnimation>();

	return e;
}

Entity* FactoryMk::addMockToGame(App* app, GameState* state, int orientation, std::vector<SDL_Scancode> keys, b2World* world, bool gamePad, uint16 cBits, uint16 mBits, int playerNumber)
{
	Entity* e = state->getEntityManager().addEntity();
	PhysicsTransform* pT = e->addComponent<PhysicsTransform>(Vector2D(-orientation * 100 + 960, 600), Vector2D(0, 0), 500, 500, 0, world, cBits, mBits, 0);
	pT->setOrientation(orientation);
	pT->setColliderWidth(pT->getWidth() / 2);
	state->addHurtbox(pT->getMainFixture());

	e->addComponent<InputState>();
	if (!gamePad) {
		e->addComponent<KeyboardInput>(keys);
	}
	else {
		e->addComponent<GamepadInput>();
	}

	PlayerController* pC = e->addComponent<PlayerController>(-7, 4.5);
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::GanonSheet)); // CHANGE ME
	e->addComponent<PlayerState>();
	Health* h = e->addComponent<Health>(100);
	//e->addComponent<PlayerOnHit>();
	PlayerData* p_data_ = e->addComponent<MockingbirdData>(keys, pT->getWidth(), pT->getHeight(), pT->getRotation(), pC->getJumpImpulse(), Vector2D(-orientation * 100 + 200, 10), pC->getMovSpeed(), h->getHealth(), 1, 50, playerNumber);

	//std::vector<AnimationChain*> chains = app_->getAssetsManager()->getMoveParser()->parseFile("../../../../assets/Assets/Config/MovesMK.txt");
	e->addComponent<PlayerAttacks>(p_data_->getNormal_punch(), p_data_->air_normal_punch(), p_data_->getHard_punch(), p_data_->air_hard_punch(),
		p_data_->getNormal_kick(), p_data_->air_normal_kick(), p_data_->getHard_kick(), p_data_->air_hard_kick(), p_data_->guard_breaker());
	e->addComponent<PlayerAnimation>();

	return e;
}
