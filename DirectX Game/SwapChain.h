#pragma once
#include "GraphicsEngine.h"
#include "d3d11.h"

class DeviceContext;

class SwapChain
{
	public:
		SwapChain();
		bool Init(HWND hwnd, UINT width, UINT height);

		bool Present(bool vSync);

		bool Release();
		~SwapChain();
	private:
		IDXGISwapChain* swapChain;
		ID3D11RenderTargetView* renderTargetView;
	private:
		friend class DeviceContext;
};

