#pragma once
#include "Component.h"
#include "Texture.h"
//#include "Transform.h"
#include "PhysicsTransform.h"

#include "Entity.h"

class RenderImage: public Component
{
public:
	//constructor
	RenderImage(Texture* tex) : Component(ecs::RenderImage), texture_(tex) { };
	void init() override;
	inline void setTexture(Texture* tex) { texture_ = tex; }
	virtual void render() override;
	~RenderImage() {};
private:
	Transform* transform_=nullptr;
	Texture* texture_=nullptr;
};

