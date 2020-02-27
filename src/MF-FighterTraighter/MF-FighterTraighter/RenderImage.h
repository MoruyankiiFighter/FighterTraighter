#pragma once
#include "Component.h"
#include "Texture.h"
#include "Transform.h"
#include "Entity.h"

class RenderImage: public Component
{
public:
	RenderImage(Texture* texture) : Component(ecs::RenderImage), texture_(texture) { };
	void init() override { trans_ = entity_->getComponent<Transform>(ecs::Transform); };
	virtual void render() override;
	~RenderImage() {};
private:
	Transform* trans_;
	Texture* texture_;
};

