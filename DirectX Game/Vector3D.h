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


	public:
		float x, y, z;
};

