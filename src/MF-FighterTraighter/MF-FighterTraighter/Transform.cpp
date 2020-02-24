#include "Transform.h"

Transform::Transform(Vector2D position, Vector2D speed, double width, double height, double rotation):
	Component(ecs::Transform),position_(position),speed_(speed), width_(width), height_(height), rotation_(rotation)
{
	std::cout << "Transform added" << std::endl;
}

Transform::Transform():
	Component(ecs::Transform),position_(),speed_(),width_(),height_(),rotation_()
{
	std::cout << "Transform added" << std::endl;
}

Transform::~Transform()	{}
