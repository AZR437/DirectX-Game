#include "Cube.h"

Cube::Cube()
{
}

Cube::Cube(float width, float height)
{
	this->windowWidth = width;
	this->windowHeight = height;
	this->position = Vector3D(0,0,0);
	this->rotation = Vector3D(0,0,0);
	this->scale = Vector3D(0.25,0.25,0.25);
}

Cube::Cube(float width, float height, Transforms transformMatrices)
{
	this->windowWidth = width;
	this->windowHeight = height;
	this->position = transformMatrices.position;
	this->rotation = transformMatrices.rotation;
	this->scale = transformMatrices.scale;
}

void Cube::Load()
{
	vertex list[] =
	{
		//Front
		{ Vector3D(-0.5f,-0.5f, -0.5f),  Vector3D(0,0,0),  Vector3D(0,1,0) }, // POS1
		{ Vector3D(-0.5f, 0.5f, -0.5f),  Vector3D(1,1,0),  Vector3D(1,1,0) }, // POS2
		{ Vector3D( 0.5f,  0.5f, -0.5f), Vector3D(0,0,1),  Vector3D(1,0,0) },// POS2
		{ Vector3D( 0.5f, -0.5f, -0.5f), Vector3D(1,1,1),  Vector3D(0,0,1) },

		//Back
		{ Vector3D( 0.5f,-0.5f, 0.5f),   Vector3D(0,0,0),  Vector3D(0,1,0) }, // POS1
		{ Vector3D( 0.5f, 0.5f, 0.5f),   Vector3D(1,1,0),  Vector3D(1,1,0) }, // POS2
		{ Vector3D(-0.5f, 0.5f, 0.5f),  Vector3D(0,0,1),  Vector3D(1,0,0) },// POS2
		{ Vector3D(-0.5f,-0.5f, 0.5f), Vector3D(1,1,1),  Vector3D(0,0,1) },


	};
	
	this->vertexBuffer = GraphicsEngine::GetInstance()->CreateVertexBuffer();
	UINT listSize = ARRAYSIZE(list);

	unsigned indexList[] =
	{
		// Front
		0,1,2,
		2,3,0,
		//Back
		4,5,6,
		6,7,4,
		//Top
		1,6,5,
		5,2,1,
		//Bot
		7,0,3,
		3,4,7,
		//Right
		3,2,5,
		5,4,3,
		//Left
		7,6,1,
		1,0,7

	};

	this->indexBuffer = GraphicsEngine::GetInstance()->CreateIndexBuffer();
	UINT indexListSize = ARRAYSIZE(indexList);

	this->indexBuffer->Load(indexList, indexListSize);

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

void Cube::Draw()
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
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->SetIndexBuffer(this->indexBuffer);

	// Draw
	GraphicsEngine::GetInstance()->GetImmediateDeviceContext()->DrawIndexedTriangleList(this->indexBuffer->GetIndexSizelist(), 0, 0);
	
}

void Cube::Release()
{
	this->vertexBuffer->Release();
	this->indexBuffer->Release();
	this->constantBuffer->Release();
	this->vertexShader->Release();
	this->pixelShader->Release();
}

Cube::~Cube()
{
}

void Cube::updatePosition()
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
	temp.SetRotationZ(deltaScale);
	cc.world *= temp;

	temp.SetIdentity();
	temp.SetRotationY(deltaScale);
	cc.world *= temp;

	temp.SetIdentity();
	temp.SetRotationX(deltaScale);
	cc.world *= temp;

	temp.SetIdentity();
	temp.SetTranslate(this->position);
	cc.world *= temp;

	cc.view.SetIdentity();
	cc.projection.SetOrthoPM(this->windowWidth / 400.0f, this->windowHeight / 400.0f, -4.0f, 4.0f);

	this->constantBuffer->Update(GraphicsEngine::GetInstance()->GetImmediateDeviceContext(), &cc);
}
