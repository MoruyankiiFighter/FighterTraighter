#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"
#include "OptionsMenu.h"
#include "consts.h"

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

void OptionsCallback(App* app)
{
	app->Options();
}



///AÑADIR SOUND MANAGER 
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

	float volume_ = 0; //app_->getAudioManager()->getGeneralVolume();

	if (volume_ - 0.1 > 0) {
		volume_ = 0;
	}
	else {
		volume_ -= 0.1;
	}
}



//-------------------------------






void Button::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(app_->getInputManager()->Left)) {
		SDL_Point p = { app_->getInputManager()->getMousePosX(),app_->getInputManager()->getMousePosY() };

		Vector2D pos = trans_->getPosition();
		SDL_Rect destRect = { pos.getX(), pos.getY(), trans_->getWidth() * trans_->getWMult(), trans_->getHeight() * trans_->getHMult() };

		if (SDL_PointInRect(&p, &destRect)) {
			//cout << "arcade";
			callbackbutton(app_);
		}
	}

}
