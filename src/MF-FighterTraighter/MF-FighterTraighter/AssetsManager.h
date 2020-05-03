#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include "Texture.h"
#include "Font.h"
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
		HealthbarSaco,
		HealthbarBack,
		RoundCounter,
		CharacterSelection,
		BackgroundFight,
		Banner,
		Panel,

		//resources of aisha
		Aisha_icon,
		AishaArtwork,
		AishaSheet,
		
		//resources of mkwhoop
		Ganonbot_icon,
		GanonArtwork,
		GanonSheet,
		
		//resources of mockingbird
		Mock_icon,
		MockArtwork,
		MockSheet,

		//resources of flor
		Flor_icon,
		FlorArtwork,
		FlorSheet,

	};

	enum FontNames {
		Roboto_Black,
		Arial,
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

	//audio methods

	//return the audio with the position id
	//Audio* getAudio(size_t id);
	void loadMusic();

	void playMusic(const string& name, int channel);
	void resumeAll();
	void resumeMusic();
	void pauseMusic();
	void stopMusic();

	int getGeneralVolume() const;
	int getMusicVolume() const;
	int getChannelVolume(int channel) const;
	void setGeneralVolume(float volume_ratio);
	void setChannelvolume(int channel, float volume_ratio);
	void setMusicVolume(float volume_ratio);
	void setSFXVolume(const string& name, float volume_ratio);


private:
	std::map<TextureNames, Texture*> textures_;
	std::map<FontNames, Font*> fonts_;
	//std::vector<Audio*> music_;
	//std::vector<Audio*> sfx_;

	App* app_;
};

