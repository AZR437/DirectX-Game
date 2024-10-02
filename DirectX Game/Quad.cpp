#include "Quad.h"



Quad::Quad()
{
}

Quad::Quad(float x, float y, float scale)
{
	this->position.x = x;
	this->position.y = y;
	this->scale = scale;
}

void Quad::Load()
{
	vertex list[] =
	{
		//X - Y - Z
		{-0.5f,-0.5f,0.0f,    -0.32f,-0.11f,0.0f,   1,0,0,  0,0,1 }, // POS1
		{-0.5f,0.5f,0.0f,     -0.11f,0.78f,0.0f,    1,0,0,  0,0,1 }, // POS2
		{ 0.5f,-0.5f,0.0f,     0.75f,-0.73f,0.0f,   1,0,0,  0,0,1 },// POS2
		{ 0.5f,0.5f,0.0f,      0.88f,0.77f,0.0f,    1,0,0,  0,0,1 }
	};
	UINT listSize = ARRAYSIZE(list);
	this->vertexBuffer = GraphicsEngine::GetInstance()->CreateVertexBuffer();

	
	this->Translate(list, listSize);
	this->Scale(list, listSize);

	void* shaderByteCode = nullptr;
	size_t shaderSize = 0;

	GraphicsEngine::GetInstance()->CompileVertexShaders(L"VertexShader.hlsl", "vsmain", &shaderByteCode, &shaderSize);

	this->vertexShader = GraphicsEngine::GetInstance()->CreateVertexShaders(shaderByteCode, shaderSize);

	this->vertexBuffer->Load(list, sizeof(vertex), listSize, shaderByteCode, shaderSize);

	GraphicsEngine::GetInstance()->ReleaseCompiledShader();

	GraphicsEngine::GetInstance()->CompilePixelShader(L"PixelShader.hlsl", "psmain", &shaderByteCode, &shaderSize);

	this->pixelShader = GraphicsEngine::GetInstance()->CreatePixelShader(shaderByteCode, shaderSize);

	GraphicsEngine::GetInstance()->ReleaseCompiledShader();

	constant cc;
	cc.angle = 0;

	this->constantBuffer = GraphicsEngine::GetInstance()->CreateConstantBuffer();
	this->constantBuffer->Load(&cc, sizeof(constant));
}

void Quad::Draw()
{
	unsigned long newTime = 0;
	if (this->oldTime)
		newTime = ::GetTickCount() - this->oldTime;
	this->deltaTime = newTime / 1000.0f;
	this->oldTime = ::GetTickCount();

	this->angle += 1.57f * this->deltaTime;
	constant cc;
	cc.angle = this->angle;
	
	this->constantBuffer->Update(GraphicsEngine::GetInstance()->GetImmediateDeviceContext(), &cc);

	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetConstantBuffer(this->vertexShader, this->constantBuffer);
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetConstantBuffer(this->pixelShader, this->constantBuffer);

	//set default shader in graphics pipeline
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetVertexShader(this->vertexShader);
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetPixelShader(this->pixelShader);
	//Set vertices
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetVertexBuffer(this->vertexBuffer);
	// Draw
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->DrawTriangleStrip(this->vertexBuffer->GetVertexSizelist(), 0);
}

void Quad::Release()
{
	this->vertexBuffer->Release();
	this->vertexShader->Release();
	this->pixelShader->Release();
	this->constantBuffer->Release();
	
}

Quad::~Quad()
{
}

void Quad::Translate(vertex list[4], UINT listSize)
{
	for (UINT i = 0; i < listSize; i++)
	{
		list[i].position.x += this->position.x;
		list[i].position.y += this->position.y;
	}

}

void Quad::Scale(vertex list[4], UINT listSize)
{
	for (UINT i = 0; i < listSize; i++)
	{
		list[i].position.x *= this->scale;
		list[i].position.y *= this->scale;
	}
}
