#include "GraphicsEngine.h"
GraphicsEngine* GraphicsEngine::sharedInstance = NULL;

GraphicsEngine::GraphicsEngine()
{

}
GraphicsEngine::~GraphicsEngine()
{

}
bool GraphicsEngine::InitDX()
{
	
	D3D_DRIVER_TYPE driverTypes[]=
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
			featureLevelCount, D3D11_SDK_VERSION,&this->d3dDevice, &this->featureLevel, &immContext);

		if (SUCCEEDED(res))
		{
			break;
			++driverTypeIndex;
		}
		
	}
	if (FAILED(res))
	{
		return false;
	}

	immDeviceContext = new DeviceContext(immContext);

	this->d3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&this->dxgiDevice);
	this->dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&this->dxgiAdapter);
	this->dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&this->dxgiFactory);

	
	return true;
}
bool GraphicsEngine::Release()
{
	dxgiDevice->Release();
	dxgiAdapter->Release();
	dxgiFactory->Release();
	this->immDeviceContext->Release();
	this->d3dDevice->Release();
	return true;
	delete sharedInstance;
}

void GraphicsEngine::Initialize()
{
	sharedInstance = new GraphicsEngine();
	sharedInstance->InitDX();
}

void GraphicsEngine::Destroy()
{
	if (sharedInstance != NULL)
	{
		sharedInstance->Release();
	}
}

SwapChain* GraphicsEngine::CreateSwapChain()
{
	return new SwapChain();
}
DeviceContext* GraphicsEngine::GetImmediateDeviceContext()
{
	return this->immDeviceContext;
}

VertexBuffer* GraphicsEngine::CreateVertexBuffer()
{
	return new VertexBuffer();
}

IndexBuffer* GraphicsEngine::CreateIndexBuffer()
{
	return new IndexBuffer();
}

ConstantBuffer* GraphicsEngine::CreateConstantBuffer()
{
	return new ConstantBuffer();
}

VertexShader* GraphicsEngine::CreateVertexShaders(const void* shaderByteCode, size_t byteCodeSize)
{
	VertexShader* vertShader = new VertexShader();
	if (!vertShader->Init(shaderByteCode, byteCodeSize))
	{
		vertShader->Release();
		return nullptr;
	}
	return vertShader;
}

PixelShader* GraphicsEngine::CreatePixelShader(const void* shaderByteCode, size_t byteCodeSize)
{
	PixelShader* pixShader = new PixelShader();
	if (!pixShader->Init(shaderByteCode, byteCodeSize))
	{
		pixShader->Release();
		return nullptr;
	}
	return pixShader;
}

bool GraphicsEngine::CompileVertexShaders(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize)
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

bool GraphicsEngine::CompilePixelShader(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize)
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

void GraphicsEngine::ReleaseCompiledShader()
{
	if (this->blob)
	{
		this->blob->Release();
	}
}






GraphicsEngine* GraphicsEngine::GetInstance()
{
	return sharedInstance;
}

ID3D11Device* GraphicsEngine::GetDirectXDevice()
{
	return this->d3dDevice;
}
