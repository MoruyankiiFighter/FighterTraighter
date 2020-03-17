#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "Texture.h"
#include "Font.h"
class App;

class AssetsManager
{
public:
	AssetsManager(App* app);
	AssetsManager(AssetsManager&) = delete;
	AssetsManager& operator= (AssetsManager&) = delete;

	Texture* getTexture(size_t id);
	void loadTextures(); // Textures are hardcoded for now

	void loadFonts(); // Fonts are hardcoded for now
	Font* getFont(size_t id);

	virtual ~AssetsManager();
	void UnloadAssets();
private:
	std::vector<Texture*> textures_;
	std::vector<Font*> fonts_;
	App* app_;
};

