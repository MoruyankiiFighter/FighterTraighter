#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"

void Button::init()
{
	trans_ = entity_->getComponent<Transform>(ecs::Transform);
}

void ArcadeCallback(App* app) {
	app->PlayArcade();
}

void OneVsOneCallback(App* app) {
	app->PlayOnevsOne();
}

//void PauseCallback(App* app) {
//	app->Pause();
//}

void ExitCallback(App* app) {
	app->Exit();
}

void ContinuePlayingCallback(App* app) {
	app->ContinuePlaying();
}

void MovementsCallback(App* app) {
	app->Movements();
}

void MenuCallback(App* app) {
	app->Menu();
}

void OptionsCallback(App* app)
{
	app->Options();
}

//brightness
void moreBright(App* app) {
	float bright = SDL_GetWindowBrightness(app->getWindow());

	if (bright >= 1)
		bright = 1;
	else
		bright += 0.1;

	SDL_SetWindowBrightness(app->getWindow(), bright);

}
void lessBright(App* app) {
	float bright = SDL_GetWindowBrightness(app->getWindow());

	if (bright <= 0)
		bright = 0;
	else
		bright -= 0.1;

	SDL_SetWindowBrightness(app->getWindow(), bright);
}

///A�ADIR SOUND MANAGER 
//volume music
void moreVolume(App* app) {
	float volume_ = 0; //app_->getAudioManager()->getGeneralVolume();

	if (volume_ + 0.1 > 1) {
		volume_ = 1;
	}
	else {
		volume_ += 0.1;
	}

}
void lessVolume(App app) {

	float volume_ = 0;
}

//SFXVolume
void moreSFXVolume(App* app) {

}
void lessSFXVolume(App* app) {

}

//-------------------------------

//fullscreen
void fullScreen(App* app) {
	bool IsFullscreen = SDL_GetWindowFlags(app->getWindow()) & SDL_WINDOW_FULLSCREEN_DESKTOP;
	if (IsFullscreen)
	{
		SDL_SetWindowFullscreen(app->getWindow(), 0);
	}
	else
	{
		SDL_SetWindowFullscreen(app->getWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
}




void Button::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(app_->getInputManager()->Left)) {
		cout << "click";
		SDL_Point p = { app_->getInputManager()->getMousePosX(),app_->getInputManager()->getMousePosY() };

		Vector2D pos = trans_->getPosition();
		SDL_Rect destRect = { pos.getX(), pos.getY(), trans_->getWidth() * trans_->getWMult(), trans_->getHeight() * trans_->getHMult() };

		if (SDL_PointInRect(&p, &destRect)) {
			//cout << "arcade";
			callbackbutton(app_);
		}
	}

}
