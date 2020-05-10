#include "Camera.h"

inline void Camera::CalculaPunto()
{
	if (m_Target2!=nullptr)
	{
		/*m_ViewBox.x = (m_Target1->getPosition().getX() + m_Target2->getPosition().getX()) / 2 + m_Target1->getPosition().getX() - m_ViewBox.w / 2;
		m_ViewBox.y = (m_Target1->getPosition().getY() + m_Target2->getPosition().getY()) / 2 + m_Target1->getPosition().getY() - m_ViewBox.h / 2;*/

		m_ViewBox.y =- (m_Target1->getPosition().getY() + m_Target2->getPosition().getY())/2;
		m_ViewBox.x = -(m_Target1->getPosition().getX() + m_Target2->getPosition().getX())/2;

		//ControlaLimites();

	}
	else if(m_Target1!= nullptr)
	{
		m_ViewBox.x = -m_Target1->getPosition().getX();
		std::cout << m_ViewBox.x << std::endl;
		//m_ViewBox.y = app_->getWindowManager()->getCurResolution().h/2- m_Target1->getPosition().getY();
	     m_ViewBox.y = - m_Target1->getPosition().getY()/2;
	//ControlaLimites();

	}
}
void  Camera::ControlaLimites()
{
	if (m_ViewBox.x < 0)
	{
		m_ViewBox.x = 0;
	}
	if (m_ViewBox.x > app_->getWindowManager()->getCurResolution().w * 2 - m_ViewBox.w)
	{
		m_ViewBox.x = app_->getWindowManager()->getCurResolution().w * 2 - m_ViewBox.w;
	}
	if (m_ViewBox.y > app_->getWindowManager()->getCurResolution().h * 2 - m_ViewBox.h)
	{
		m_ViewBox.y = app_->getWindowManager()->getCurResolution().h * 2 - m_ViewBox.h;
	}

}

void Camera::update()
{
	CalculaPunto();
	cam->setPosition(Vector2D(m_ViewBox.x, m_ViewBox.y));
}

