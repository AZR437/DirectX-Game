#include "PixelShader.h"

bool PixelShader::Init(const void* shaderByteCode, size_t byteCodeSize)
{
	if (!SUCCEEDED(GraphicsEngine::GetInstance()->d3dDevice->CreatePixelShader(shaderByteCode, byteCodeSize, nullptr, &this->pixelShader)))
	{
		return false;
	}
	return true;
}

PixelShader::PixelShader()
{
}

void PixelShader::Release()
{
	
	this->pixelShader->Release();
	delete this;
}

PixelShader::~PixelShader()
{
}
