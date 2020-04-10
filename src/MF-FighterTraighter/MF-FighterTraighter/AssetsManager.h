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

	//audio methods

	//return the audio with the position id
	//Audio* getAudio(size_t id);
	void loadMusic();
	void loadSFX();
	
	void playMusic(int index);
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
	std::vector<Texture*> textures_;	//images/Textures
	std::vector<Font*> fonts_;			//fonts
	std::vector <Mix_Chunk*> sfx_;		//sound effects
	std::vector <Mix_Music*> music_;	//music
	App* app_;
};

