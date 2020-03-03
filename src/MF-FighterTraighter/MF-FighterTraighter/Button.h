#include "Component.h"
#include "RenderImage.h"
using callBackOnClick = void(string text);

class Button : public Component {

public:
	//constructor
	Button() : Component(ecs::Button) {};
	//destructor
	virtual ~Button() {};

	void init() override;
	//handle the input of the mouse by the moment
	void handleInput() override;

private:
	RenderImage* render_;
};
