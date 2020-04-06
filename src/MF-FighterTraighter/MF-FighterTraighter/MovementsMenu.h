#pragma once
#include "GameState.h"
#include "Texture.h"
#include <vector>
class App;

class MovementsMenu : public GameState
{
private:
	vector<Entity*> controls_;
public:
	//constructor
	MovementsMenu(App* app);
	//destructor
	virtual ~MovementsMenu();

	//methods overrided from GameState where we create the entitys
	void init() override;

	//callback
	static void GoBack(App* app);
};

