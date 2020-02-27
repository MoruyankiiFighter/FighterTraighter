#pragma once
#include "Component.h"
#include "Transform.h"

class Collider :
	public Component
{
public:
	Collider();
	void update() override;
	void render() override;
private:
	Transform* tr_;
};

