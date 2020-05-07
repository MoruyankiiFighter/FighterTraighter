#include "Camera.h"

inline void Camera::update()
{

	m_ViewBox.x = m_Target->getX(); /*-Screen_width /2*/
	m_ViewBox.y = m_Target->getY(); /*-Screen_Height /2*/
	if (m_ViewBox.x <0)
	{
		m_ViewBox.x = 0;
	}if (m_ViewBox.y >0)
	{
		m_ViewBox.y = 0;
	}
	if (m_ViewBox.x >/* 2* Screen_width /*/ -m_ViewBox.w	)
	{
		m_ViewBox.x = /* 2* Screen_width /*/ -m_ViewBox.w;
	}
	if (m_ViewBox.y >/* 2* Screen_height /*/ -m_ViewBox.h)
	{
		m_ViewBox.y = /* 2* Screen_height /*/ -m_ViewBox.h;
	}

	m_Position = Vector2D(m_ViewBox.x, m_ViewBox.y);
}
