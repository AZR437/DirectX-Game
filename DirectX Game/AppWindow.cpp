#include "AppWindow.h"

AppWindow* AppWindow::sharedInstance = NULL;

AppWindow::AppWindow()
{
	
}
AppWindow::~AppWindow()
{
	
}

void AppWindow::Initialize()
{
	sharedInstance = new AppWindow();
}

AppWindow* AppWindow::GetInstance()
{
	return sharedInstance;
}

void AppWindow::OnCreate()
{
	GraphicsEngine::Initialize();
	Window::OnCreate();
	GraphicsEngine* graphics = GraphicsEngine::GetInstance();;
	graphics->InitDX();

	this->swapChain = graphics->CreateSwapChain();

	RECT rc = this->GetClientWindowRect();
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;

	this->swapChain->Init(this->hwnd, width, height);

	



	this->primitiveLoader = new PrimitiveLoader(width, height);
	transformList2D quadTransforms[] =
	{
		{0.0f, 0.0f, 2.0f},

	};

	this->primitiveLoader->LoadPrimitive(QUAD, 1, quadTransforms);

}
void AppWindow::OnUpdate()
{
	Window::OnUpdate();
	//Clear Render Target
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->ClearRenderTargetColor(this->swapChain,0.25,0.75f,0.85f,1);
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
	GraphicsEngine::GetInstance()->Destroy();
	Window::OnDestroy();
}