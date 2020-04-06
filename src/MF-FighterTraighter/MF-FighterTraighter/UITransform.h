#pragma once
#include "Transform.h"
class UITransform :
	public Transform
{
public:
	enum AnchorPreset
	{
		TopLeft,
		Top,
		TopRight,
		CenterLeft,
		Center,
		CenterRight,
		BottomLeft,
		Bottom,
		bottomRight
	};

	void init() override;
	void update() override;

	void setAnchor(Vector2D anchor) { anchor_ = anchor; }
	void setAnchorPreset(AnchorPreset preset);

	const Vector2D& getPosition() const override { return position_ + anchor_; }
	void setPosition(const Vector2D& v) override { position_ = v; }
	void setPosition(double x, double y) override { position_ = { x,y }; }

	virtual void WindowResized(double newW, double newH);

	UITransform(Vector2D pos, Vector2D anchor, Vector2D size) : Transform(pos, Vector2D(), size.getX(), size.getY(), 0), anchor_(anchor) {};
protected:
	WindowManager* windowMngr_ = nullptr;
	Vector2D anchor_; // from where in the window the position is calculated
};

