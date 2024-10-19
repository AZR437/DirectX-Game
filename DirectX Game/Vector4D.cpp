#include "Vector4D.h"

Vector4D::Vector4D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Vector4D::Vector4D(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4D::Vector4D(const Vector4D& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
	this->w = vector.w;
}

Vector4D::~Vector4D()
{
}

Vector4D Vector4D::Cross(const Vector4D& v1, const Vector4D& v2, const Vector4D& v3)
{
	float x = v1.y * (v2.z * v3.w - v3.z * v2.w) - v1.z * (v2.y * v3.w - v3.y * v2.w) + v1.w * (v2.y * v3.z - v2.z * v3.y);
	float y = -(v1.x * (v2.z * v3.w - v3.z * v2.w) - v1.z * (v2.x * v3.w - v3.x * v2.w) + v1.w * (v2.x * v3.z - v3.x * v2.z));
	float z = v1.x * (v2.y * v3.w - v3.y * v2.w) - v1.y * (v2.x * v3.w - v3.x * v2.w) + v1.w * (v2.x * v3.y - v3.x * v2.y);
	float w = -(v1.x * (v2.y * v3.z - v3.y * v2.z) - v1.y * (v2.x * v3.z - v3.x * v2.z) + v1.z * (v2.x * v3.y - v3.x * v2.y));
	return Vector4D(x, y, z, w);
}

Vector4D Vector4D::Lerp(const Vector4D& start, const Vector4D& end, float delta)
{
	Vector4D result;
	result.x = start.x * (1.0f - delta) + (end.x * delta);
	result.y = start.y * (1.0f - delta) + (end.y * delta);
	result.z = start.z * (1.0f - delta) + (end.z * delta);
	result.w = start.w * (1.0f - delta) + (end.w * delta);
	return result;
}


