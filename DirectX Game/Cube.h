#pragma once

#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Constants.h"
#include "EngineTime.h"
#include "InputSystem.h"
#include "CameraManager.h"
#include "GraphicsEngine.h"
class Cube
{
private:
	VertexBufferPtr vertexBuffer;
	IndexBufferPtr indexBuffer;
	ConstantBufferPtr constantBuffer;
	VertexShaderPtr vertexShader;
	PixelShaderPtr pixelShader;

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
	bool isPlane;
	
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

