#include "Circle.h"

Circle::Circle()
{
}

Circle::Circle(float width, float height, Transforms transform)
{
	this->windowWidth = width;
	this->windowHeight = height;
	this->position = transform.position;
	this->scale = transform.scale;
	this->rotX = transform.rotation.x;
	this->rotY = transform.rotation.y;
	this->rotZ = transform.rotation.z;
}
//Circle::Circle(float width, float height, Vector3D start, Vector3D destination)
//{
//	this->windowWidth = width;
//	this->windowHeight = height;
//	this->source = start;
//	this->destination = destination;
//}
Circle::Circle(float width, float height)
{
	this->windowWidth = width;
	this->windowHeight = height;
	this->position = Vector3D(0, 0, 0);
	this->scale = Vector3D(1, 1, 1);;
	this->rotX = 0;
	this->rotY = 0;
	this->rotZ = 0;
}

void Circle::Load()
{

	int numSegments = 100;
	vertex list[sizeof(vertex)*10*3];
	float deltaTheta = 2.0f * 3.14159f / numSegments;
	float radius = 0.25f;
	for (int i = 0; i < numSegments;i++)
	{
		float theta = i* deltaTheta;
		int index = i * 3;
		vertex Vertice;
		Vertice.position.x = 0;
		Vertice.position.y = 0;
		Vertice.position.z = 0;
		Vertice.colour.x = 1.0f;
		Vertice.colour.y = 0.0f;
		Vertice.colour.z = 0.0f;
		Vertice.colour1.x = 0.0f;
		Vertice.colour1.y = 0.0f;
		Vertice.colour1.z = 1.0f;
		list[index + 0] = Vertice;
		Vertice.position.x = radius* cos(theta);
		Vertice.position.y =  radius *sin(theta);
		Vertice.position.z = 0;
		Vertice.colour.x = 1.0f;
		Vertice.colour.y = 0.0f;
		Vertice.colour.z = 0.0f;
		Vertice.colour1.x = 0.0f;
		Vertice.colour1.y = 0.0f;
		Vertice.colour1.z = 1.0f;
		list[index + 1] = Vertice;
		Vertice.position.x = radius * cos(theta + deltaTheta);
		Vertice.position.y = radius * sin(theta + deltaTheta);
		Vertice.position.z = 0;
		Vertice.colour.x = 1.0f;
		Vertice.colour.y = 0.0f;
		Vertice.colour.z = 0.0f;
		Vertice.colour1.x = 0.0f;
		Vertice.colour1.y = 0.0f;
		Vertice.colour1.z = 1.0f;
		list[index + 2] = Vertice;
		
	}
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


void Circle::Draw()
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

void Circle::Release()
{
	//this->vertexBuffer->Release();
	//this->vertexShader->Release();
	//this->pixelShader->Release();
	//this->constantBuffer->Release();
}

Circle::~Circle()
{

}

void Circle::updatePosition()
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
	cc.world.SetScale(Vector3D(1, 1, 1));

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
