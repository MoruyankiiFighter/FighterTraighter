#pragma once
#include "Component.h"
#include "Transform.h"
#include "RenderImage.h"
#include "Texture.h"

class Collider : public Component
{
public:
	Collider(Entity* e);
	~Collider();
	virtual void update(); // main update of the component
	virtual void init(); // get required pointers at runtime
	//virtual void handleInput(); // gets called before update, use for input
	virtual void render(); // render textures
private:
	Transform* tr_ = new Transform ( Vector2D(500,500), Vector2D(0,0), 50.0, 50.0, 0 );
	Texture* tex_;
	Entity* en_, col_;
	Vector2D pos_;	
	bool debug_ = true;

	std::string filePath = "../../../../assets/Assets/hitbox.png";
	RenderImage* ri_ = new RenderImage (tex_);
};

