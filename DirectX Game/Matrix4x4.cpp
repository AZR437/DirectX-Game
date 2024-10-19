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

Vector3D Matrix4x4::GetTranslate()
{
	return Vector3D(this->matrix[3][0], this->matrix[3][1], this->matrix[3][2]);
}

Vector3D Matrix4x4::GetRight()
{
	return Vector3D(this->matrix[0][0], this->matrix[1][0], this->matrix[2][0]);
}

Vector3D Matrix4x4::GetUp()
{
	return Vector3D(this->matrix[0][1], this->matrix[1][0], this->matrix[2][0]);
}

Vector3D Matrix4x4::GetForward()
{
	return Vector3D(this->matrix[0][2], this->matrix[1][2], this->matrix[2][2]);
}

float Matrix4x4::GetDeterminant() const
{
	Vector4D minor, v1, v2, v3;
	float det;

	v1 = Vector4D(this->matrix[0][0], this->matrix[1][0], this->matrix[2][0], this->matrix[3][0]);
	v2 = Vector4D(this->matrix[0][1], this->matrix[1][1], this->matrix[2][1], this->matrix[3][1]);
	v3 = Vector4D(this->matrix[0][2], this->matrix[1][2], this->matrix[2][2], this->matrix[3][2]);

	minor = Vector4D::Cross(v1, v2, v3);
	det = -(this->matrix[0][3] * minor.x + this->matrix[1][3] * minor.y + this->matrix[2][3] * minor.z +
		this->matrix[3][3] * minor.w);
	return det;
}

void Matrix4x4::Inverse()
{
	int a, i, j;
	Matrix4x4 out;
	Vector4D v, vec[3];
	float det = 0.0f;

	det = this->GetDeterminant();
	if (!det) return;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j != i)
			{
				a = j;
				if (j > i) a = a - 1;
				vec[a].x = (this->matrix[j][0]);
				vec[a].y = (this->matrix[j][1]);
				vec[a].z = (this->matrix[j][2]);
				vec[a].w = (this->matrix[j][3]);
			}
		}
		v = Vector4D::Cross(vec[0], vec[1], vec[2]);

		out.matrix[0][i] = powf(-1.0f, i) * v.x / det;
		out.matrix[1][i] = powf(-1.0f, i) * v.y / det;
		out.matrix[2][i] = powf(-1.0f, i) * v.z / det;
		out.matrix[3][i] = powf(-1.0f, i) * v.w / det;
	}

	this->SetMatrix(out);
}

void Matrix4x4::SetOrthoPM(float width, float height, float nearPlane, float farPlane)
{
	this->SetIdentity();
	this->matrix[0][0] = 2.0f/ width;
	this->matrix[1][1] = 2.0f/height;
	this->matrix[2][2] = 1.0f / (farPlane - nearPlane);
	this->matrix[3][2] = -(nearPlane / (farPlane - nearPlane));
}

void Matrix4x4::SetMatrix(const Matrix4x4& matrix)
{
	::memcpy(this->matrix, matrix.matrix, sizeof(float) * 16);
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

void Matrix4x4::SetPerspectiveFovLH(float fov, float aspect, float znear, float zfar)
{
	float yscale = 1.0f / tan(fov / 2.0f);
	float xscale = yscale / aspect;
	matrix[0][0] = xscale;
	matrix[1][1] = yscale;
	matrix[2][2] = zfar / (zfar - znear);
	matrix[2][3] = 1.0f;
	matrix[3][2] = (-znear * zfar) / (zfar - znear);
}



Matrix4x4::~Matrix4x4()
{
}
