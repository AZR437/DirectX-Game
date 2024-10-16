#pragma once
#include "Vector3D.h"
#include "memory"

class Matrix4x4
{
public:
	Matrix4x4();
	void SetIdentity();
	void SetTranslate(const Vector3D& translation);
	void SetScale(const Vector3D& scale);
	void SetRotationX(float x);
	void SetRotationY(float y);
	void SetRotationZ(float z);


	void operator *=(const Matrix4x4& matrix);
	void SetOrthoPM(float width, float height, float nearPlane, float farPlane);
	~Matrix4x4();
private:
	float matrix[4][4] = {};
};

