#pragma once
#include <string>
#include <SDL.h>
class Audio
{
	Audio();
	Audio(const Audio&) = delete;
	Audio operator= (const Audio&) = delete;
	Audio(std::string route) { }

	virtual ~Audio();

	void setAudio(std::string route);
	void LoadAudio(std::string route); 
	//get audio(investigar)

	//deletes the audio
	void clearAudio();

protected:

};

