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

	virtual bool init() = 0;


	Mix_Chunk* loadSound(const std::string& fileName);
	virtual int playChannel(int tag, int loops, int channel = -1);
	virtual void pauseChannel(int channel = -1);
	virtual void resumeChannel(int channel = -1);
	virtual void haltChannel(int channel = -1);
	virtual int setChannelVolume(int volume, int channel = -1);
	virtual int channels();


	// music
	Mix_Music* loadMusic(const std::string& fileName);
	void playMusic(Mix_Music* music, bool loops);
	virtual int setMusicVolume(int volume);
	virtual void haltMusic();
	virtual void pauseMusic();
	virtual void resumeMusic();
	void resumeAll();
	void stopMusic();


	//for settings
	int getGeneralVolume() const;
	int getMusicVolume() const;
	int getChannelVolume(int channel) const;
	void setGeneralVolume(float volume_ratio);
	void setChannelvolume(int channel, float volume_ratio);
	void setMusicVolume(float volume_ratio);
	void setSFXVolume(const std::string& name, float volume_ratio);

private:
	bool initialized_ = false;
	int channels_=-1;
};

