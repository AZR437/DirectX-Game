#pragma once
#include "d3d11.h"
#include "d3dcompiler.h"
#include "RenderSystem.h"

#include "Prerequisite.h"

class GraphicsEngine
{
	
	public:
		
		//Initialize graphics engine & Dx11 Device
		//Release all resources loaded
		bool Release();

		
	public:
		static GraphicsEngine* GetInstance();
		static RenderSystem* GetRenderSystem();
		static void Initialize();
		static void Destroy();

	private: 
		RenderSystem* renderSystem = nullptr;
	private:
		GraphicsEngine();
		GraphicsEngine(GraphicsEngine const&);
		GraphicsEngine& operator = (GraphicsEngine const&) {};
		static GraphicsEngine* sharedInstance;
		~GraphicsEngine();
};

