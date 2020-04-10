#include "AudioManager.h"
#include <SDL_mixer.h>

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

void AudioManager::playMusic(Mix_Music* music, int loops)
{
	if (music != nullptr) {
		Mix_PlayMusic(music, loops);
	}
}

int AudioManager::setMusicVolume(int volume)
{
	return Mix_VolumeMusic(volume);
}

void AudioManager::haltMusic()
{
	Mix_HaltMusic();
}

void AudioManager::pauseMusic()
{
	Mix_PauseMusic();
}

void AudioManager::resumeMusic()
{
	Mix_ResumeMusic();
}
