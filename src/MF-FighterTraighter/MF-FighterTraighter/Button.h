#include "Component.h"
#include "RenderImage.h"

using CallBackOnClick = void(App* app);

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
	Transform* trans_ = nullptr;
	CallBackOnClick* callbackbutton = nullptr;
};
