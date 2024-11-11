#include "PixelShader.h"



PixelShader::PixelShader(RenderSystem* renderSystem, const void* shaderByteCode, size_t byteCodeSize):pixelShader(0), renderSystem(renderSystem)
{
	if (!SUCCEEDED(renderSystem->d3dDevice->CreatePixelShader(shaderByteCode, byteCodeSize, nullptr, &this->pixelShader)))
	{
		throw std::exception("Pixel shader was not created successfully");
	}
}



PixelShader::~PixelShader()
{
	this->pixelShader->Release();
}
