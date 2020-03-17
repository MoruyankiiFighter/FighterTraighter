#include "PunchingBagListener.h"

void PunchingBagListener::BeginContact(b2Contact* contact)
{
	//check if fixture A was was the punching bag
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	PunchingBagCollision* pbCol = dynamic_cast<PunchingBagCollision*>(static_cast<Entity*>(bodyUserData)->getComponent<PunchingBagCollision>(ecs::PunchingBagCollision));
	if (pbCol != nullptr) {
		pbCol->OnCollision();
	}

	//check if fixture B was was the punching bag
	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	pbCol = dynamic_cast<PunchingBagCollision*>(static_cast<Entity*>(bodyUserData)->getComponent<PunchingBagCollision>(ecs::PunchingBagCollision));
	if (pbCol != nullptr) {
		pbCol->OnCollision();
	}
}
