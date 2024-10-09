#pragma once
#include "Vector3D.h"
#include "memory"

class Matrix4x4
{
public:
	Matrix4x4();
	void SetIdentity();
	void SetTranslate(const Vector3D& translation);
	void SetOrthoPM(float width, float height, float nearPlane, float farPlane);
	~Matrix4x4();
private:
	float matrix[4][4] = {};
};

