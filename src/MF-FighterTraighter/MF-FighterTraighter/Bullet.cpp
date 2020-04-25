#include "Bullet.h"
#include "EntityHitboxData.h"
Bullet::Bullet(GameState* state, uint16 playerNumber, Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact):
	Component(ecs::Bullet), state_(state), playerNumber_(playerNumber), speed_(speed),damage_(damage),hitstun_(hitstun),
	knockBack_(knockBack), timeAlive_(time),  destroyInContact_(destroyInContact)
{
}
void Bullet::init()
{
	transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	transform_->setSpeed(speed_);
	//	EntityHitboxData(Entity* e, int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, bool destroy = false) : 
	cout << damage_ << endl;
	EntityHitboxData* hitbox_ = new EntityHitboxData( entity_, damage_,timeAlive_, hitstun_, knockBack_,false/*,false,destroyInContact_ */,false );//create the hitbox's data
	transform_->getMainFixture()->SetUserData(hitbox_);
	state_->addHitbox(playerNumber_,hitbox_,transform_->getMainFixture());

}



