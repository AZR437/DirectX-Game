#include "Quad.h"



Quad::Quad()
{
}

Quad::Quad(float width, float height)
{
	this->windowWidth = width;
	this->windowHeight = height;
}

Quad::Quad(float width, float height, Transforms transformMatrices)
{
	this->windowWidth = width;
	this->windowHeight = height;
	this->scale = scale;
	this->position = position;
	this->rotX = 0;
	this->rotY = 0;
	this->rotZ = 0;
}

void Quad::Load()
{
	vertex list[] =
	{

		{ Vector3D(-0.5f,-0.5f,0.0f), Vector3D(0,0,0),  Vector3D(0,1,0) }, // POS1
		{ Vector3D(-0.5f,0.5f,0.0f),  Vector3D(1,1,0),  Vector3D(1,1,0) }, // POS2
		{ Vector3D(0.5f,-0.5f,0.0f),  Vector3D(0,0,1),  Vector3D(1,0,0) },// POS2
		{ Vector3D(0.5f,0.5f,0.0f),   Vector3D(1,1,1),  Vector3D(0,0,1) }
	};
	UINT listSize = ARRAYSIZE(list);
	this->vertexBuffer = GraphicsEngine::GetInstance()->CreateVertexBuffer();

	GraphicsEngine::GetInstance()->CreateIndexBuffer();


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
	this->deltaTime = EngineTime::GetDeltaTime();

	this->angle += 1.57f * (this->deltaTime * this->multiplier);

	this->updatePosition();

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

void Quad::updatePosition()
{
	constant cc;
	cc.angle = this->angle;

	this->deltaPos += this->deltaTime * 0.25f;
	if (this->deltaPos > 1.0f)
	{
		this->deltaPos = 0;
	}
	
	Matrix4x4 temp;
	this->deltaScale += this->deltaTime * 1.f;
	//cc.world.SetTranslate(Vector3D(0, 0, 0));
	//cc.world.SetScale(Vector3D::Lerp(Vector3D(0.25, 0.25, 0), Vector3D(1, 1, 0), (sin(this->deltaScale) + 1.0f)/2));
	//temp.SetTranslate(Vector3D::Lerp(Vector3D(-1, -1, 0), Vector3D(1, 1, 0), deltaPos));
	//cc.world.SetScale();
	//cc.world *= temp;
	cc.world.SetScale(Vector3D(0.5, 0.5, 0.5));
	temp.SetIdentity();
	temp.SetRotationX(45*PI/180);
	cc.world *= temp;
	cc.view.SetIdentity();
	cc.projection.SetOrthoPM(this->windowWidth/400.0f, this->windowHeight/400.0f, -4.0f, 4.0f);

	this->constantBuffer->Update(GraphicsEngine::GetInstance()->GetImmediateDeviceContext(), &cc);
}



