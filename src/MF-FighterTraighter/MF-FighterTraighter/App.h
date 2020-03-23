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
	App();			//constructor
	App(App&) = delete;
	App& operator= (App&) = delete;
	~App();			//destructor

	void run();		//main

	inline SDL_Renderer* getRenderer() const { return renderer; };

	inline GameStateMachine* getStateMachine() const { return stateMachine_.get(); };
	inline InputManager* getInputManager() const { return inputManager_.get(); };
	inline AssetsManager* getAssetsManager() const { return assetsManager_.get(); };
	inline HitboxMng* getHitboxMng() const { return hitboxManager_.get(); };
	inline WindowManager* getWindowManager() const { return windowManager_.get(); };

	void update();	//calls update of the current state
	void render();	//calls render of the current state
	void handleInput(); //calls handleInput of current state

	void PlayArcade();
	void Pause();
	inline void Exit() { exit = true; } //quit game
	void PlayOnevsOne();
	void ContinuePlaying();
	void Options();
	void Menu();
	void Movements();

private:
	SDL_Renderer* renderer;

	std::unique_ptr<GameStateMachine> stateMachine_;
	std::unique_ptr<InputManager> inputManager_;
	std::unique_ptr<AssetsManager> assetsManager_;
	std::unique_ptr<HitboxMng> hitboxManager_;
	std::unique_ptr<WindowManager> windowManager_;

	
	/*static*/ bool exit;
	void init();	//open the window and creates everything
	void clean();	//deletes everything on the app
};

