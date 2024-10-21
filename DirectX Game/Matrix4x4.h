#pragma once
#include "Vector3D.h"
#include "Vector4D.h"
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

	Vector3D GetTranslate();
	Vector3D GetScale();
	Vector3D GetRight();
	Vector3D GetUp();
	Vector3D GetForward();

	float GetDeterminant() const;
	void Inverse();

	

	void operator *=(const Matrix4x4& matrix);
	void SetPerspectiveFovLH(float fov, float aspect, float znear, float zfar);
	void SetOrthoPM(float width, float height, float nearPlane, float farPlane);
	void SetMatrix(const Matrix4x4& matrix);

	~Matrix4x4();
private:
	float matrix[4][4] = {};
};

