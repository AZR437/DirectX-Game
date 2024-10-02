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


	HRESULT hRes =GraphicsEngine::GetInstance()->dxgiFactory->CreateSwapChain(device, &desc, &this->swapChain);

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
