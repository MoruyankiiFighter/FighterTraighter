#pragma once
#include "Component.h"
#include "Texture.h"
//#include "Transform.h"
#include "PhysicsTransform.h"

#include "Entity.h"

class RenderImage : public Component
{
public:
	RenderImage(Texture* tex) : Component(ecs::RenderImage), tex_(tex) { };
	void init() override {
		trans_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	};
	inline void setTexture(Texture* tex) { tex_ = tex; }
	inline void setFrame(size_t x, size_t y) { curX = x; curY = y; }
	virtual void render() override;
	~RenderImage() {};
private:
	Transform* trans_ = nullptr;
	Texture* tex_ = nullptr;
	int curX = 0, curY = 0;
};

