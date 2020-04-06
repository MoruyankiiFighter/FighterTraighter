#pragma once
#include "Component.h"
#include "Texture.h"
//#include "Transform.h"
#include "PhysicsTransform.h"

#include "Entity.h"

class RenderImage : public Component
{
public:
	//constructor
	RenderImage(Texture* tex) : Component(ecs::RenderImage), texture_(tex) { };
	inline void setFrame(size_t x, size_t y) { curX = x; curY = y; }
	//destructor
	~RenderImage();
	
	inline void setTexture(Texture* tex) { texture_ = tex; }
	void init();
	//method overrided from Component
	virtual void render() override;
private:
	size_t curX = 0, curY = 0;
	Transform* transform_=nullptr;
	Texture* texture_=nullptr;
};

