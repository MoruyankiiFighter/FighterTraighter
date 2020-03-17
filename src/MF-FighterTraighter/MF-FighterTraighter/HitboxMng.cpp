#include "HitboxMng.h"

HitboxMng::HitboxMng(): Component(ecs::HitboxMng)
{

}

void HitboxMng::update()
{
	for (auto it = hitboxList_.begin(); it != hitboxList_.end();++it) {
		if ((*it)->update()) {
			(*it)->GetBody()->DestroyFixture((*it));
			//auto itaux = ++it;

			hitboxList_.erase(it);
			//it = itaux;
		}
	}

	//for (auto h : hitboxListToRemove_) {
	//	//h->update();
	//	h->GetBody()->DestroyFixture(h);

	//}
	//hitboxListToRemove_.clear();
}

void HitboxMng::addHitbox(Vector2D pos, int width, int height, int time, int damage, Vector2D dir)
{
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2, { float32(pos.getX() + width / 2),float32(pos.getY() + height / 2) }, 0);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001;			//densidad casi 0, para que no cambie segun el ancho y el alto por ahora

	body_->CreateFixture(&fixturedef);
	//fList.push_back(body_->CreateFixture(&fixturedef));
	//time_ = time;
}
