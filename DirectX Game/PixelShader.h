#pragma once

#include "d3d11.h"
#include "GraphicsEngine.h"
#include "DeviceContext.h"

class GraphicsEngine;
class DeviceContext;

class PixelShader
{
	private:
		bool Init(const void* shaderByteCode, size_t byteCodeSize);
	public:
		PixelShader();
		void Release();
		~PixelShader();
	private:
		ID3D11PixelShader* pixelShader;
	private:
		friend class GraphicsEngine;
		friend class DeviceContext;


};

