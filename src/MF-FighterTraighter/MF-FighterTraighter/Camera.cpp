#include "Camera.h"

inline void Camera::CalculaPunto()
{
	if (m_Target2!=nullptr)
	{
		m_ViewBox.x = (m_Target1->getPosition().getX() + m_Target2->getPosition().getX()) / 2 - app_->getWindowManager()->getCurResolution().w / 2;
		m_ViewBox.y = (m_Target1->getPosition().getY() + m_Target2->getPosition().getY()) / 2 - app_->getWindowManager()->getCurResolution().h / 2;
	}
	else
	{
		m_ViewBox.x = m_Target1->getPosition().getX() - app_->getWindowManager()->getCurResolution().h / 2;
		m_ViewBox.y = app_->getWindowManager()->getCurResolution().h / 2;

	}
}
void  Camera::ControlaLimites()
{
	if (m_ViewBox.x < 0)
	{
		m_ViewBox.x = 0;
	}if (m_ViewBox.y > 0)
	{
		m_ViewBox.y = 0;
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
	ControlaLimites();
	cam->setPosition(Vector2D(m_ViewBox.x, m_ViewBox.y));
}

