#include "App.h"

App::App()
{
	init();
}

App::~App()
{
	// Se borran atributos de SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void App::run()
{
}

void App::update()
{
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
