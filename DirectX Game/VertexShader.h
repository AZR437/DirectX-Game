#pragma once
#include "d3d11.h"
#include "GraphicsEngine.h"
#include "DeviceContext.h"

class GraphicsEngine;
class DeviceContext;

class VertexShader
{
private:
	bool Init(const void* shaderByteCode, size_t byteCodeSize);
public: 
	VertexShader();
	void Release();
	~VertexShader();
private:
	ID3D11VertexShader* vertexShader;
private:
	friend class GraphicsEngine;
	friend class DeviceContext;
};

