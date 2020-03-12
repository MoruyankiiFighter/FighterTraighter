#include "hitbox.h"

void hitbox::update()
{
	time_--;
	if (time_ <= 0) {
		body_->DestroyFixture(this);		
	}
}

hitbox::~hitbox()
{
}

void hitbox::init()
{
}


