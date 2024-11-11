#pragma once
#include "d3d11.h"
#include "SwapChain.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Prerequisite.h"
#include "exception"

class DeviceContext
{
	public:
		DeviceContext(ID3D11DeviceContext* deviceContext, RenderSystem* renderSystem);
		void ClearRenderTargetColor(SwapChainPtr swapChain, float r, float g, float b, float a);
		void SetVertexBuffer(VertexBufferPtr vertexBuffer);
		void SetIndexBuffer(IndexBufferPtr indexBuffer);

		void SetConstantBuffer(VertexShaderPtr vertexShader, ConstantBufferPtr constantBuffer);
		void SetConstantBuffer(PixelShaderPtr pixelShader, ConstantBufferPtr constantBuffer);

		void DrawTriangleList(UINT vertexCount, UINT vertexIndexStart);
		void DrawIndexedTriangleList(UINT indexCount, UINT vertexIndexStart, UINT indexStartLocation);
		void DrawTriangleStrip(UINT vertexCount, UINT vertexIndexStart);
		


		void SetViewPortSize(UINT width, UINT height);

		void SetVertexShader(VertexShaderPtr vertexShader);
		void SetPixelShader(PixelShaderPtr pixelShader);

		ID3D11DeviceContext* GetDeviceContext();
		~DeviceContext();
	private:
		ID3D11DeviceContext* deviceContext;
		RenderSystem* renderSystem = nullptr;
	private:
		friend class ConstantBuffer;
};

