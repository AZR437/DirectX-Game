#pragma once
struct vec3
{
	float x, y, z;
};
struct vertex
{
	vec3 position;
	vec3 position1;
	vec3 colour;
	vec3 colour1;

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
	float angle;
};
enum PrimitveType
{
	QUAD = 0,
	TRI
};
