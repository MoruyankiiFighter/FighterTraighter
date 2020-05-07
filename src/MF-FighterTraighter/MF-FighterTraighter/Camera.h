#pragma once
#include "Vector2D.h"
#include "SDL.h"
#include "App.h"
#include "Entity.h"

class Camera
{
public:
	/*inline static Camera* GetInstance() {
		return s_Instance - (s_Instance != nullptr) ? s_Instance : new Camera();
	}*/
	inline SDL_Rect GetViewBox() { return m_ViewBox; }
	inline Vector2D GetPosition() { return m_Position; }
	inline  void SetTarget(Vector2D* target) { m_Target = target; }
	inline void update();
private:
	Camera() {/* m_ViewBox = {0,0,app->getWindowManager()->getWindow,pones las dimensiones de la ventana*/ };

		static Camera* s_Instance;
		SDL_Rect m_ViewBox;
		Vector2D m_Position;
		Vector2D* m_Target;
};

