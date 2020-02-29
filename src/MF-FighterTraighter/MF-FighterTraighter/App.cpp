#include "App.h"
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
		
		handleInput();
		update();
		render();

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

void App::handleInput() {

	// update input state
	inputManager_->update();

	stateMachine_->getCurrentState()->handleInput();
}

void App::update()
{
	//std::cout << "Pulsa ESCAPE para cerrar la ventana"<<std::endl;//testing
	stateMachine_->getCurrentState()->update();
}

void App::render()
{
	stateMachine_->getCurrentState()->render();
}

void App::init()	//creates the window and the renderer
{
	int e = SDL_Init(SDL_INIT_EVERYTHING);
	if (e > 0) {
		//throw an error
	}
	window = SDL_CreateWindow("Fighter Traighter ver 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 800, SDL_WINDOW_SHOWN); //añadir constantes aqui
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!window || !renderer) {
		//throw another Error
	}
	
	stateMachine_.reset(new GameStateMachine());
	inputManager_.reset(new InputManager(this));

	Menu();

	//stateMachine_->pushState(new Fight(this));
}

void App::clean()
{

}

void App::PlayArcade() {
	//getStateMachine()->pushState(new PlayArcade());
}

void App::PlayOnevsOne() {
	//getStateMachine()->pushState(new PlayOneVsOne());
}

void App::ContinuePlaying() {
	//getStateMachine()->pushState(new PlayArcade());
}

void App::Exit() {
	SDL_Quit();
}

void App::Pause() {
	//getStateMachine()->pushState(new Pause());
}

void App::Menu() {
	stateMachine_->pushState(new MainMenu(this));
}

void App::Options() {
	//getStateMachine()->pushState(new Options());
}

void App::Movements() {
	//getStateMachine()->pushState(new Movements());
}