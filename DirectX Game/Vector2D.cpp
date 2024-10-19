#include "Vector2D.h"

Vector2D::Vector2D()
{
	this->x = 0;
	this->y = 0;
}

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D(const Vector2D& vector2D)
{
	this->x = vector2D.x;
	this->y = vector2D.y;
}

Vector2D::~Vector2D()
{
}


bool operator!=(const Vector2D& left, const Vector2D& right)
{
	return (left.x != right.x || left.y != right.y);;
}
