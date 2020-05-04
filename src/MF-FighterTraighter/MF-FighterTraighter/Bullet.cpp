#include "Bullet.h"
#include "DestroyOnHit.h"
Bullet::Bullet(uint16 playerNumber, Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact):
	Component(ecs::Bullet), playerNumber_(playerNumber), speed_(speed),damage_(damage),hitstun_(hitstun),
	knockBack_(knockBack), timeAlive_(time),  destroyInContact_(destroyInContact)
{
}
void Bullet::init()
{
	transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	transform_->setSpeed(speed_);
	//	EntityHitboxData(Entity* e, int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, bool destroyOnHit = false) : 
	//cout << damage_ << endl;
	DestroyOnHit* hitbox_ = new DestroyOnHit(damage_,timeAlive_, hitstun_, knockBack_,false, playerNumber_, entity_, destroyInContact_);//create the hitbox's data
	transform_->resetUserData(hitbox_);
	entity_->getState()->addHitbox(playerNumber_,hitbox_,transform_->getMainFixture());

}

//void Bullet::update()
//{
//}



