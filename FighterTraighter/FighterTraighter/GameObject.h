#pragma once
class GameObject
{
public:
	GameObject();
	void Render();
	void Update();
	~GameObject();
private:
	//Texture texture;
	int posX, posY;
};

