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
	//debug de hitbox de box2D, solo usar drawPoligon si van a ser poligonos, las demas hacen nada
	/// Dibuja la hitbox
	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override{}
	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)override;
	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)override {}
	void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {}
	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)override {}
	void DrawTransform(const b2Transform& xf)override {}
private:
	SDL_Renderer* renderer;
};

