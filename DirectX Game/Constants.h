#pragma once
#include "Vector3D.h"
#include "Matrix4x4.h"
#define PI 3.14159f
struct vertex
{
	Vector3D position;
	Vector3D colour;
	Vector3D colour1;

};
struct Transforms
{
	Vector3D scale;
	Vector3D rotation;
	Vector3D position;
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
	TRI,
	CUBE,
	CIRCLE
};
