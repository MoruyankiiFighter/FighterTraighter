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
		
		if (!mov)
		{
			inSt->setInput(0, false);
			inSt->setInput(1, false);
			inSt->setInput(2, false);
			inSt->setInput(3, false);
		}
		else
		{
			for (int i = 0; i < axis.size() / 2; i++)
			{


				if (app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, axis[i]) < -deadZone)
				{

					inSt->setInput(2 * i, true);
					inSt->setInput(2 * i + 1, false);

				}
				else if (app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, axis[i]) > deadZone)
				{
					inSt->setInput(2 * i + 1, true);
					inSt->setInput(2 * i, false);

				}

			}
		}
			
			
		int i = 2;
		//triggers
		for (; i < axis.size(); i++)
		{
			if (app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, axis[i]) > deadZone)
			{

				inSt->setInput(i+2, true);


			}
			else
			{
				inSt->setInput(i + 2, false);

			}
		}
		//button pressed
		for (int j =0; j < button.size(); j++)
		{
			if (app_->getInputManager()->isControllerButtonPressed(InputManager::PLAYER1, button[i]) )
			{

				inSt->setInput(i + j, true);


			}
			else
			{
				inSt->setInput(i + j, false);

			}
		}
		//button held 
		/*	for (int j =0; j < button.size(); j++)
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
		button[index] = newbutton;
	}

private:
	InputState* inSt = nullptr;
	int inputsize = 10;
	const float deadZone = 0.2;
		bool mov=false;
	std::vector<SDL_GameControllerButton>button = {
	SDL_CONTROLLER_BUTTON_A,
	SDL_CONTROLLER_BUTTON_B,
	SDL_CONTROLLER_BUTTON_X,
	SDL_CONTROLLER_BUTTON_Y,
	SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
	SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
	};
	std::vector<SDL_GameControllerAxis>axis = {
    SDL_CONTROLLER_AXIS_LEFTX,
    SDL_CONTROLLER_AXIS_LEFTY,
	SDL_CONTROLLER_AXIS_TRIGGERLEFT,
	SDL_CONTROLLER_AXIS_TRIGGERRIGHT
	};




 void ZonaMuerta(SDL_GameControllerAxis ejeX, SDL_GameControllerAxis ejeY )
{
	double stickX = app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, ejeX); // devuelve un valor entre -1.0 y 1.0
	double stickY = app_->getInputManager()->getControllerAxis(InputManager::PLAYER1, ejeY);; // devuelve un valor entre -1.0 y 1.0
	//hipo^2=Cat^2+Cat^2 Pitagoras
	const double deadzoneRadius = deadZone;
	const double deadzoneAlCuadrado = deadzoneRadius * deadzoneRadius;
	double cuadradocatop = stickY *stickY;
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