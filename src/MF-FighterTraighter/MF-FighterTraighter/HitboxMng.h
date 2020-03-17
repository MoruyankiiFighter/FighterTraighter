#pragma once
#include "Component.h"
#include <list>
#include "hitbox.h"
class HitboxMng : public Component
{
public:
	HitboxMng();
	~HitboxMng() {}
	void update();
	void addHitbox(Vector2D pos, int width, int height, int time, int damage, Vector2D dir);
private:
	list<hitbox*> hitboxList_;
	list<hitbox*> hitboxListToRemove_;

};

