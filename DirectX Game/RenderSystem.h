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
#include "Prerequisite.h"


class RenderSystem
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
private:
	friend class SwapChain;
	friend class VertexBuffer;
	friend class ConstantBuffer;
	friend class VertexShader;
	friend class PixelShader;
	friend class IndexBuffer;
public:

	RenderSystem();
	//Initialize graphics engine & Dx11 Device
	bool Init();
	//Release all resources loaded
	bool Release();
	~RenderSystem();
public:
	SwapChain* CreateSwapChain(HWND hwnd, UINT width, UINT height);
	VertexBuffer* CreateVertexBuffer(void* listVertices, UINT sizeVertex, UINT sizeList, void* shaderByteCode, UINT sizeByteShader);
	IndexBuffer* CreateIndexBuffer(void* listIndices, UINT sizeList);
	ConstantBuffer* CreateConstantBuffer(void* buffer, UINT sizeBuffer);
	VertexShader* CreateVertexShaders(const void* shaderByteCode, size_t byteCodeSize);
	PixelShader* CreatePixelShader(const void* shaderByteCode, size_t byteCodeSize);
	DeviceContext* GetImmediateDeviceContext();
public:
	bool CompileVertexShaders(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize);
	bool CompilePixelShader(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize);
	void ReleaseCompiledShader();
public:
	ID3D11Device* GetDirectXDevice();


};

