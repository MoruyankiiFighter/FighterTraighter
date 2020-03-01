#include "Component.h"
using callBackOnClick = void(string text);

class Button : public Component {
	Button(callBackOnClick* funct) : Component(ecs::Button), funct_(funct) {};
	~Button() {};
	void handleInput() override;
private:
	callBackOnClick* funct_;
};
