#pragma once

#include <SDL.h>
#include "App.h"

class Entity;
class Component
{

public:
	Component();
	Component(int id);
	~Component();

	void setEntity(Entity* entity) { entity_ = entity; }
	void setGame(App* app) { app_ = app; }
	void setID(int id) { id_ = id; }

	int getID() { return id_; }

	virtual void init() {}
	virtual void update() {}
	virtual void render() {}


protected:
	Entity* entity_;
	App* app_;
	int id_;
};

