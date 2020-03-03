#include "Vector2D.h"
// default constructor
Vector2D::Vector2D(): _x(0),_y(0)	{}

//constructor with parameters
Vector2D::Vector2D(double x, double y) : _x(x), _y(y)	{}

Vector2D::Vector2D(const Vector2D& v)
{
	//No funciona bien llamandolo desde el constructor por copia, es lo mismo pero ahora si va 
	//set(v);
	_x = v._x;
	_y = v._y;
}

//operator +
Vector2D Vector2D::operator+(const Vector2D& v) const
{
	Vector2D w;
	w._x = this->_x + v._x;
	w._y = this->_y + v._y;
	return w;
}

//operator product when is number x vector
Vector2D Vector2D::operator*(double d) const
{

	Vector2D w;
	w._x = this->_x * d;
	w._y = this->_y * d;
	return w;
}

//operator product when is vector x vector
double Vector2D::operator*(const Vector2D& v)
{

	Vector2D w;
	w._x = this->_x * v._x;
	w._y = this->_y * v._y;
	return w._x+w._y;
}

Vector2D Vector2D::operator=(const Vector2D& v)
{
	set(v);
	return *this;
}
