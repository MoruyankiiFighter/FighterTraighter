#include "SDLDebugDraw.h"

void SDLDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
	for (int32 i = 0; i < vertexCount; i++) {
		SDL_RenderDrawLine(renderer, vertices[i].x, vertices[i].y, vertices[(i + 1) % vertexCount].x, vertices[(i + 1) % vertexCount].y);
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}
