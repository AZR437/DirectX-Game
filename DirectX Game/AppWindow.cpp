#include "AppWindow.h"

AppWindow* AppWindow::sharedInstance = NULL;

AppWindow::AppWindow()
{
	
}
AppWindow::~AppWindow()
{
	
}

void AppWindow::OnKeyDown(int key)
{
	
}

void AppWindow::OnKeyRelease(int key)
{
}

void AppWindow::OnMouseMove(const Vector2D& deltaMousePos)
{
	//std::cout << "X:" << deltaMousePos.x << std::endl;
	//std::cout << "Y:" << deltaMousePos.y << std::endl;
}

void AppWindow::OnFocus()
{
	InputSystem::GetInstance()->AddListener(this);
}

void AppWindow::OnKillFocus()
{
	InputSystem::GetInstance()->RemoveListener(this);
}

void AppWindow::OnLeftMouseDown(const Vector2D& mousePos)
{
	
	//std::cout << "LM Press" << std::endl;
}

void AppWindow::OnLeftMouseRelease(const Vector2D& mousePos)
{
	
	//std::cout << "LM Release" << std::endl;
}

void AppWindow::OnRightMouseDown(const Vector2D& mousePos)
{
	//::ShowCursor(false);
	//std::cout << "RM Press" << std::endl;
}

void AppWindow::OnRightMouseRelease(const Vector2D& mousePos)
{
	//::ShowCursor(true);
	/*std::cout << "RM Release" << std::endl;*/
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
	InputSystem::Initialize();
	CameraManager::Initialize();
	Window::OnCreate();
	GraphicsEngine* graphics = GraphicsEngine::GetInstance();;
	InputSystem* input = InputSystem::GetInstance();
	graphics->InitDX();
	input->AddListener(this);
	this->swapChain = graphics->CreateSwapChain();

	RECT rc = this->GetClientWindowRect();
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;

	this->swapChain->Init(this->hwnd, width, height);

	CameraManager::GetInstance()->CreateCamera();
	CameraManager::GetInstance()->GetSelectedCamera()->SetWidthAndHeight(width, height);
	//CameraManager::GetInstance()->GetSelectedCamera()->SetOrtho(width / 300.0f, height / 300.0f, -4.0f, 4.0f);
	CameraManager::GetInstance()->GetSelectedCamera()->SetPers(1.87f, width / height, 0.01f, 1000.0f);
	



	this->primitiveLoader = new PrimitiveLoader(width, height);
	Transforms cubeTransformList[] =
	{
		{Vector3D(0.25f,0.25f,0.25f), Vector3D(0,0,0), Vector3D(0.f,-1.f,0)}
	};
	Transforms quadTransformList[] =
	{
		{Vector3D(5.f,5.f,5.f), Vector3D(90,0,0), Vector3D(0.f,-1.f,0)}
	};
	Transforms circleTransformList[] =
	{
		{Vector3D(5.f,5.f,5.f), Vector3D(0,0,0), Vector3D(0.f,0.f,0)}
	};
	this->primitiveLoader->LoadPrimitives(CUBE, 1, cubeTransformList);
	this->primitiveLoader->LoadPrimitives(QUAD, 1, quadTransformList);
	this->primitiveLoader->LoadPrimitives(CIRCLE, 1,circleTransformList);
	

}
void AppWindow::OnUpdate()
{
	Window::OnUpdate();
	InputSystem::GetInstance()->Update();
	CameraManager::GetInstance()->Update();
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
	delete sharedInstance;
	Window::OnDestroy();
}