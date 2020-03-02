#pragma once
#include "Component.h"
#include "Transform.h"
#include "RenderImage.h"

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
	Transform* tr_ = new Transform ( Vector2D(300,500), Vector2D(0,0), 50.0, 50.0, 0 );
	Texture* tex = new Texture(app_->getRenderer(), filePath.c_str(), 1, 1);
	Entity* en_;
	Vector2D pos_;	
	bool debug = true;
	std::string filePath = "../../../../assets/Assets/hitbox.png";
	RenderImage* ri_ = new RenderImage (tex);
};

