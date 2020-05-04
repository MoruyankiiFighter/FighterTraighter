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
	
    virtual int setSFXVolume( int volume);
	virtual int setMusicVolume(int volume);

	void stopMusic();
	virtual void pauseMusic();
	virtual void resumeMusic();

	void resumeAll();

	//int getGeneralVolume() const;
	int getMusicVolume() const;
	int getSFXVolume() const;

	//for settings
	//void setGeneralVolume(float MaxVolume, float volume_ratio);
	//void setChannelvolume(int channel, float volume_ratio);

private:
	bool initialized_ = false;
	int channels_ = -1;
};

