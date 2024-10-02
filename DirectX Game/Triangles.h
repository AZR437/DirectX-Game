#pragma once
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Constants.h"

class Triangles
{
private:
	vec3 position;
	float scale;
	VertexBuffer* vertexBuffer;
	ConstantBuffer* constantBuffer;
	VertexShader* vertexShader;
	PixelShader* pixelShader;
	unsigned long oldTime = 0;
	float deltaTime = 0;
	float angle = 0;
	vertex list[];
public:
	Triangles();
	Triangles(float x, float y, float scale);
	void Load();
	void Draw();
	void Release();
	~Triangles();
private:
	void Translate(vertex list[3], UINT listSize);
	void Scale(vertex list[3], UINT listSize);
};

