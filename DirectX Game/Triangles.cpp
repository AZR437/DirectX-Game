#include "Triangles.h"

Triangles::Triangles()
{
}


void Triangles::Load()
{
	vertex list[] =
	{
		//X - Y - Z
		{Vector3D(-0.5f,-0.5f,0.0f), Vector3D(1,0,0),  Vector3D(0,0,1) }, // POS1
		{Vector3D(0.f,0.5f,0.0f),    Vector3D(1,0,0),  Vector3D(0,0,1) }, // POS2
		{Vector3D(0.5f,-0.5f,0.0f),  Vector3D(1,0,0), Vector3D(0,0,1) }
	};
	UINT listSize = ARRAYSIZE(list);





	void* shaderByteCode = nullptr;
	size_t shaderSize = 0;

	GraphicsEngine::GetInstance()->GetRenderSystem()->CompileVertexShaders(L"VertexShader.hlsl", "vsmain", &shaderByteCode, &shaderSize);

	this->vertexShader = GraphicsEngine::GetInstance()->GetRenderSystem()->CreateVertexShaders(shaderByteCode, shaderSize);
	this->vertexBuffer = GraphicsEngine::GetInstance()->GetRenderSystem()->CreateVertexBuffer(list, sizeof(vertex), listSize, shaderByteCode, shaderSize);

	GraphicsEngine::GetInstance()->GetRenderSystem()->ReleaseCompiledShader();

	GraphicsEngine::GetInstance()->GetRenderSystem()->CompilePixelShader(L"PixelShader.hlsl", "psmain", &shaderByteCode, &shaderSize);

	this->pixelShader = GraphicsEngine::GetInstance()->GetRenderSystem()->CreatePixelShader(shaderByteCode, shaderSize);

	GraphicsEngine::GetInstance()->GetRenderSystem()->ReleaseCompiledShader();

	constant cc;
	cc.angle = 0;

	this->constantBuffer = GraphicsEngine::GetInstance()->GetRenderSystem()->CreateConstantBuffer(&cc, sizeof(constant));
}

void Triangles::Draw()
{
	this->deltaTime = EngineTime::GetDeltaTime();

	this->angle += 1.57f * this->deltaTime ;
	constant cc;
	cc.angle = this->angle;

	this->constantBuffer->Update(GraphicsEngine::GetInstance()->GetRenderSystem()->GetImmediateDeviceContext(), &cc);

	GraphicsEngine::GetInstance()->GetRenderSystem()->GetImmediateDeviceContext()->SetConstantBuffer(this->vertexShader, this->constantBuffer);
	GraphicsEngine::GetInstance()->GetRenderSystem()->GetImmediateDeviceContext()->SetConstantBuffer(this->pixelShader, this->constantBuffer);

	//set default shader in graphics pipeline
	GraphicsEngine::GetInstance()->GetRenderSystem()->GetImmediateDeviceContext()->SetVertexShader(this->vertexShader);
	GraphicsEngine::GetInstance()->GetRenderSystem()->GetImmediateDeviceContext()->SetPixelShader(this->pixelShader);
	//Set vertices
	GraphicsEngine::GetInstance()->GetRenderSystem()->GetImmediateDeviceContext()->SetVertexBuffer(this->vertexBuffer);
	// Draw
	GraphicsEngine::GetInstance()->GetRenderSystem()->GetImmediateDeviceContext()->DrawTriangleStrip(this->vertexBuffer->GetVertexSizelist(), 0);
}

void Triangles::Release()
{
	//this->vertexBuffer->Release();
	//this->vertexShader->Release();
	//this->pixelShader->Release();
	//this->constantBuffer->Release();

}

Triangles::~Triangles()
{
}


