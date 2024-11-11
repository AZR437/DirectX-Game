#include "RenderSystem.h"

RenderSystem::RenderSystem()
{
}

bool RenderSystem::Init()
{

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT driverTypeCount = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0
	};
	UINT featureLevelCount = ARRAYSIZE(featureLevels);
	HRESULT res = 0;

	for (UINT driverTypeIndex = 0; driverTypeIndex < driverTypeCount;)
	{
		res = D3D11CreateDevice(NULL, driverTypes[driverTypeIndex], NULL, NULL, featureLevels,
			featureLevelCount, D3D11_SDK_VERSION, &this->d3dDevice, &this->featureLevel, &immContext);

		if (SUCCEEDED(res))
		{
			++driverTypeIndex;
			break;
		}

	}
	if (FAILED(res))
	{
		std::cout << "Errot in device creation" << std::endl;
		return false;
	}

	immDeviceContext = new DeviceContext(immContext, this);

	this->d3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&this->dxgiDevice);
	this->dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&this->dxgiAdapter);
	this->dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&this->dxgiFactory);


	return true;
}
bool RenderSystem::Release()
{
	dxgiDevice->Release();
	dxgiAdapter->Release();
	dxgiFactory->Release();
	this->d3dDevice->Release();
	return true;
}


RenderSystem::~RenderSystem()
{
}
SwapChain* RenderSystem::CreateSwapChain(HWND hwnd, UINT width, UINT height)
{
	SwapChain* swapChain = nullptr;
	try
	{
		swapChain = new SwapChain(this, hwnd, width, height);
	}
	catch(...)
	{
		std::cout << "SwapChain Creation Error" << std::endl;
	}
	return swapChain;
}


VertexBuffer* RenderSystem::CreateVertexBuffer(void* listVertices, UINT sizeVertex, UINT sizeList, void* shaderByteCode, UINT sizeByteShader)
{
	VertexBuffer* vertBuffer = nullptr;
	try
	{
		vertBuffer = new VertexBuffer(this, listVertices, sizeVertex, sizeList, shaderByteCode, sizeByteShader);
	}
	catch (...)
	{
		std::cout << "VertexBuffer Creation Error" << std::endl;
	}
	return vertBuffer;
}

IndexBuffer* RenderSystem::CreateIndexBuffer(void* listIndices, UINT sizeList)
{
	IndexBuffer* indexBuffer = nullptr;
	try
	{
		indexBuffer = new IndexBuffer(this, listIndices, sizeList);
	}
	catch (...)
	{
		std::cout << "IndexBuffer Creation Error" << std::endl;
	}
	return  indexBuffer;
}

ConstantBuffer* RenderSystem::CreateConstantBuffer(void* buffer, UINT sizeBuffer)
{
	ConstantBuffer* constBuffer = nullptr;
	try
	{
		constBuffer = new ConstantBuffer(this, buffer, sizeBuffer);
	}
	catch (...)
	{
		std::cout << "ConstantBuffer Creation Error" << std::endl;
	}
	return constBuffer;
}

VertexShader* RenderSystem::CreateVertexShaders(const void* shaderByteCode, size_t byteCodeSize)
{
	VertexShader* vertShader = nullptr;
	try
	{
		vertShader = new VertexShader(this, shaderByteCode, byteCodeSize);
	}
	catch (...)
	{
		std::cout << "VertexShader Creation Error" << std::endl;
	}
	return vertShader;
}

PixelShader* RenderSystem::CreatePixelShader(const void* shaderByteCode, size_t byteCodeSize)
{
	PixelShader* pixShader = nullptr;
	try
	{
		pixShader = new PixelShader(this, shaderByteCode, byteCodeSize);
	}
	catch (...)
	{
		std::cout << "PixelShader Creation Error" << std::endl;
	}
	return pixShader;
}
DeviceContext* RenderSystem::GetImmediateDeviceContext()
{
	return this->immDeviceContext;
}

bool RenderSystem::CompileVertexShaders(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize)
{
	ID3DBlob* errorBlob = nullptr;
	if (!SUCCEEDED(::D3DCompileFromFile(fileName, nullptr, nullptr, entryPointName, "vs_5_0", 0, 0, &this->blob, &errorBlob)))
	{
		if (errorBlob)
		{
			errorBlob->Release();
		}
		return false;
	}
	*shaderByteCode = this->blob->GetBufferPointer();
	*byteCodeSize = this->blob->GetBufferSize();
	return true;
}

bool RenderSystem::CompilePixelShader(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize)
{
	ID3DBlob* errorBlob = nullptr;
	if (!SUCCEEDED(::D3DCompileFromFile(fileName, nullptr, nullptr, entryPointName, "ps_5_0", 0, 0, &this->blob, &errorBlob)))
	{
		if (errorBlob)
		{
			errorBlob->Release();
		}
		return false;
	}
	*shaderByteCode = this->blob->GetBufferPointer();
	*byteCodeSize = this->blob->GetBufferSize();
	return true;
}

void RenderSystem::ReleaseCompiledShader()
{
	if (this->blob)
	{
		this->blob->Release();
	}
}

ID3D11Device* RenderSystem::GetDirectXDevice()
{
	return this->d3dDevice;
}
