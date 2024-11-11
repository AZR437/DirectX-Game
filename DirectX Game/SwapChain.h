#pragma once
#include "RenderSystem.h"
#include "d3d11.h"
#include "Prerequisite.h"
#include "exception"

class SwapChain
{
	public:
		SwapChain(RenderSystem* renderSystem, HWND hwnd, UINT width, UINT height);

		bool Present(bool vSync);
;
		~SwapChain();
	private:
		IDXGISwapChain* swapChain;
		ID3D11DepthStencilView* depthView;
		ID3D11RenderTargetView* renderTargetView;
		RenderSystem* renderSystem = nullptr;
	private:
		friend class DeviceContext;
};

