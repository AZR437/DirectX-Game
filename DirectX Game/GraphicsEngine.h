#pragma once
#include "d3d11.h"
#include "d3dcompiler.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "VertexBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "ConstantBuffer.h"
#include "IndexBuffer.h"

class SwapChain;
class DeviceContext;
class VertexBuffer;
class ConstantBuffer;
class VertexShader;
class PixelShader;
class IndexBuffer;

class GraphicsEngine
{
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
	public:
		
		//Initialize graphics engine & Dx11 Device
		bool InitDX();
		//Release all resources loaded
		bool Release();
		
	public:
		SwapChain* CreateSwapChain();
		DeviceContext* GetImmediateDeviceContext();
		VertexBuffer* CreateVertexBuffer();
		IndexBuffer* CreateIndexBuffer();
		ConstantBuffer* CreateConstantBuffer();
		VertexShader* CreateVertexShaders(const void* shaderByteCode, size_t byteCodeSize);
		PixelShader* CreatePixelShader(const void* shaderByteCode, size_t byteCodeSize);
	public:
		bool CompileVertexShaders(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize);
		bool CompilePixelShader(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize);
		void ReleaseCompiledShader();

		
	public:
		static GraphicsEngine* GetInstance();
		static void Initialize();
		static void Destroy();

	private:
		friend class SwapChain;
		friend class VertexBuffer;
		friend class ConstantBuffer;
		friend class VertexShader;
		friend class PixelShader;
		friend class IndexBuffer;
	private:
		GraphicsEngine();
		GraphicsEngine(GraphicsEngine const&);
		GraphicsEngine& operator = (GraphicsEngine const&) {};
		static GraphicsEngine* sharedInstance;
		~GraphicsEngine();
};

