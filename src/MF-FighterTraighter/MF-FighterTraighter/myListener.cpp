#include "myListener.h"
#include "Fight.h"

myListener::myListener(Fight* fight) {
	fight_ = fight; 
}


//no destruir los cuerpos aqui, puede dar error, mejor tener un flag

void myListener::BeginContact(b2Contact* contact) {
	b2Body* one = contact->GetFixtureA()->GetBody();
	//one->GetFixtureList().
	//fight_->test(one);
	b2Body* two = contact->GetFixtureB()->GetBody();
	//fight_->test(two);
	if (one->GetFixtureList()->GetDensity() == 1) {
		fight_->test(two);
	}
	else fight_->test(one);
	fight_->testCreateBody();
	//world_->DestroyBody(one);

	std::cout << "Begin Contact " << std::endl;
}
void myListener::EndContact(b2Contact* contact) {
	std::cout << "End Contact " << std::endl;

}
void myListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
	std::cout << "post solve " << std::endl;

}
void myListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
	std::cout << "pre solve " << std::endl;

}