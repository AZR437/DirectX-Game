#pragma once
class Vector3D
{
	public:
		Vector3D();
		Vector3D(float x, float y, float z);
		Vector3D(const Vector3D& vector);
		~Vector3D();
public:
	static Vector3D Lerp(const Vector3D& start, const Vector3D& end, float delta);
	Vector3D operator *(float num);
	Vector3D operator +(Vector3D vec);

    friend Vector3D operator-(const Vector3D& right);
    friend Vector3D operator+(const Vector3D& left, const Vector3D& right);
    friend Vector3D& operator+=(Vector3D& left, const Vector3D& right);
    friend Vector3D operator-(const Vector3D& left, const Vector3D& right);
    friend Vector3D& operator-=(Vector3D& left, const Vector3D& right);
    friend Vector3D operator*(const Vector3D& left, const Vector3D& right);
    friend Vector3D& operator*=(Vector3D& left, const Vector3D& right);
    friend Vector3D operator*(const Vector3D& left, const float& right);
    friend Vector3D operator*(const float& left, const Vector3D& right);
    friend Vector3D& operator*=(Vector3D& left, const float& right);
    friend Vector3D operator/(const Vector3D& left, const Vector3D& right);
    friend Vector3D& operator/=(Vector3D& left, const Vector3D& right);
    friend Vector3D operator/(const Vector3D& left, const float& right);
    friend Vector3D operator/(const float& left, const Vector3D& right);
    friend Vector3D& operator/=(Vector3D& left, const float& right);
    friend bool operator==(const Vector3D& left, const Vector3D& right);
    friend bool operator!=(const Vector3D& left, const Vector3D& right);
	public:
		float x, y, z;
};

