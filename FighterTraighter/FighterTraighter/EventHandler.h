#pragma once
#include <SDL.h>

class EventHandler
{
public:
	//method which character will inherance for handling their events
	virtual void HandleEvents(SDL_Event& ev)=0; 
};
