#pragma once
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Constants.h".h"
#include "EngineTime.h"
#include "vector"
#include "CameraManager.h"
class Circle
{
	private:
		VertexBuffer* vertexBuffer = nullptr;
		ConstantBuffer* constantBuffer = nullptr;
		VertexShader* vertexShader = nullptr;
		PixelShader* pixelShader = nullptr;
		unsigned long oldTime = 0;
		float deltaTime = 0;
		float deltaScale = 0;
		float deltaPos = 0;
		float multiplier = 1.0f;
		float angle = 0;
		float rotX = 0.f;
		float rotY = 0.f;
		float rotZ = 0.f;
		float windowWidth, windowHeight;
		Vector3D position;
		Vector3D scale;
		std::vector<vertex> vertices = {};
		
	
public:
	Circle();
	Circle(float width, float height, Transforms transform);
	//Circle(float width, float height, Vector3D start, Vector3D destination);
	Circle(float width, float height);
	void Load();
	void Draw();
	void Release();
	~Circle();
public:
	void updatePosition();


};

