#include "App.h"
#include "consts.h"
#include "SDLExceptions.h"
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
	clean();
}

//main loop
void App::run()
{
	exit = false;

	while (!exit) {
		
		Uint32 startTime = SDL_GetTicks();
		
		handleInput();
		update();
		render();

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

//creates the window and the renderer, and opens ttf also set up the state machine and the input manager
void App::init()	
{
	int ttf = TTF_Init();
	if (ttf == -1) {
		throw new SDLExceptions::TTFException(TTF_GetError() + std::string("\nUnable to init TTF"));
	}

	int e = SDL_Init(SDL_INIT_EVERYTHING);
	if (e > 0) {
		throw new SDLExceptions::SDLException(SDL_GetError() + std::string("\nUnable to init SDL"));
	}
	//int nJoysticks = SDL_NumJoysticks();
    
	/*SDL_Joystick* joystick = SDL_JoystickOpen(0);
	std::cout << "Controller Name:" << SDL_JoystickName(joystick) << std::endl;
	std::cout << "Num Axes :" << SDL_JoystickNumAxes(joystick) << std::endl;
	std::cout << "Num Buttons :" << SDL_JoystickNumButtons(joystick) << std::endl;*/
	
	window = SDL_CreateWindow("Fighter Traighter ver 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH_, WINDOW_HEIGHT_, SDL_WINDOW_SHOWN);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, WINDOW_WIDTH_, WINDOW_HEIGHT_); //para que se redimensionen a su proporcion
	if (!window || !renderer) {
		throw new SDLExceptions::SDLException("Unable to create window or renderer");
	}

	stateMachine_.reset(new GameStateMachine());
	inputManager_.reset(new InputManager(this));
	assetsManager_.reset(new AssetsManager(this));
	hitboxManager_.reset(new HitboxMng(this));

	stateMachine_->pushState(new MainMenu(this));
}

void App::clean()
{
	// Reset pointers to prevent errors (especially assetsManager)
	stateMachine_.reset();
	inputManager_.reset();
	// If we try to close fonts after TTF_Quit(), an error will occur
	assetsManager_.reset();

	// Delete SDL's attributes
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	TTF_Quit();
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
	getStateMachine()->pushState(new Training(this));
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

//pause the game
void App::Pause() {
	getStateMachine()->pushState(new PauseMenu(this));
}


void App::Movements() {
	std::cout << "Movements" << endl;
	//getStateMachine()->pushState(new Movements());
}
