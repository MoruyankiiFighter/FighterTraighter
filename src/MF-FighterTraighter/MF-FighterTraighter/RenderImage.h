#pragma once
#include "Component.h"
#include "Texture.h"
//#include "Transform.h"
#include "PhysicsTransform.h"

#include "Entity.h"

class RenderImage: public Component
{
public:
	RenderImage(Texture* tex) : Component(ecs::RenderImage), tex_(tex) { };
	void init() override { trans_ = entity_->getComponent<Transform>(ecs::Transform); };
	virtual void render() override;
	~RenderImage() {};
private:
	Transform* trans_;
	Texture* tex_;
};

