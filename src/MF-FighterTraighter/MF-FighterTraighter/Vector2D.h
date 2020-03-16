#pragma once
class Vector2D
{
public:
	//constructors
	Vector2D();
	Vector2D(double x, double y);
	Vector2D(const Vector2D& v);
	//destructors
	~Vector2D() {};
	//returns _x
	inline const double& getX() const { return _x; };
	//returns _y
	inline const double& getY() const { return _y; };

	//set _x=x
	inline void setX(double x) { _x = x; };
	//set y=_y
	inline void setY(double y) { _y = y; };
	//set x and y
	inline void set(double x, double y) { 
		_x = x;
		_y = y; 
	};
	inline void set(const Vector2D& v) { 
		_x = v._x; 
		_y = v._y; 
	};

	//operators
	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	double operator*(const Vector2D& v);
	Vector2D operator=(const Vector2D& v);
private:
	double _x = 0, _y = 0;
};
