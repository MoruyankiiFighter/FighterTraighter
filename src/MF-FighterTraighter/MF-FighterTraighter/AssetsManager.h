#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "Texture.h"
#include "Font.h"
#include "Audio.h"
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
	Audio* getAudio(size_t id);
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
	std::vector<Texture*> textures_;
	std::vector<Font*> fonts_;
	std::vector<Audio*> music_;
	std::vector<Audio*> sfx_;

	App* app_;
};

