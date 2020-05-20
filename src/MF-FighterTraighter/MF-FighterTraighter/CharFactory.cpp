#include "CharFactory.h"
#include "App.h"
#include "PhysicsTransform.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "PlayerAttacks.h"
#include "PlayerState.h"
#include "Health.h"
#include "PlayerOnHit.h"
#include "MkWH00PData.h"
#include "PlayerAnimation.h"
#include "MockingbirdData.h"
#include "F10RData.h"
#include "PlayerParticleSystem.h"

Entity* CharFactory::addCharacterToGame(App* app, GameState* state, double orientation, b2World* world, const GameManager::PlayerInfo* character, uint16 cBits, uint16 mBits, int playerNumber)
{
	Entity* e = state->getEntityManager().addEntity();
	PhysicsTransform* pT = e->addComponent<PhysicsTransform>(Vector2D(-orientation * 100.0 + 960, 700), Vector2D(0, 0), 500, 500, 0, world, cBits, mBits, 0);
	pT->resetUserData(new PlayerOnHit(e));
	pT->setOrientation(orientation);
	pT->setColliderWidth(pT->getWidth() / 2);
	pT->getBody()->SetLinearDamping(10);	//friction
	state->addHurtbox(pT->getMainFixture());

	PlayerController* pC = e->addComponent<PlayerController>(character->hid, -7, 4.5);
	e->addComponent<PlayerState>();
	
	PlayerData* pdata = nullptr;
	Health* h = nullptr;

	switch (character->character){
	case(GameManager::MKWh00p):
		e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::GanonSheet));
		h = e->addComponent<Health>(110);
		pdata = e->addComponent<MkWH00PData>(pT->getWidth(), pT->getHeight(), pT->getRotation(), pC->getJumpImpulse(), Vector2D(-orientation * 100.0 + 200, 10), pC->getMovSpeed(), h->getHealth(), 1, 1, playerNumber);	
		if(pdata->getPlayerNumber()==0)
			app->getGameManager()->setPlayer1Sound(app->getAssetsManager()->getSFX(AssetsManager::MKWOP_1));
		else 		
			app->getGameManager()->setPlayer2Sound(app->getAssetsManager()->getSFX(AssetsManager::MKWOP_1));

		break;
	case(GameManager::Mockingbird):
		e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::GanonSheet)); 
		h = e->addComponent<Health>(100);
		pdata = e->addComponent<MockingbirdData>(pT->getWidth(), pT->getHeight(), pT->getRotation(), pC->getJumpImpulse(), Vector2D(-orientation * 100.0 + 200, 10), pC->getMovSpeed(), h->getHealth(), 1, 1, playerNumber);
		if (pdata->getPlayerNumber() == 0)
			 app->getGameManager()->setPlayer1Sound(app->getAssetsManager()->getSFX(AssetsManager::MKBIRD_1));
		else
			app->getGameManager()->setPlayer2Sound(app->getAssetsManager()->getSFX(AssetsManager::MKBIRD_1));

		break;
	case(GameManager::F10R):
		e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::F10rSheet));
		h = e->addComponent<Health>(100);
		pdata = e->addComponent<F10RData>(pT->getWidth(), pT->getHeight(), pT->getRotation(), pC->getJumpImpulse(), Vector2D(-orientation * 100.0 + 200, 10), pC->getMovSpeed(), h->getHealth(), 1, 1, playerNumber);
		if (pdata->getPlayerNumber() == 0)
			app->getGameManager()->setPlayer1Sound(app->getAssetsManager()->getSFX(AssetsManager::FLOR_1));
		else
			app->getGameManager()->setPlayer2Sound(app->getAssetsManager()->getSFX(AssetsManager::FLOR_1));

		break;
	case(GameManager::Aisha):
		e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::GanonSheet));
		h = e->addComponent<Health>(100);
		pdata = e->addComponent<MkWH00PData>(pT->getWidth(), pT->getHeight(), pT->getRotation(), pC->getJumpImpulse(), Vector2D(-orientation * 100.0 + 200, 10), pC->getMovSpeed(), h->getHealth(), 1, 1, playerNumber);
		break;
	default:
#ifdef _DEBUG
		cout << "No valid character id" << endl;
#endif
		break;
	}

	//std::vector<AnimationChain*> chains = app_->getAssetsManager()->getMoveParser()->parseFile("../../../../assets/Assets/Config/MovesMK.txt");
	e->addComponent<PlayerAttacks>(character->hid, pdata->getNormal_punch(), pdata->air_normal_punch(), pdata->getHard_punch(), pdata->air_hard_punch(),
		pdata->getNormal_kick(), pdata->air_normal_kick(), pdata->getHard_kick(), pdata->air_hard_kick(), pdata->guard_breaker());
	e->addComponent<PlayerAnimation>();
	e->addComponent<PlayerParticleSystem>(10);

	return e;
}
