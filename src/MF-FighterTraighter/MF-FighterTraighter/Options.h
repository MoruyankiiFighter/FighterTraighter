#pragma once
#include "GameState.h"

class App;
//callbacks para las opciones

void fullScreenCallback(App* app);
void SetResolution(App* app);

class Options: public GameState
{
public:
	Options(App* app);
	virtual ~Options();

	void init() override;
	virtual void update() override;
	virtual void render() override;

private:

	//by the moment for changing resolutions
	Entity* fullscreen;
	Entity* audiovolume;
	Entity* backtomenu;
};

