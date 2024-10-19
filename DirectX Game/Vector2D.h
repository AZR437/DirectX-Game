#pragma once
#include "math.h"
class Vector2D
{
public:
	float x, y = 0;
public:
	Vector2D();
	Vector2D(float x, float y);
	Vector2D(const Vector2D& vector2D);
	friend bool operator !=(const Vector2D& left, const Vector2D& right);
	~Vector2D();
};

