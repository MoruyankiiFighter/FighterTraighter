#pragma once
#include "Component.h"
#include "LinkedGrid.h"
#include "Vector2D.h"
#include "UIElement.h"

class NavigationController :
	public Component
{
public:
	NavigationController(size_t sizeX, size_t sizeY);
	virtual ~NavigationController() {};

	void init() override;
	void handleInput() override;
	
	void SetElementInPos(UIElement* ent, size_t x, size_t y);
	UIElement* GetElementInPos(size_t x, size_t y);

protected:
	LinkedGrid<UIElement*> grid_;
	int cursorPositionX_, cursorPositionY_;

	int findInRowFrom(int y);
	int findInColFrom(int x);
};

