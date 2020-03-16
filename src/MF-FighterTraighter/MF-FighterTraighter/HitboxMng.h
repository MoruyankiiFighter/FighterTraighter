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
private:
	list<hitbox*> hitboxList_;
	list<hitbox*> hitboxListToRemove_;

};

