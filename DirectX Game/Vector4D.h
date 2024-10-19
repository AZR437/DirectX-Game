#pragma once
class Vector4D
{
public:
	float x, y, z, w;
public:
	Vector4D();
	Vector4D(float x, float y, float z, float w);
	Vector4D(const Vector4D& vector);
	~Vector4D();
public:
	static Vector4D Cross(const Vector4D& v1, const Vector4D& v2, const Vector4D& v3);
	static Vector4D Lerp(const Vector4D& start, const Vector4D& end, float delta);


};

