#pragma once
#include <SDL.h>
#include<SDL_ttf.h>
#include <iostream>
#include "GameStateMachine.h"

class App
{
public:
	App();			//constructor
	~App();			//destructor

	void run();		//main

	inline GameStateMachine* getStateMachine() const { return stateMachine_; };

	void update();	//calls update of the current state	
	void render();	//calls render of the current state
	void handleInput();//to start testing, after remove it
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	GameStateMachine* stateMachine_;

	/*static*/ bool exit;
	void init();	//open the window and creates everything
	void clean();	//deletes everything on the app


};

