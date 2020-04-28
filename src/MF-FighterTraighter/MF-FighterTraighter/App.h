#pragma once
#include <SDL.h>
#include <iostream>
#include "GameStateMachine.h"
#include "InputManager.h"
#include "MainMenu.h"
#include "AssetsManager.h"
#include "HitboxMng.h"
#include "WindowManager.h"

class App
{
public:
	//constructor
	App();			
	App(App&) = delete;
	App& operator= (App&) = delete;
	
	//destructor
	~App();

	//main loop
	void run();		

	//returns the SDL_Renderer
	inline SDL_Renderer* getRenderer() const { return renderer; };
	
	//returns the game state machine of the scenes
	inline GameStateMachine* getStateMachine() const { return stateMachine_.get(); };
	
	//returns the input manager for handling events
	inline InputManager* getInputManager() const { return inputManager_.get(); };
	
	//returns the assets manager/ resources manager for getting textures, fonts or audio elements
	inline AssetsManager* getAssetsManager() const { return assetsManager_.get(); };
	
	//returns the hitbox manager for handling the collisions
	inline HitboxMng* getHitboxMng() const { return hitboxManager_.get(); };
	
	//returns the window manager
	inline WindowManager* getWindowManager() const { return windowManager_.get(); };

	
	//calls update of the current state
	void update();	
	
	//calls render of the current state
	void render();	
	
	//calls handleInput of current state
	void handleInput(); 

	//methods that changes the current state
	void PlayArcade();
	void Pause();
	inline void Exit() { exit = true; } //quit game
	void PlayOnevsOne();
	void ContinuePlaying();
	void Options();
	void Menu();
	void Movements();

	void SelectSkills();


private:
	
	//open the window and creates everything
	void init();	

	//deletes everything on the app
	void clean();	


	SDL_Renderer* renderer;
	std::unique_ptr<GameStateMachine> stateMachine_; //game state machine
	std::unique_ptr<InputManager> inputManager_;//input manager
	std::unique_ptr<AssetsManager> assetsManager_;//assets manager
	std::unique_ptr<HitboxMng> hitboxManager_;//hitbox manager
	std::unique_ptr<WindowManager> windowManager_;//window manager

	
	/*static*/ bool exit;
};

