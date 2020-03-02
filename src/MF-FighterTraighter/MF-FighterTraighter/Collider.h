#pragma once
#include "Component.h"
#include "Transform.h"
#include "RenderImage.h"

class Collider: public Component
{
public:
	Collider(Entity* e);
	
	~Collider();
	
	virtual void update();

private:
	Transform* tr_;
	Entity* en_;
	Vector2D pos_;
	std::string filePath = "../../../../assets/Assets/hitbox.png";

};

