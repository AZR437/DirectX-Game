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
void Matrix4x4::SetScale(const Vector3D& scale)
{
	this->SetIdentity();
	this->matrix[0][0] = scale.x;
	this->matrix[1][1] = scale.y;
	this->matrix[2][2] = scale.z;
}

void Matrix4x4::SetRotationX(float x)
{
	this->matrix[1][1] = cos(x);
	this->matrix[1][2] = sin(x);
	this->matrix[2][1] = -sin(x);
	this->matrix[2][2] = cos(x);
}

void Matrix4x4::SetRotationY(float y)
{
	this->matrix[0][0] = cos(y);
	this->matrix[0][2] = -sin(y);
	this->matrix[2][0] = sin(y);
	this->matrix[2][2] = cos(y);
}

void Matrix4x4::SetRotationZ(float z)
{
	this->matrix[0][0] = cos(z);
	this->matrix[0][1] = sin(z);
	this->matrix[1][0] = -sin(z);
	this->matrix[1][1] = cos(z);
}

void Matrix4x4::SetOrthoPM(float width, float height, float nearPlane, float farPlane)
{
	this->SetIdentity();
	this->matrix[0][0] = 2.0f/ width;
	this->matrix[1][1] = 2.0f/height;
	this->matrix[2][2] = 1.0f / (farPlane - nearPlane);
	this->matrix[3][2] = -(nearPlane / (farPlane - nearPlane));
}

void Matrix4x4::operator*=(const Matrix4x4& matrix)
{
	Matrix4x4 out;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			out.matrix[i][j] =
				this->matrix[i][0] * matrix.matrix[0][j] + this->matrix[i][1] * matrix.matrix[1][j] +
				this->matrix[i][2] * matrix.matrix[2][j] + this->matrix[i][3] * matrix.matrix[3][j];
		}
	}
	::memcpy(this->matrix, out.matrix, sizeof(float) * 16);
}



Matrix4x4::~Matrix4x4()
{
}
