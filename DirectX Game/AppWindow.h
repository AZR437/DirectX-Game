#pragma once
#include "Window.h"
#include "Windows.h"
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "PrimitiveLoader.h"
#include "Quad.h"
#include "Triangles.h"
#include "Constants.h"

class AppWindow: public Window
{
	public:
		AppWindow();
		~AppWindow();

		virtual void OnCreate() override;
		virtual void OnUpdate() override;
		virtual void OnDestroy() override;

	private:
		SwapChain* swapChain;
		PrimitiveLoader* primitiveLoader;
		std::vector<Quad> quadList;
		std::vector<Triangles> triList;

		
		
};

