#pragma once

#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Constants.h"
#include "EngineTime.h"
#include "InputSystem.h"
#include "CameraManager.h"

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
	float rotX;
	float rotY;
	float rotZ;
	Vector3D scale;
	Vector3D position;
	
public:
	Cube();
	Cube(float width, float height);
	Cube(float width, float height, Transforms transformMatrices);

	void Load();
	void Draw();
	void Release();
	~Cube();
public:
	Vector3D GetScale();
	void SetScale(Vector3D scaleNew);
	Vector3D GetPosition();
	void SetPosition(Vector3D positionNew);
	float GetRotX();
	void SetRotX(float newX);
	float GetRotY();
	void SetRotY(float newY);
	float GetRotZ();
	void SetRotZ(float newZ);
	float GetDeltaTime();
public:
	void updatePosition();
private:
	float windowWidth, windowHeight;
};

