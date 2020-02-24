#pragma once

#include <SDL.h>
#include "App.h"
#include "ecs.h"
class Entity;
class Component
{

public:
	Component(ecs::CmpId id);
	~Component();

	void setEntity(Entity* entity) { entity_ = entity; }

	ecs::CmpId getID() { return id_; }

	virtual void init() {} // get required pointers at runtime
	virtual void handleInput() {} // gets called before update, use for input
	virtual void update() {} // main update of the component
	virtual void render() {} // render textures


protected:
	Entity* entity_;
	ecs::CmpId id_;
};

