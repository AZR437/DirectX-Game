#include "Matrix4x4.h"
#include "iostream"
Matrix4x4::Matrix4x4()
{

}

void Matrix4x4::SetIdentity()
{
	::memset(matrix, 0, sizeof(float) * 16);
	this->matrix[0][0] = 1;
	this->matrix[1][1] = 1;
	this->matrix[2][2] = 1;
	this->matrix[3][3] = 1;
}

void Matrix4x4::SetTranslate(const Vector3D& translation)
{
	this->SetIdentity();
	this->matrix[3][0] = translation.x;
	this->matrix[3][1] = translation.y;
	this->matrix[3][2] = translation.z;
}

void Matrix4x4::SetOrthoPM(float width, float height, float nearPlane, float farPlane)
{
	this->SetIdentity();
	this->matrix[0][0] = 2.0f/ width;
	this->matrix[1][1] = 2.0f/height;
	this->matrix[2][2] = 1.0f / (farPlane - nearPlane);
	this->matrix[3][2] = -(nearPlane / (farPlane - nearPlane));
}





Matrix4x4::~Matrix4x4()
{
}
