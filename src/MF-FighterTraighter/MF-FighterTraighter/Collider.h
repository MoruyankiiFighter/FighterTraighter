#pragma once
#include "Component.h"
#include "Transform.h"
#include "RenderImage.h"
#include "Texture.h"

class Collider : public Component
{
public:
	Collider();//Constructora vacia
	~Collider();//Destructora vacia
	virtual void update(); // main update of the component
	virtual void init(); // get required pointers at runtime
	virtual void render(); // render textures
private:
	Transform* tr_; //Banana for Scale
	Texture* tex_;  //Green square
	Vector2D pos_;	//Entity_ position
	bool debug_ = true; //for debugging purpouses
	

	std::string filePath = "../../../../assets/Assets/hitbox.png"; //filepath Greenbox
	
};

