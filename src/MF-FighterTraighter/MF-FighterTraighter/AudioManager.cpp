#include "AudioManager.h"
#include <SDL_mixer.h>
#include <SDL.h>

AudioManager::AudioManager(){

	if (SDL_Init(SDL_INIT_AUDIO) == 0)
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
			std::cout << "Audio Manager not loaded" << Mix_GetError() << std::endl;
}


AudioManager::~AudioManager()
{


	Mix_CloseAudio();
}

Mix_Chunk* AudioManager::loadSound(const std::string& fileName)
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

Mix_Music* AudioManager::loadMusic(const std::string & fileName)
{
	Mix_Music* m = Mix_LoadMUS(fileName.c_str());
	return m;
}

void AudioManager::playMusic(Mix_Music* music, bool loops)
{
	if (music != nullptr) {
		Mix_PlayMusic(music,loops ?- 1:0); //si loop= true se loopea(-1), en caso contrario 1 vez
	}
	else {
		//lanzar excepciones
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

void AudioManager::resumeAll()
{
}

void AudioManager::stopMusic()
{
}

int AudioManager::getGeneralVolume() const
{
	return 0;
}

int AudioManager::getMusicVolume() const
{
	return 0;
}

int AudioManager::getChannelVolume(int channel) const
{
	return 0;
}

void AudioManager::setGeneralVolume(float volume_ratio)
{
}

void AudioManager::setChannelvolume(int channel, float volume_ratio)
{
}

void AudioManager::setMusicVolume(float volume_ratio)
{
}

void AudioManager::setSFXVolume(const std::string& name, float volume_ratio)
{
}
