#pragma once
#include <vector>
#include <SDL_timer.h>
const float FRAME_PER_SECOND = FPS / 1000.0F;
const float FRAME_DELAY = 1000.0F / FPS;
const float MAX_DELTA_TIME = 1.5f;
class Timer
{

public :
	Timer();
	void Tick();
	inline const float DeltaTime() { return m_DeltaTime; }
	inline static Timer* Instance() { return s_instance=(s_instance!=nullptr)?s_instance:new Timer(); }
	inline void Clean() {
		for (SDL_TimerID id : m_TimerRegistry)SDL_RemoveTimer(id);
	}
	inline SDL_TimerID StartTimer(Uint32 interval, SDL_TimerCallback callback, void* data)
	{
		SDL_TimerID id = SDL_AddTimer(interval, callback, data);
		m_TimerRegistry.push_back(id);
	}
	inline void RemoveTimer(SDL_TimerID id) { SDL_RemoveTimer(id); }


private :
	float m_DeltaTime;
	float m_LastTime;
	std::vector<SDL_TimerID> m_TimerRegistry;
	static Timer* s_instance;
};

