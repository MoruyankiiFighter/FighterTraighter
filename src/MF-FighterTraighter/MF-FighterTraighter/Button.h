#include "Component.h"
using callBackOnClick = void(string text);

class Button : public Component {

public:
	Button() : Component(ecs::Button) {};
	~Button() {};
	void handleInput() override;
private:
};
