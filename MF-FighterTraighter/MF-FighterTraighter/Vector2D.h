#ifndef VECTOR2D_H

#define Vector2D_H
class Vector2D
{
public:
	Vector2D();
	Vector2D(double x, double y);

	double getX() { return _x; }
	double getY() { return _y; }

	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	double operator*(const Vector2D& v);
private:
	double _x = 0, _y = 0;
};

#endif

