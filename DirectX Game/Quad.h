#pragma once
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Constants.h"
#include "EngineTime.h"
#include "CameraManager.h"

class Quad
{
	private:
		VertexBuffer* vertexBuffer;
		ConstantBuffer* constantBuffer;
		VertexShader* vertexShader;
		PixelShader* pixelShader;
		unsigned long oldTime = 0;
		float deltaTime = 0;
		float deltaPos = 0;
		float deltaScale = 0;
		float multiplier = 1.0f;
		float angle = 0;
		float rotX = 0;
		float rotY = 0;
		float rotZ = 0;
		Vector3D scale;
		Vector3D position;
		
	public:
		Quad();
		Quad(float width, float height);
		Quad(float width, float height, Transforms transformMatrices);
		void Load();
		void Draw();
		void Release();
		~Quad();
	public:
		void updatePosition();
	private:
		float windowWidth, windowHeight;
};

