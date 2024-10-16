#pragma once
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Constants.h"
#include "EngineTime.h"

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
		Vector3D scale;
		Vector3D position;
		Vector3D rotation;
		
	public:
		Quad();
		Quad(float width, float height);
		Quad(float width, float height, Vector3D scale, Vector3D position, Vector3D rotation);
		void Load();
		void Draw();
		void Release();
		~Quad();
	public:
		void updatePosition();
	private:
		float windowWidth, windowHeight;
};

