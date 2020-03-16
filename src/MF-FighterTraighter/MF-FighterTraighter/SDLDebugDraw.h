#pragma once
#include "Box2D/Box2D.h"
#include "SDL.h"
#include <iostream>

//clase para debuggear las hitbox con SDL, tiene que heredar de b2Draw
//para ver las fisicas tal y como las hace b2D
class SDLDebugDraw : public b2Draw
{
public:
	SDLDebugDraw(SDL_Renderer* r) :  b2Draw(), renderer(r) {}
	//debug of hitbox of the library box2D, use drawPoligon if it's gonna be polygons
	
	/// Draw the hitboxes
	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	//draw the form
	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)override {}
	//draw a circumference
	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)override {}
	//draw a circle
	void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {}
	//draw a segment
	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)override {}
	//draw transform
	void DrawTransform(const b2Transform& xf)override {}

private:
	SDL_Renderer* renderer=nullptr;
};

