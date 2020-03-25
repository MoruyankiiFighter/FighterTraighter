#pragma once
#include "Component.h"
#include "LinkedGrid.h"
#include "Vector2D.h"

class NavigationController :
	public Component
{
public:
	NavigationController(size_t sizeX, size_t sizeY);
	void init() override;
	void handleInput() override;
	virtual ~NavigationController() {};
	void SetElementInPos(Entity* ent, size_t x, size_t y);
	Entity* GetElementInPos(size_t x, size_t y);
protected:
	LinkedGrid<Entity*> grid_;
	int cursorPositionX_, cursorPositionY_;
};

