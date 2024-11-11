#pragma once
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Constants.h"
#include "EngineTime.h"
#include "GraphicsEngine.h"
class Triangles
{
private:

	VertexBufferPtr vertexBuffer;
	ConstantBufferPtr constantBuffer;
	VertexShaderPtr vertexShader;
	PixelShaderPtr pixelShader;
	float deltaTime = 0;
	float deltaPos = 0;
	float angle = 0;
public:
	Triangles();
	Triangles(float x, float y, float scale);
	void Load();
	void Draw();
	void Release();
	~Triangles();

};

