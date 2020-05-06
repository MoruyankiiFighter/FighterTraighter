#include "BulletGravity.h"

BulletGravity::BulletGravity(uint16 playerNumber, Vector2D speed, int damage, int hitstun,
	Vector2D knockBack, int time, bool destroyInContact) :
	Bullet(playerNumber,speed,damage,hitstun,knockBack,time,destroyInContact)
{

}
//void BulletGravity::init() {
//	Bullet::init();
//}

void BulletGravity::update()
{
	speed_.setY(speed_.getY() + 0.1);
	transform_->setSpeed(speed_);
}
