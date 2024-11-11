#include "VertexShader.h"


VertexShader::VertexShader(RenderSystem* renderSystem, const void* shaderByteCode, size_t byteCodeSize):vertexShader(0), renderSystem(renderSystem)
{
	if (!SUCCEEDED(renderSystem->d3dDevice->CreateVertexShader(shaderByteCode, byteCodeSize, nullptr, &this->vertexShader)))
	{
		throw std::exception("Vertex shader was not created successfully.");
	}
}

VertexShader::~VertexShader()
{
	this->vertexShader->Release();
}
