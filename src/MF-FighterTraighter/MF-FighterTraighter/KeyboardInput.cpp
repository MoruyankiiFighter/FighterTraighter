#include "KeyboardInput.h"
#include "Entity.h"

void KeyboardInput::init()
{
	inSt = entity_->getComponent<InputState>(ecs::InputState);
	keys_ = app_->getInputManager()->ControlKeyboard();
}
