#include "App.h"

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
//testing, probably remove it
void App::handleInput() {
	
	
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		else if (event.key.keysym.sym == SDLK_ESCAPE) {
			exit=true;
		}
	}
}

void App::update()
{
	std::cout << "Pulsa ESCAPE para cerrar la ventana"<<std::endl;//testing
}

void App::render()
{
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
	
}

void App::clean()
{

}
