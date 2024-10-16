#pragma once

#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Constants.h"
#include "EngineTime.h"

class Cube
{
private:
	VertexBuffer* vertexBuffer;
	IndexBuffer* indexBuffer;
	ConstantBuffer* constantBuffer;
	VertexShader* vertexShader;
	PixelShader* pixelShader;

	float deltaTime = 0;
	float deltaPos = 0;
	float deltaScale = 0;
	float multiplier = 1.0f;
	float angle = 0;
	Vector3D scale;
	Vector3D position;
	Vector3D rotation;
public:
	Cube();
	Cube(float width, float height);
	Cube(float width, float height, Transforms transformMatrices);

	void Load();
	void Draw();
	void Release();
	~Cube();
public:
	void updatePosition();
private:
	float windowWidth, windowHeight;
};

