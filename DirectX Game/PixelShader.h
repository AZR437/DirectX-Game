#pragma once

#include "d3d11.h"
#include "RenderSystem.h"
#include "DeviceContext.h"
#include "RenderSystem.h"
#include "Prerequisite.h"
#include "exception"

class PixelShader
{

	public:
		PixelShader(RenderSystem* renderSystem,const void* shaderByteCode, size_t byteCodeSize);
		~PixelShader();
	private:
		ID3D11PixelShader* pixelShader;
		RenderSystem* renderSystem = nullptr;
	private:
		friend class DeviceContext;
		friend class RenderSystem;


};

