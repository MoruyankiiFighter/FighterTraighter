#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include "Texture.h"
#include "Font.h"
#include <SDL_mixer.h>
class App;

class AssetsManager
{
public:
	enum TextureNames {
		Player,
		Button,
		Logo,
		Controller,
		Slidebar,
		SliderRegulator,
		PlayerActing,
		Background,
		Healthbar,
		HealthbarBack,
		RoundCounter
	};

	enum FontNames {
		Roboto_Black
	};

	enum MusicNames {
		MENU_PRINCIPAL,
		MENU_OPCIONES,
		FIGHT_1,
		FIGHT_2,
		FIGHT_3,
		FIGHT_4
	};

	enum SFXNames {
		/// Taunts
		AISHA_1,
		AISHA_2,
		AISHA_3,
		AISHA_4,
		AISHA_5,
		AISHA_6,
		FLOR_1,
		FLOR_2,
		FLOR_3,
		MKWOP_1,
		MKWOP_2,
		MKWOP_3,
		MKWOP_4,
		MKWOP_5,
		MKBIRD_1,
		MKBIRD_2,
		MKBIRD_3,
		/// SFX

	};

	//constructors
	AssetsManager(App* app);
	AssetsManager(AssetsManager&) = delete;
	AssetsManager& operator= (AssetsManager&) = delete;

	virtual ~AssetsManager();
	void UnloadAssets();


	//texture methods
	//return the texture with the position id from the textures_ map 
	Texture* getTexture(AssetsManager::TextureNames id);
	void loadTextures(); // Textures are hardcoded for now

	//font methods
	//return the font with the position id from the fonts_ map
	Font* getFont(AssetsManager::FontNames id);
	void loadFonts(); // Fonts are hardcoded for now

	//music methods
	Mix_Music* getMusic(size_t id);
	void loadMusic();
	
	//sfx methods
	Mix_Chunk* getSFX(size_t id);
	void loadSFX();


private:
	std::map <TextureNames,Texture*> textures_;	//images/Textures
	std::map <FontNames,Font*> fonts_;			//fonts
	std::map <MusicNames,Mix_Music*> music_;	//music
	std::map <SFXNames,Mix_Chunk*> sfx_;		//sound effects
	App* app_;
};

