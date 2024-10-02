#pragma once
#include "d3d11.h"
#include "d3dcompiler.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "VertexBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "ConstantBuffer.h"

class SwapChain;
class DeviceContext;
class VertexBuffer;
class ConstantBuffer;
class VertexShader;
class PixelShader;

class GraphicsEngine
{
	public:
		GraphicsEngine();
		//Initialize graphics engine & Dx11 Device
		bool Init();
		//Release all resources loaded
		bool Release();
		~GraphicsEngine();
	public:
		SwapChain* CreateSwapChain();
		DeviceContext* GetImmediateDeviceContext();
		VertexBuffer* CreateVertexBuffer();
		ConstantBuffer* CreateConstantBuffer();
		VertexShader* CreateVertexShaders(const void* shaderByteCode, size_t byteCodeSize);
		PixelShader* CreatePixelShader(const void* shaderByteCode, size_t byteCodeSize);
	public:
		bool CompileVertexShaders(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize);
		bool CompilePixelShader(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize);
		void ReleaseCompiledShader();

		
	public:
		static GraphicsEngine* GetInstance();
	private:
		DeviceContext* immDeviceContext;
	private:
		ID3D11Device* d3dDevice;
		D3D_FEATURE_LEVEL featureLevel;
		ID3D11DeviceContext* immContext;
	private:
		IDXGIDevice* dxgiDevice;
		IDXGIAdapter* dxgiAdapter;
		IDXGIFactory* dxgiFactory;
		ID3DBlob* blob;
		ID3DBlob* vsBlob;
		ID3DBlob* psBlob;
		ID3D11VertexShader* vertexShader;
		ID3D11PixelShader* pixelShader;
	private:
		friend class SwapChain;
		friend class VertexBuffer;
		friend class ConstantBuffer;
		friend class VertexShader;
		friend class PixelShader;
		
};

