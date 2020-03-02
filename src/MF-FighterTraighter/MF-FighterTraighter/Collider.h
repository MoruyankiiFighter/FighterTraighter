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
	Vector2D pos_;
	Entity* en_;
	Transform* tr_;
	Texture* text_;
	std::string filePath = "../../../../assets/Assets/hitbox.png";

};

