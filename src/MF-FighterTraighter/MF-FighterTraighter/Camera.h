#pragma once
#include "Vector2D.h"
#include "Component.h"
#include "PhysicsTransform.h"
#include "UITimer.h"

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
		

		//1920+860*2+500
		cam->setWidthHeight(cam->getWidth() + m_Target1->getPosition().getX()*2 + m_Target1->getWidth()/2, cam->getHeight() + m_Target1->getPosition().getY());
		//m_ViewBox.w = app_->getWindowManager()->getCurResolution().w;
		//m_ViewBox.h= app_->getWindowManager()->getCurResolution().h +500;
		
	}
	virtual void update()override;
private:
	void Shake();
	inline void CalculaPunto();
		SDL_Rect m_ViewBox;
		SDL_Rect m_shake;
		Transform* cam;
		Transform* m_Target1;
		Transform* m_Target2;
};

