#pragma once

#include <SDL.h>
#include "App.h"
#include "ecs.h"
class Entity;
class Component
{

public:

	//constructor
	Component(ecs::CmpId id);
	//destructor
	virtual ~Component();

	//set the entity of the component
	inline void setEntity(Entity* entity) { entity_ = entity; }
	//set the app
	inline void setApp(App* app) { app_ = app; }

	//return the ID of the component
	ecs::CmpId getID() { return id_; }

	virtual void init() {} // get required pointers at runtime
	virtual void handleInput() {} // gets called before update, use for input
	virtual void update() {} // main update of the component
	virtual void render() {} // render textures


protected:
	Entity* entity_=nullptr;
	App* app_=nullptr;
	ecs::CmpId id_;
};

