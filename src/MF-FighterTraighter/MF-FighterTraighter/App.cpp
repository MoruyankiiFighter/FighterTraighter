#include "App.h"
#include "consts.h"

#include "PauseMenu.h"
#include "Options.h"
#include "Fight.h"


App::App()
{
	init();
}

App::~App()
{
	// Delete SDL's attributes
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//main loop
void App::run()
{
	exit = false;

	while (!exit) {
		
		Uint32 startTime = SDL_GetTicks();
		
		update();
		render();
		handleInput();

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

void App::handleInput() 
{

	inputManager_->update();

	stateMachine_->getCurrentState()->handleInput();
}

void App::update()
{
	stateMachine_->getCurrentState()->update();
}

void App::render()
{
	stateMachine_->getCurrentState()->render();
}

//creates the window and the renderer also set up the state machine and the input manager
void App::init()	
{
	int e = SDL_Init(SDL_INIT_EVERYTHING);
	if (e > 0) {
		//throw an error
	}
	
	window = SDL_CreateWindow("Fighter Traighter ver 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH_, WINDOW_HEIGHT_, SDL_WINDOW_SHOWN);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!window || !renderer) {
		//throw another Error
	}

	stateMachine_.reset(new GameStateMachine());
	inputManager_.reset(new InputManager(this));

	Menu();
}

void App::clean()
{

}


//init the main menu
void App::Menu() {
	while (!stateMachine_->empty()) {
		stateMachine_->popState();
	}

	stateMachine_->pushState(new MainMenu(this));
}

//set up arcade state
void App::PlayArcade() {
	getStateMachine()->pushState(new Fight(this));
}

//set up the options state
void App::Options() {
	//getStateMachine()->pushState();
}

//set up pvp state
void App::PlayOnevsOne() {
	//getStateMachine()->pushState(new PlayOneVsOne());
}

//quit pause state to previous state
void App::ContinuePlaying() {
	getStateMachine()->popState();
}

//quit game
void App::Exit() {
	SDL_Quit();
}

//pause the game
void App::Pause() {
	//getStateMachine()->pushState(new PauseMenu(this));
}


void App::Movements() {
	//getStateMachine()->pushState(new Movements());
}
