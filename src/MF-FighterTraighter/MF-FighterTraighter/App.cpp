#include "App.h"
#include "consts.h"

#include "PauseMenu.h"
#include "Fight.h"
#include "OptionsMenu.h"
#include "Training.h"


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
	int ttf = TTF_Init();
	if (ttf == -1) {
		//throw an error
	}

	int e = SDL_Init(SDL_INIT_EVERYTHING);
	if (e > 0) {
		//throw an error
	}
	SDL_Joystick* joystick = SDL_JoystickOpen(0);
	if (joystick != nullptr) {
		std::cout << "Controller Name:" << SDL_JoystickName(joystick) << std::endl;
		std::cout << "Num Axes :" << SDL_JoystickNumAxes(joystick) << std::endl;
		std::cout << "Num Buttons :" << SDL_JoystickNumButtons(joystick) << std::endl;
	}
	window = SDL_CreateWindow("Fighter Traighter ver 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH_, WINDOW_HEIGHT_, SDL_WINDOW_SHOWN);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!window || !renderer) {
		//throw another Error
	}

	stateMachine_.reset(new GameStateMachine());
	inputManager_.reset(new InputManager(this));
	assetsManager_.reset(new AssetsManager(this));

	stateMachine_->pushState(new MainMenu(this));
}

void App::clean()
{

}


//init the main menu
void App::Menu() {
	GameState* currState = stateMachine_->getCurrentState();
	while (dynamic_cast<MainMenu*>(currState) == nullptr) {
		stateMachine_->popState();
		currState = stateMachine_->getCurrentState();
	}
}

//set up arcade state
void App::PlayArcade() {
	getStateMachine()->pushState(new Fight(this));
}

//set up the options state
void App::Options() {
	getStateMachine()->pushState(new OptionsMenu(this));
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
	TTF_Quit();
}

//pause the game
void App::Pause() {
	//getStateMachine()->pushState(new PauseMenu(this));
}


void App::Movements() {
	std::cout << "Movements" << endl;
	//getStateMachine()->pushState(new Movements());
}
