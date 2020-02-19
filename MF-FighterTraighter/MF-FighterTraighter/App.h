#pragma once
#include <SDL.h>
#include<SDL_ttf.h>
#include <iostream>
class App
{
public:
	App();			//constructor
	~App();			//destructor

	void run();		//main

	void update();	//calls update of the current state	
	void render();	//calls render of the current state
	void handleInput();//to start testing, after remove it
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	/*static*/ bool exit;
	void init();	//open the window and creates everything
	void clean();	//deletes everything on the app


};

