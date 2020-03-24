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
	//constructors
	AssetsManager(App* app);
	AssetsManager(AssetsManager&) = delete;
	AssetsManager& operator= (AssetsManager&) = delete;

	virtual ~AssetsManager();
	void UnloadAssets();


	//texture methods
	//return the texture with the position id from the textures_ vector 
	Texture* getTexture(size_t id);
	void loadTextures(); // Textures are hardcoded for now

	//font methods
	//return the font with the position id from the fonts_ vector
	Font* getFont(size_t id);
	void loadFonts(); // Fonts are hardcoded for now

	//audio methods

	//sound methods

private:
	std::vector<Texture*> textures_;
	std::vector<Font*> fonts_;
	App* app_;
};

