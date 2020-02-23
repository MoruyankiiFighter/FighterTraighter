#pragma once

#include "Vector2D.h"
#include "Component.h"
#include "ecs.h"
class Transform: public Component
{
public:
	//constructor and destructor
	Transform(Vector2D position, Vector2D speed, double width, double height, double rotation);
	Transform();
	virtual ~Transform();

	// get and set for position
	const Vector2D& getPosition() const { return position_; }
	void setPosition(const Vector2D& v) { position_ = v; }
	void setPosition(double x, double y) { position_ = { x,y }; }

	//get and set for speed
	const Vector2D& getSpeed() const { return speed_; }
	void setSpeed(const Vector2D& v) { speed_ = v; }
	void setSpeed(double x, double y) { speed_ = { x,y }; }

	// get and set for width and height
	double getWidth() const { return width_; }
	double getHeight() const { return height_; }

	void setWidth(double width) { width_ = width; }
	void setHeight(double height) { height_ = height; }

	void setWidthHeight(double width, double height) { 
		setWidth(width);
		setHeight(height); 
	}

	//get and set for rotation
	double getRotation() { return rotation_; }
	void setRotation(double rotation) { rotation_ = rotation; }

private:
	Vector2D position_;
	Vector2D speed_;
	double width_=0, height_=0, rotation_=0;
};

