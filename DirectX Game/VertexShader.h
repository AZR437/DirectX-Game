#pragma once
#include "d3d11.h"
#include "RenderSystem.h"
#include "DeviceContext.h"
#include "RenderSystem.h"
#include "Prerequisite.h"
#include "exception"

class VertexShader
{
public: 
	VertexShader(RenderSystem* renderSystem, const void* shaderByteCode, size_t byteCodeSize);
	~VertexShader();
private:
	ID3D11VertexShader* vertexShader;
	RenderSystem* renderSystem = nullptr;
private:
	friend class DeviceContext;
	friend class RenderSystem;
};

