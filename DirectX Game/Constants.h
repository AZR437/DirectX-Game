#pragma once
#include "Vector3D.h"
#include "Matrix4x4.h"
struct vertex
{
	Vector3D position;
	Vector3D position1;
	Vector3D colour;
	Vector3D colour1;

};
struct transform2D
{
	float x, y, scale;
};
struct transformList2D
{
	transform2D transform;
};

__declspec(align(16))
struct constant
{
	Matrix4x4 world;
	Matrix4x4 view;
	Matrix4x4 projection;
	float angle;
};
enum PrimitveType
{
	QUAD = 0,
	TRI
};
