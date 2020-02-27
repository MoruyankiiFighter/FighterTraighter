#include "Button.h"

Button::Button(Transform* butt, Texture* button_, GameState* state_, CallBackOnClick* _call)
	: Entity(), button(butt), buttonTex(button_), callbackbutton(_call), state(state_) {
}

void ArcadeCallback(App* app) {
	//app->PlayArcade();
}

void PauseCallback(App* app) {
	//app->Pause();
}

void ExitCallback(App* app) {
	//app->Exit();
}

void OnevsOneCallback(App* app) {
	//app->PlayOnevsOne();
}

void ContinuePlayingCallback(App* app) {
	//app->ContinuePlaying();
}

void OptionsCallback(App* app) {
	//app->Options();
}

void MenuCallback(App* app) {
	//app->Menu();
}

void MovementsCallback(App* app) {
	//app->Menu();
}

void Button::render() {

}

void Button::handleEvent(SDL_Event& event) {

	if ((event.type == SDL_MOUSEBUTTONUP) && (event.button.button == SDL_BUTTON_LEFT)) {
		SDL_Point mousePoint = { event.button.x, event.button.y };

		if (SDL_PointInRect(&mousePoint, button->getDestRect())) {
			callbackbutton(state->giveMeApp());
		}
	}
}