#include "GamepadInput.h"
#include "Entity.h"

void GamepadInput::init()
{
	inSt = entity_->getComponent<InputState>(ecs::InputState);
}
