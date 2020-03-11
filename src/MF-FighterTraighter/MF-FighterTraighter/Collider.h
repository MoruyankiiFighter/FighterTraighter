#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include "RenderImage.h"
#include "Texture.h"

class Collider : public Component
{
public:
	Collider();//Constructora vacia
	~Collider();//Destructora vacia
	virtual void update(); // main update of the component
	virtual void init(); // get required pointers at runtime
	virtual void render() override; // render textures
private:
	int liveFrames_= 1;
	bool destroy_ = false;
	PhysicsTransform PhyT_;
	Vector2D pos_;	//Entity_ position
	Vector2D tam_;
	int daño;
	//Transform* tr_; //Banana for Scale
	//Texture* tex_;  //Green square
	//bool debug_ = true; //for debugging purpouses
	
	std::string filePath = "../../../../assets/Assets/hitbox.png"; //filepath Greenbox
	
};

