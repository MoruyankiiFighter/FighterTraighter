#pragma once
#include "Component.h"
#include "Texture.h"
#include "PhysicsTransform.h"
#include "Entity.h"

class RenderImage: public Component
{
public:
	//constructor
	RenderImage(Texture* tex) : Component(ecs::RenderImage), texture_(tex) { };
	//destructor
	~RenderImage() {};

	// methods overrided from component
	void init() override ;
	virtual void render() override;
private:
	Transform* transform_=nullptr;
	Texture* texture_=nullptr;
};

