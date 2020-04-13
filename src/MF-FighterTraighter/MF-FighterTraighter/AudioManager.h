#pragma once
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <SDL_mixer.h>
class AudioManager
{
public:
	AudioManager();
	AudioManager(int channels);

	virtual ~AudioManager();

	//SFX
	Mix_Chunk* loadSFX(const std::string& fileName);
	virtual void playSFX(Mix_Chunk* sound, int loops, int channel = -1);

	// music
	Mix_Music* loadMusic(const std::string& fileName);
	void playMusic(Mix_Music* music, bool loops);
	virtual int setMusicVolume(int volume);
	void stopMusic();
	virtual void pauseMusic();
	virtual void resumeMusic();
	
	void resumeAll();


	//for settings
	int getGeneralVolume() const;
	int getMusicVolume() const;
	int getChannelVolume(int channel) const;
	void setGeneralVolume(float MaxVolume, float volume_ratio);
	
	void setChannelvolume(int channel, float volume_ratio);
	void setMusicVolume(float volume_ratio);
	void setSFXVolume(const std::string& name, float volume_ratio);

private:
	bool initialized_ = false;
	int channels_=-1;
};

