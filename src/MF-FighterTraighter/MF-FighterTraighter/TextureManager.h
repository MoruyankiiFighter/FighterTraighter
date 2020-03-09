#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "Texture.h"
class App;

class TextureManager
{
public:
	TextureManager(App* app);
	TextureManager(TextureManager&) = delete;
	TextureManager& operator= (TextureManager&) = delete;

	Texture* getTexture(size_t id);
	void loadTextures(); // Textures are hardcoded for now

	virtual ~TextureManager();
private:
	std::vector<Texture*> textures_;
	App* app_;
};

