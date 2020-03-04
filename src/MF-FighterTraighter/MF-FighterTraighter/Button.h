#include "Component.h"
#include "RenderImage.h"

using CallBackOnClick = void(App* app);
//callbacks para el menu principal
void ArcadeCallback(App* app);
void OneVsOneCallback(App* app);
void OptionsCallback(App* app);
void ExitCallback(App* app);
//callback para el juego
void PauseCallback(App* app);
//callbacks para el menu pausa
void ContinuePlayingCallback(App* app);
void MovementsCallback(App* app);
void MenuCallback(App* app);

class Button : public Component {

public:
	//constructor
	Button(CallBackOnClick* call) : Component(ecs::Button) { callbackbutton = call; };
	//destructor
	virtual ~Button() {};

	void init() override;
	//handle the input of the mouse by the moment
	void handleInput() override;

private:
	RenderImage* render_ = nullptr;
	CallBackOnClick* callbackbutton = nullptr;
};
