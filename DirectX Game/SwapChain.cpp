#include "SwapChain.h"
SwapChain::SwapChain()
{

}
bool SwapChain::Init(HWND hwnd, UINT width, UINT height)
{
	ID3D11Device* device = GraphicsEngine::GetInstance()->d3dDevice;
	
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


	HRESULT hRes = GraphicsEngine::GetInstance()->dxgiFactory->CreateSwapChain(device, &desc, &this->swapChain);

	if (FAILED(hRes))
	{
		return false;
	}

	ID3D11Texture2D* buffer = NULL;
	hRes = swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);


	if (FAILED(hRes))
	{
		return false;
	}

	hRes = device->CreateRenderTargetView(buffer, NULL, &renderTargetView);
	buffer->Release();

	if (FAILED(hRes))
	{
		return false;
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
		return false;
	}
	hRes = device->CreateDepthStencilView(buffer, NULL, &this->depthView);
	if (FAILED(hRes))
	{
		return false;
	}
	buffer->Release();
	return true;
}
bool SwapChain::Present(bool vSync)
{
	this->swapChain->Present(vSync, NULL);

	return true;
}
bool SwapChain::Release()
{
	this->swapChain->Release();
	delete this;
	return true;
}
SwapChain::~SwapChain()
{

}
