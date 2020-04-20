#include "SDLDebugDraw.h"

/*void SDLDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	float scaleFactor = 1;

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
	for (int32 i = 0; i < vertexCount; i++) {
		float spX = vertices[i].x,
			spY = vertices[i].y,
			epX = vertices[(i + 1) % vertexCount].x,
			epY = vertices[(i + 1) % vertexCount].y;
		SDL_RenderDrawLine(renderer, (vertices[i].x * scaleFactor), vertices[i].y * scaleFactor, vertices[(i + 1) % vertexCount].x * scaleFactor , vertices[(i + 1) % vertexCount].y* scaleFactor);
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}*/

void SDLDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color){
	float scaleFactor = 100;
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
	for (int32 i = 0; i < vertexCount; i++) {
		float spX = vertices[i].x * scaleFactor,
			spY = vertices[i].y * scaleFactor,
			epX = vertices[(i + 1) % vertexCount].x * scaleFactor,
			epY = vertices[(i + 1) % vertexCount].y * scaleFactor;
		//SDL_RenderDrawLine(renderer, 40, 600, 1960, 600);
		SDL_RenderDrawLine(renderer, (vertices[i].x * scaleFactor), vertices[i].y * scaleFactor, vertices[(i + 1) % vertexCount].x * scaleFactor, vertices[(i + 1) % vertexCount].y * scaleFactor);
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

