#pragma once
#include "Windows.h"

class Window
{
	public:
		Window();
		bool Init();
		bool Broadcast();
		bool Release();
		~Window();

		
		
		//getters/setters
		bool IsRunning();
		RECT GetClientWindowRect();
		void SetHWND(HWND hwnd);


		//EVENTS
		virtual void OnCreate();
		virtual void OnUpdate();
		virtual void OnDestroy();
	protected:
		HWND hwnd;
		bool isRunning;
};

