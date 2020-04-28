#include "App.h"
#include "consts.h"
#include "SDLExceptions.h"
#include "PauseMenu.h"
#include "Fight.h"
#include "OptionsMenu.h"
#include "Training.h"
#include "SkillSelection.h"

#include <SDL_mixer.h>

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
		stateMachine_->deleteStates();

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 1000 / frameRate_)
			SDL_Delay(1000 / frameRate_ - frameTime);
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

	/*if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)<0) {
		throw new SDLExceptions::SDLException("\nUnable to load audio");
	}*/
	//if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
	//	throw new SDLExceptions::SDLException("\nUnable to load audio");
	//}

	int e = SDL_Init(SDL_INIT_EVERYTHING);
	if (e > 0) {
		throw new SDLExceptions::SDLException(SDL_GetError() + std::string("\nUnable to init SDL"));
	}
	windowManager_.reset(new WindowManager(this));

	renderer = SDL_CreateRenderer(windowManager_->getWindow(), -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, windowManager_->getCurResolution().w, windowManager_->getCurResolution().h); //para que se redimensionen a su proporcion
	if (!renderer) {
		throw new SDLExceptions::SDLException("Unable to create renderer");
	}

	stateMachine_.reset(new GameStateMachine());
	inputManager_.reset(new InputManager(this));
	assetsManager_.reset(new AssetsManager(this));
	gameManager_.reset(new GameManager(this));

}

void App::clean()
{
	// Reset pointers to prevent errors (especially assetsManager)
	stateMachine_.reset();
	inputManager_.reset();
	// If we try to close fonts after TTF_Quit(), an error will occur
	assetsManager_.reset();
	windowManager_.reset();
	gameManager_.reset();

	// Delete SDL's attributes
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	TTF_Quit();
}
