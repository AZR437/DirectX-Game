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

	//vertex list[] =
	//{
	//	//X - Y - Z
	//	{-0.5f,-0.5f,0.0f,    -0.32f,-0.11f,0.0f,   1,0,0,  0,0,1 }, // POS1
	//	{-0.5f,0.5f,0.0f,     -0.11f,0.78f,0.0f,    1,0,0,  0,0,1 }, // POS2
	//	{ 0.5f,-0.5f,0.0f,     0.75f,-0.73f,0.0f,   1,0,0,  0,0,1 },// POS2
	//	{ 0.5f,0.5f,0.0f,      0.88f,0.77f,0.0f,    1,0,0,  0,0,1 }
	//};
	//this->vertexBuffer = GraphicsEngine::GetInstance()->CreateVertexBuffer();
	//UINT listSize = ARRAYSIZE(list);
	//


	//

	//void* shaderByteCode = nullptr;
	//size_t shaderSize = 0;

	//GraphicsEngine::GetInstance()->CompileVertexShaders(L"VertexShader.hlsl", "vsmain", &shaderByteCode, &shaderSize);

	//this->vertexShader = GraphicsEngine::GetInstance()->CreateVertexShaders(shaderByteCode, shaderSize);

	//this->vertexBuffer->Load(list, sizeof(vertex), listSize, shaderByteCode, shaderSize);

	//GraphicsEngine::GetInstance()->ReleaseCompiledShader();

	//GraphicsEngine::GetInstance()->CompilePixelShader(L"PixelShader.hlsl", "psmain", &shaderByteCode, &shaderSize);

	//this->pixelShader = GraphicsEngine::GetInstance()->CreatePixelShader(shaderByteCode, shaderSize);

	//GraphicsEngine::GetInstance()->ReleaseCompiledShader();

	/*constant cc;
	cc.angle = 0;

	this->constantBuffer = GraphicsEngine::GetInstance()->CreateConstantBuffer();
	this->constantBuffer->Load(&cc, sizeof(constant));*/




	
	
	//this->quadList.push_back(Quad(0, 0, 0.45f));
	//this->quadList.push_back(Quad(1.5f, 0, 0.45f));
	//this->quadList.push_back(Quad(-1.5f, 0, 0.45f));
	//this->triList.push_back(Triangles(-1.5, -1.5, 0.45));



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

	//unsigned long newTime = 0;
	//if (this->oldTime)
	//	newTime = ::GetTickCount() - this->oldTime;
	//this->deltaTime = newTime / 1000.0f;
	//this->oldTime = ::GetTickCount();

	//this->angle += 1.57f * this->deltaTime;
	//constant cc;
	//cc.angle = this->angle;

	//this->constantBuffer->Update(GraphicsEngine::GetInstance()->GetImmediateDeviceContext(), &cc);

	//GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetConstantBuffer(this->vertexShader, this->constantBuffer);
	//GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetConstantBuffer(this->pixelShader, this->constantBuffer);

	////set default shader in graphics pipeline
	//GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetVertexShader(this->vertexShader);
	//GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetPixelShader(this->pixelShader);
	////Set vertices
	//GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetVertexBuffer(this->vertexBuffer);
	//// Draw
	//GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->DrawTriangleStrip(this->vertexBuffer->GetVertexSizelist(), 0);

	


	this->primitiveLoader->DrawPrimitives();
	this->swapChain->Present(true);
}
void AppWindow::OnDestroy()
{
	this->swapChain->Release();
	//this->vertexBuffer->Release();
	//this->vertexShader->Release();
	//this->pixelShader->Release();
	//this->quadList[0].Release();
	//this->quadList[1].Release();
	//this->quadList[2].Release();
	//this->triList[0].Release();
	this->primitiveLoader->ReleasePrimitives();
	Window::OnDestroy();
}