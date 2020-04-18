#pragma once
#include "Component.h"
#include "InpuState.h"
class GamepadInput :public  Component
{
public:
	GamepadInput() :Component(ecs::GamepadInput) {};

	~GamepadInput() {};
	virtual void init();

	virtual void handleInput()override
	{

		ZonaMuerta(SDL_CONTROLLER_AXIS_LEFTX, SDL_CONTROLLER_AXIS_LEFTY);

		int i = 0;
		if (!mov)
		{
			inSt->setInput(0, false);
			inSt->setInput(1, false);
			inSt->setInput(2, false);
			inSt->setInput(3, false);
			i = 4;
		}
		else
		{
			int k = 0;
			for (; i < movement.size(); i++)	//left, right, up, down
			{


				if (app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, movement[i]) < -deadZone)
				{

					inSt->setInput(k, true);
					inSt->setInput(k + 1, false);

				}
				else if (app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, movement[i]) > deadZone)
				{
					inSt->setInput(k + 1, true);
					inSt->setInput(k, false);

				}
				else {
					inSt->setInput(k, false);
					inSt->setInput(k + 1, false);
				}
				k += 2;
			}
			i = k;
		}

		int j = 0;
		for (; j < attacks.size(); ++j)	//button pressed
		{
			if (app_->getInputManager()->isControllerButtonPressed(InputManager::PLAYER1, attacks[j]))
			{

				inSt->setInput(i, true);
			}
			else
			{
				inSt->setInput(i, false);
			}
			++i;
		}

		if (app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, blocking[0]) > deadZone) inSt->setInput(i, true);
		else (inSt->setInput(i, false));
		++i;

		if (app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, blocking[1]) > deadZone && gbReleased) { 
			inSt->setInput(i, true); 
			gbReleased = false;
		}
		else if (app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, blocking[1]) <= deadZone) {	//So guardbreak can't be spammed
			inSt->setInput(i, false);																			//Spaghetti? Maybe
			gbReleased = true;																					//Work? It sure do be fuckin workin
		}
		else inSt->setInput(i, false);
		++i;

		/*	for (int j =0; j < button.size(); j++)			//button held
		{
			if (app_->getInputManager()->isControllerButtonHeld(InputManager::PLAYER1, button[j]) )
			{

				inSt->setInput(true,i + j);


			}
			else
			{
				inSt->setInput(false,i + j);

			}
		}*/
	}

	void changeButton(int index, SDL_GameControllerButton newbutton) {
		attacks[index] = newbutton;
	}

private:
	InputState* inSt = nullptr;
	int inputsize = 10;
	const float deadZone = 0.5;
	bool mov = false;
	bool gbReleased = true;

	std::vector<SDL_GameControllerButton>attacks = {
	SDL_CONTROLLER_BUTTON_A,
	SDL_CONTROLLER_BUTTON_B,
	SDL_CONTROLLER_BUTTON_X,
	SDL_CONTROLLER_BUTTON_Y,
	SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
	SDL_CONTROLLER_BUTTON_RIGHTSHOULDER
	};

	std::vector<SDL_GameControllerAxis>blocking = {
	SDL_CONTROLLER_AXIS_TRIGGERLEFT,
	SDL_CONTROLLER_AXIS_TRIGGERRIGHT
	};

	std::vector<SDL_GameControllerAxis>movement = {
	SDL_CONTROLLER_AXIS_LEFTX,
	SDL_CONTROLLER_AXIS_LEFTY,
	};


	void ZonaMuerta(SDL_GameControllerAxis ejeX, SDL_GameControllerAxis ejeY)
	{
		double stickX = app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, ejeX); // devuelve un valor entre -1.0 y 1.0
		double stickY = app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, ejeY);; // devuelve un valor entre -1.0 y 1.0
		//hipo^2=Cat^2+Cat^2 Pitagoras
		const double deadzoneRadius = deadZone;
		const double deadzoneAlCuadrado = deadzoneRadius * deadzoneRadius;
		double cuadradocatop = stickY * stickY;
		double cuadradocatadj = stickX * stickX;
		//Si la deadzone al cuadrado es menor que la suma de los cuadrados al cuadrado se puede leer el input 
		if ((cuadradocatop + cuadradocatadj) > deadzoneAlCuadrado)
		{
			mov = true;
		}
		else
		{
			mov = false;
		}
	}



};