#include "AppWindow.h"


AppWindow::AppWindow()
{
	
}
AppWindow::~AppWindow()
{
	
}

void AppWindow::OnCreate()
{
	Window::OnCreate();
	GraphicsEngine::GetInstance()->Init();
	this->swapChain =GraphicsEngine::GetInstance()->CreateSwapChain();

	RECT rc = this->GetClientWindowRect();
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;
	this->swapChain->Init(this->hwnd, width, height);

	



	this->primitiveLoader = new PrimitiveLoader();
	transformList2D quadTransforms[] =
	{
		{1.5f, 1.5f, 0.45f},
		{-1.5f, 1.5f, 0.45f},
		{1.5f, -1.5f, 0.45f},
		{-1.5f, -1.5f, 0.45f},
	};
	transformList2D triTransforms[] =
	{
		{0.0f, 0.0f, 0.45f},
		{1.0f, 0.0f, 0.45f},
		{-1.0f, 0.0f, 0.45f},
		{0.0f, 1.0f, 0.45f},
		{0.0f, -1.0f, 0.45f},
	};
	this->primitiveLoader->LoadPrimitive(QUAD, 4, quadTransforms);
	this->primitiveLoader->LoadPrimitive(TRI, 5, triTransforms);
}
void AppWindow::OnUpdate()
{
	Window::OnUpdate();
	//Clear Render Target
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->ClearRenderTargetColor(this->swapChain,0,0,0,1);
	// Set viewport for render target to use to draw
	RECT rc = this->GetClientWindowRect();
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetViewPortSize(width, height);

	

	


	this->primitiveLoader->DrawPrimitives();
	this->swapChain->Present(true);
}
void AppWindow::OnDestroy()
{
	this->swapChain->Release();
	this->primitiveLoader->ReleasePrimitives();
	Window::OnDestroy();
}