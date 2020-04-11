#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "Texture.h"
#include "Font.h"
#include <SDL_mixer.h>
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

	//music methods
	Mix_Music* getMusic(size_t id);
	void loadMusic();
	
	//sfx methods
	Mix_Chunk* getSFX(size_t id);
	void loadSFX();


private:
	std::vector<Texture*> textures_;	//images/Textures
	std::vector<Font*> fonts_;			//fonts
	std::vector <Mix_Chunk*> sfx_;		//sound effects
	std::vector <Mix_Music*> music_;	//music
	App* app_;
};

