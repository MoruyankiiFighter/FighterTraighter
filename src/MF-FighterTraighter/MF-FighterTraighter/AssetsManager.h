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
	//constructor
	AssetsManager(App* app);
	AssetsManager(AssetsManager&) = delete;
	AssetsManager& operator= (AssetsManager&) = delete;
	
	//destructor
	virtual ~AssetsManager();

	//methods for the textures
	Texture* getTexture(size_t id);
	void loadTextures(); // Textures are hardcoded for now

	//methods for the fonts
	void loadFonts(); // Fonts are hardcoded for now
	Font* getFont(size_t id);
	
	//methods foor music

	//methods for sound effects

	void UnloadAssets();
private:
	std::vector<Texture*> textures_;
	std::vector<Font*> fonts_;
	App* app_;
};

