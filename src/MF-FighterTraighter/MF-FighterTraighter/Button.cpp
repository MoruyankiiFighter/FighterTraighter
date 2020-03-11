#include "Button.h"
#include "Entity.h"
#include "Transform.h"

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

void PauseCallback(App* app) {
	app->Pause();
}

void ExitCallback(App* app) {
	app->Exit();
}

void OptionsCallback(App* app) {
	app->Options();
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

void Button::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(app_->getInputManager()->Left)) {
		cout << "click";
		SDL_Point p = { app_->getInputManager()->getMousePosX(),app_->getInputManager()->getMousePosY() };

		Vector2D pos = trans_->getPosition();
		SDL_Rect destRect = { pos.getX(), pos.getY(), trans_->getWidth() * trans_->getWMult(), trans_->getHeight() * trans_->getHMult() };

		if (SDL_PointInRect(&p, &destRect)) {
			cout << "arcade";
			callbackbutton(app_);
		}

		//app_->PlayArcade();
	}

}
