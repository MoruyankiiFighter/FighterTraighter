#pragma once
#include <SDL.h>
#include<SDL_ttf.h>
#include <iostream>
#include "GameStateMachine.h"
#include "InputManager.h"

class App
{
public:
	App();			//constructor
	~App();			//destructor

	void run();		//main

	inline GameStateMachine* getStateMachine() const { return stateMachine_; };

	void update();	//calls update of the current state	
	void render();	//calls render of the current state
	void handleInput(); //calls handleInput of current state
	inline void exitApp() { exit = true; };
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	GameStateMachine* stateMachine_;
	InputManager* inputManager_;

	/*static*/ bool exit;
	void init();	//open the window and creates everything
	void clean();	//deletes everything on the app


};

