#pragma once
#include "Vector2D.h"
#include "Component.h"
#include "PhysicsTransform.h"

class Camera:public Component
{
public:

	Camera(Transform*Target ) : Component(ecs::Camera),m_Target1(Target)
	{};
	Camera(Transform*Target, Transform* Target2) : Component(ecs::Camera),m_Target1(Target),m_Target2(Target2)
	{};
	void init()override
	{
		cam = entity_->getComponent<Transform>(ecs::Transform);
		//cam->setPosition(cam->getPosition().getX(), cam->getPosition().getY() +100);
		cam->setWidthHeight(cam->getWidth()+ m_Target1->getPosition().getX()+2*m_Target1->getWidth(), cam->getHeight()+ m_Target1->getPosition().getY());
		m_ViewBox.w = app_->getWindowManager()->getCurResolution().w;
		m_ViewBox.h= app_->getWindowManager()->getCurResolution().h +500;
		
	}
	virtual void update()override;
private:
	void ControlaLimites();
	inline void CalculaPunto();
		SDL_Rect m_ViewBox;
		Transform* cam;
		Transform* m_Target1;
		Transform* m_Target2;
};

