#pragma once
#include "d3d11.h"
#include "SwapChain.h"
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"

class SwapChain;
class VertexBuffer;
class ConstantBuffer;
class VertexShader;
class PixelShader;

class DeviceContext
{
	public:
		DeviceContext(ID3D11DeviceContext* deviceContext);
		void ClearRenderTargetColor(SwapChain* swapChain, float r, float g, float b, float a);
		void SetVertexBuffer(VertexBuffer* vertexBuffer);

		void SetConstantBuffer(VertexShader* vertexShader, ConstantBuffer* constantBuffer);
		void SetConstantBuffer(PixelShader* pixelShader, ConstantBuffer* constantBuffer);

		void DrawTriangleList(UINT vertexCount, UINT vertexIndexStart);

		void DrawTriangleStrip(UINT vertexCount, UINT vertexIndexStart);

		void SetViewPortSize(UINT width, UINT height);

		void SetVertexShader(VertexShader* vertexShader);
		void SetPixelShader(PixelShader* pixelShader);

		bool Release();
		~DeviceContext();
	private:
		ID3D11DeviceContext* deviceContext;
	private:
		friend class ConstantBuffer;
};

