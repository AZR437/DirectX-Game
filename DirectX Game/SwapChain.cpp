#include "SwapChain.h"
SwapChain::SwapChain(RenderSystem* renderSystem, HWND hwnd, UINT width, UINT height) :depthView(0), renderTargetView(0), swapChain(0), renderSystem(renderSystem)
{
	ID3D11Device* device = renderSystem->d3dDevice;

	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.BufferCount = 1;
	desc.BufferDesc.Width = width;
	desc.BufferDesc.Height = height;
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.BufferDesc.RefreshRate.Numerator = 60;
	desc.BufferDesc.RefreshRate.Denominator = 1;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.OutputWindow = hwnd;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Windowed = TRUE;


	HRESULT hRes = renderSystem->dxgiFactory->CreateSwapChain(device, &desc, &this->swapChain);

	if (FAILED(hRes))
	{
		throw std::exception("Swap chain was not created successfully.");
	}

	ID3D11Texture2D* buffer = NULL;
	hRes = this->swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);


	if (FAILED(hRes))
	{
		throw std::exception("Swap chain was not created successfully.");
	}

	hRes = device->CreateRenderTargetView(buffer, NULL, &renderTargetView);
	buffer->Release();

	if (FAILED(hRes))
	{
		throw std::exception("Render target view was not created successfully.");
	}
	D3D11_TEXTURE2D_DESC textureDesc = {};
	textureDesc.Width = width;
	textureDesc.Height = height;
	textureDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	textureDesc.MipLevels = 1;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.MiscFlags = 0;
	textureDesc.ArraySize = 1;
	textureDesc.CPUAccessFlags = 0;

	hRes = device->CreateTexture2D(&textureDesc, NULL, &buffer);
	if (FAILED(hRes))
	{
		throw std::exception("Texture 2D was not created successfully.");
	}
	hRes = device->CreateDepthStencilView(buffer, NULL, &this->depthView);
	if (FAILED(hRes))
	{
		throw std::exception("Stencil View was not created successfully.");
	}
	buffer->Release();
}

bool SwapChain::Present(bool vSync)
{
	this->swapChain->Present(vSync, NULL);

	return true;
}

SwapChain::~SwapChain()
{
	this->swapChain->Release();
	this->renderTargetView->Release();
	this->depthView->Release();
}
