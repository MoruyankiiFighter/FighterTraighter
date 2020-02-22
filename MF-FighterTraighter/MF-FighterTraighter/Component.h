#pragma once

#include <SDL.h>
#include "App.h"
#include "ecs.h"
class Entity;
class Component
{

public:
	Component();
	Component(ecs::CmpId id);
	~Component();

	void setEntity(Entity* entity) { entity_ = entity; }
	void setGame(App* app) { app_ = app; }
	void setID(ecs::CmpId id) { id_ = id; }

	ecs::CmpId getID() { return id_; }

	virtual void init() {}
	virtual void update() {}
	virtual void render() {}


protected:
	Entity* entity_;
	App* app_;
	ecs::CmpId id_;
};

