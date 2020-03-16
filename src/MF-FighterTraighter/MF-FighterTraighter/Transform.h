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
	virtual const Vector2D& getPosition() const { return position_; }
	virtual void setPosition(const Vector2D& v) { position_ = v; }
	virtual void setPosition(double x, double y) { position_ = { x,y }; }

	//get and set for speed
	virtual const Vector2D& getSpeed() const { return speed_; }
	virtual void setSpeed(const Vector2D& v) { speed_ = v; }
	virtual void setSpeed(double x, double y) { speed_ = { x,y }; }

	// get and set for width and height
	virtual double getWidth() const { return width_; }
	virtual double getHeight() const { return height_; }
	
	// get the scale from x and y
	virtual double getScaleX() const { return scale_x; }
	virtual double getScaleY() const { return scale_y; }
	
	//set the scale 
	virtual void setScaleX(double i) { scale_x = i; }
	virtual void setScaleY(double i) { scale_y = i; }
	
	//set width
	virtual void setWidth(double width) { width_ = width; }
	//set height
	virtual void setHeight(double height) { height_ = height; }

	//set width and height
	virtual void setWidthHeight(double width, double height) {
		setWidth(width);
		setHeight(height); 
	}

	//get and set for rotation
	virtual double getRotation() { return rotation_; }
	virtual void setRotation(double rotation) { rotation_ = rotation; }

protected:
	Vector2D position_;
	Vector2D speed_;
	
	double width_=0, height_=0, rotation_=0;
	double scale_x = 1, scale_y = 1;

};

