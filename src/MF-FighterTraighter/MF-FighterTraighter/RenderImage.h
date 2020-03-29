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
	//destructor
	~RenderImage();
	
	inline void setTexture(Texture* tex) { texture_ = tex; }
	void init();
	//method overrided from Component
	virtual void render() override;
private:
	Transform* transform_=nullptr;
	Texture* texture_=nullptr;
};

