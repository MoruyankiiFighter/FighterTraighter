#pragma once
#include <SDL.h>
#include<SDL_ttf.h>

class App
{
public:
	App();			//constructor
	~App();			//destructor

	void run();		//main

	void update();	//calls update of the current state	
	void render();	//calls render of the current state
	
private:

};

