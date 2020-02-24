#include "App.h"

std::unique_ptr<App> App::instance_;

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

	delete stateMachine_;
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
	InputManager::instance()->update();

	stateMachine_->getCurrentState()->handleInput();
}

void App::update()
{
	std::cout << "Pulsa ESCAPE para cerrar la ventana"<<std::endl;//testing
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
		800, 800, SDL_WINDOW_SHOWN); //a�adir constantes aqui
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!window || !renderer) {
		//throw another Error
	}
	
	stateMachine_ = new GameStateMachine();

	// PLACE STATE
								// PLACE STATE
															// PLACE STATE
}

void App::clean()
{

}
