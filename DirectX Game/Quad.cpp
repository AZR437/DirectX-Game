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
	this->scale = transformMatrices.scale;
	this->position = transformMatrices.position;
	this->rotX = transformMatrices.rotation.x;
	this->rotY = transformMatrices.rotation.y;
	this->rotZ = transformMatrices.rotation.z;
}

void Quad::Load()
{
	vertex list[] =
	{

		{ Vector3D(-0.5f,-0.5f,0.0f), Vector3D(1,1,1),  Vector3D(1,1,1) }, // POS1
		{ Vector3D(-0.5f,0.5f,0.0f),  Vector3D(1,1,1),  Vector3D(1,1,1) }, // POS2
		{ Vector3D(0.5f,-0.5f,0.0f),  Vector3D(1,1,1),  Vector3D(1,1,1) },// POS2
		{ Vector3D(0.5f,0.5f,0.0f),   Vector3D(1,1,1),  Vector3D(1,1,1) }
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

void Quad::Draw()
{
	this->deltaTime = EngineTime::GetDeltaTime();

	this->angle += 1.57f * (this->deltaTime * this->multiplier);

	this->updatePosition();

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

void Quad::Release()
{
	//this->vertexBuffer->Release();
	//this->vertexShader->Release();
	//this->pixelShader->Release();
	//this->constantBuffer->Release();
	
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
	//cc.world.SetScale(Vector3D::Lerp(Vector3D(0.25, 0.25, 0), Vector3D(1, 1, 0), (sin(this->deltaScale) + 1.0f) / 2));
	//temp.SetTranslate(Vector3D::Lerp(Vector3D(-1, -1, 0), Vector3D(1, 1, 0), deltaPos));
	//cc.world.SetScale();
	cc.world.SetScale(this->scale);

	temp.SetIdentity();
	temp.SetRotationZ(this->rotZ * (PI / 180));
	cc.world *= temp;

	temp.SetIdentity();
	temp.SetRotationY(this->rotY * (PI / 180));
	cc.world *= temp;

	temp.SetIdentity();
	temp.SetRotationX(this->rotX * (PI / 180));
	cc.world *= temp;

	temp.SetIdentity();
	temp.SetTranslate(this->position);
	cc.world *= temp;

	cc.view = CameraManager::GetInstance()->GetSelectedCamera()->GetView();
	cc.projection = CameraManager::GetInstance()->GetSelectedCamera()->GetProj();;

	this->constantBuffer->Update(GraphicsEngine::GetInstance()->GetRenderSystem()->GetImmediateDeviceContext(), &cc);
}



