#include "VertexShader.h"

bool VertexShader::Init(const void* shaderByteCode, size_t byteCodeSize)
{
	if (!SUCCEEDED(GraphicsEngine::GetInstance()->d3dDevice->CreateVertexShader(shaderByteCode, byteCodeSize, nullptr, &this->vertexShader)))
	{
		return false;
	}
	return true;
}

VertexShader::VertexShader()
{
}

void VertexShader::Release()
{
	this->vertexShader->Release();
	delete this;
}

VertexShader::~VertexShader()
{
}
