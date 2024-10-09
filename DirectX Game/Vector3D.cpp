#include "Vector3D.h"

Vector3D::Vector3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}



Vector3D::Vector3D(const Vector3D& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

Vector3D::~Vector3D()
{
}

Vector3D Vector3D::Lerp(const Vector3D& start, const Vector3D& end, float delta)
{
	Vector3D result;
	result.x = start.x * (1.0f - delta) + end.x*(delta);
	result.y = start.y * (1.0f - delta) + end.y*(delta);
	result.z = start.z * (1.0f - delta) + end.z*(delta);
	return result;
}


