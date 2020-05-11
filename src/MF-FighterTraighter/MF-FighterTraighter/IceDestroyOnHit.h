#pragma once
#include "DestroyOnHit.h"
#include "PlayerState.h"
class IceDestroyOnHit : public DestroyOnHit
{
public:
	IceDestroyOnHit(int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, Entity* e, bool mHit = false) :
		DestroyOnHit(damage, time, hitstun, knockback, guardbreaker, id, e, mHit) {}

	virtual void onHit(b2Fixture* other) {
		UserData* data = static_cast<UserData*>(other->GetUserData());
		if (data && data->entity_->getComponent<PlayerState>(ecs::PlayerState)->isGuardingStun()) {	//When the ice has hit (SPECIAL CASE)
			hitstun_ /= 10;
			data->entity_->getComponent<PlayerState>(ecs::PlayerState)->goGuardingStun(hitstun_ / 10);
		}

		PhysicsTransform* phTr = data->entity_->getComponent<PhysicsTransform>(ecs::Transform);
		int orientation_ = phTr->getOrientation();
		int width = 260;
		int projX = phTr->getPosition().getX() + (phTr->getWidth() * 1 / 4) + (phTr->getWidth() / 4);
		if (orientation_ == -1) projX = phTr->getPosition().getX() + (phTr->getWidth() * 3 / 4) - (phTr->getWidth() / 4);
		Vector2D pos = Vector2D(projX, phTr->getPosition().getY() + (phTr->getHeight() / 2) - 15);
		DestroyAtTime* dT = new DestroyAtTime(0, hitstun_, 0, { 0,0 }, false, data->entity_->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), data->entity_);
		AbilityFactory::instanceEntitywHitbox(data->entity_, 250, 530, pos, { 0, 0 }, data->entity_->getState()->NONE, data->entity_->getState(), 
			data->entity_->getApp(), data->entity_->getApp()->getAssetsManager()->getTexture(AssetsManager::Hb2), orientation_, dT);
		DestroyOnHit::onHit(other);
	}
	virtual ~IceDestroyOnHit() {}
};