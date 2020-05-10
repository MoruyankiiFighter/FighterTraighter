#include "Camera.h"


/*void Camera::update()
{
	if (!timerStopped_) {
		if (!countdown_) {
			timerNow_ = SDL_GetTicks();
		}
		else {
			timerStart_ = SDL_GetTicks();
			if (timerNow_ - timerStart_ <= 0) {
				timerStart_ = timerNow_;
			}
		}
		
	}
}*/



inline void Camera::CalculaPunto()
{
	if (m_Target2!=nullptr)
	{
		m_ViewBox.y =-(m_Target1->getPosition().getY() + m_Target2->getPosition().getY())/2   +m_shake.y;
		m_ViewBox.x = -(m_Target1->getPosition().getX() + m_Target2->getPosition().getX())/2  + m_shake.x;
	}
	else if(m_Target1!= nullptr)
	{
		m_ViewBox.x = -m_Target1->getPosition().getX();
	     m_ViewBox.y = - m_Target1->getPosition().getY();

	}
}
void Camera::update()
{
	CalculaPunto();
	cam->setPosition(Vector2D(m_ViewBox.x, m_ViewBox.y));
}

