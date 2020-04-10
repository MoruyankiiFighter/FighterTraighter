#include "AudioManager.h"

AudioManager::AudioManager(): AudioManager(8){	}

AudioManager::AudioManager(int channels)
{
}

AudioManager::~AudioManager()
{
}

bool AudioManager::loadSound(int tag, const std::string& fileName)
{
	return false;
}

int AudioManager::playChannel(int tag, int loops, int channel)
{
	return 0;
}

void AudioManager::pauseChannel(int channel)
{
}

void AudioManager::resumeChannel(int channel)
{
}

void AudioManager::haltChannel(int channel)
{
}

int AudioManager::setChannelVolume(int volume, int channel)
{
	return 0;
}

int AudioManager::channels()
{
	return 0;
}

bool AudioManager::loadMusic(int tag, const std::string& fileName)
{
	return false;
}

void AudioManager::playMusic(int tag, int loops)
{
}

int AudioManager::setMusicVolume(int volume)
{
	return 0;
}

void AudioManager::haltMusic()
{
}

void AudioManager::pauseMusic()
{
}

void AudioManager::resumeMusic()
{
}
