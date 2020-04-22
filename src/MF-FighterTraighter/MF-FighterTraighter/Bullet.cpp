#include "Bullet.h"
Bullet::Bullet(GameState* state, uint16 playerNumber, Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact):
	Component(ecs::Bullet), state_(state), playerNumber_(playerNumber), speed_(speed),damage_(damage),hitstun_(hitstun),
	knockBack_(knockBack), timeAlive_(time),  destroyInContact_(destroyInContact)
{
}
void Bullet::init()
{
	transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	transform_->setSpeed(speed_);
	HitboxData* hitbox_ = new HitboxData{ damage_,timeAlive_, hitstun_, knockBack_,false,false,destroyInContact_ ,true, entity_};//create the hitbox's data
	transform_->getMainFixture()->SetUserData(hitbox_);
	state_->addHitbox(playerNumber_,hitbox_,transform_->getMainFixture());

}



