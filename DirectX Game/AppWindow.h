#pragma once
#include "Window.h"
#include "Windows.h"
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "PrimitiveLoader.h"
#include "InputListener.h"
#include "InputSystem.h"
#include "Constants.h"
#include "CameraManager.h"
#include "IMGUI/imgui.h"
#include "IMGUI/imgui_impl_dx11.h"
#include "IMGUI/imgui_impl_win32.h"
class AppWindow: public Window, public InputListener
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
		// Inherited via InputListener
		void OnKeyDown(int key) override;

		void OnKeyRelease(int key) override;

		
		

		// Inherited via InputListener
		void OnMouseMove(const Vector2D& deltaMousePos) override;


		// Inherited via Window
		void OnFocus() override;

		void OnKillFocus() override;


		// Inherited via InputListener
		void OnLeftMouseDown(const Vector2D& mousePos) override;

		void OnLeftMouseRelease(const Vector2D& mousePos) override;

		void OnRightMouseDown(const Vector2D& mousePos) override;

		void OnRightMouseRelease(const Vector2D& mousePos) override;

};

