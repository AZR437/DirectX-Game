#include "GraphicsEngine.h"
GraphicsEngine* GraphicsEngine::sharedInstance = NULL;

GraphicsEngine::GraphicsEngine()
{

}
GraphicsEngine::~GraphicsEngine()
{

}

bool GraphicsEngine::Release()
{
	this->renderSystem->Release();
	delete this->renderSystem;
	return true;

}

void GraphicsEngine::Initialize()
{
	sharedInstance = new GraphicsEngine();
	sharedInstance->renderSystem = new RenderSystem();
	sharedInstance->renderSystem->Init();

}

void GraphicsEngine::Destroy()
{
	if (sharedInstance != NULL)
	{
		sharedInstance->Release();
	}
}

GraphicsEngine* GraphicsEngine::GetInstance()
{
	return sharedInstance;
}

RenderSystem* GraphicsEngine::GetRenderSystem()
{
	return sharedInstance->renderSystem;
}


