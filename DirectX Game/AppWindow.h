#pragma once
#include "Window.h"
#include "Windows.h"
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "PrimitiveLoader.h"
#include "Constants.h"

class AppWindow: public Window
{
	public:
		static void Initialize();
		static AppWindow* GetInstance();

		virtual void OnCreate() override;
		virtual void OnUpdate() override;
		virtual void OnDestroy() override;

	private:
		SwapChain* swapChain;
		PrimitiveLoader* primitiveLoader;
	private:
		AppWindow();
		AppWindow(AppWindow const&);
		AppWindow& operator = (AppWindow const&) {};
		static AppWindow* sharedInstance;
		~AppWindow();

		
		
};

