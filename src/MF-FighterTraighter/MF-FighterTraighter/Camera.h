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

