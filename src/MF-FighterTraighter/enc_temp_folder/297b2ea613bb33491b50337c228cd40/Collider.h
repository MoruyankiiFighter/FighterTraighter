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
	virtual void render(); // render textures
private:
<<<<<<< HEAD
	Transform* tr_ = new Transform(Vector2D(300, 500), Vector2D(0, 0), 5.0, 5.0, 0);
	Texture* tex_; 
	Entity* en_;
=======
	Transform* tr_ = new Transform ( Vector2D(500,500), Vector2D(0,0), 50.0, 50.0, 0 );
	Texture* tex_;
	Entity* en_, col_;
>>>>>>> 17b7639f88461f65fe0cc84b18f136a1bb894617
	Vector2D pos_;	
	bool debug_ = true;
	RenderImage* ri_ = new RenderImage(tex_);

	std::string filePath = "../../../../assets/Assets/hitbox.png";
	
};

