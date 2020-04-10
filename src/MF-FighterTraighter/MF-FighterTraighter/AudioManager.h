#pragma once
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

class AudioManager
{
public:
	AudioManager();
	AudioManager(int channels);

	virtual ~AudioManager();

	virtual bool init() = 0;

    virtual bool loadSound(int tag, const std::string& fileName);
	virtual int playChannel(int tag, int loops, int channel = -1);
	virtual void pauseChannel(int channel = -1);
	virtual void resumeChannel(int channel = -1);
	virtual void haltChannel(int channel = -1);
	virtual int setChannelVolume(int volume, int channel = -1);
	virtual int channels();

	// music
	virtual bool loadMusic(int tag, const std::string& fileName);
	virtual void playMusic(Mix_Music* music, int loops=-1);
	virtual int setMusicVolume(int volume);
	virtual void haltMusic();
	virtual void pauseMusic();
	virtual void resumeMusic();
private:
	bool initialized_ = false;
	int channels_=-1;
};

