#pragma once
#include "Windows.h"
#include "EngineTime.h"

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
		virtual void OnCreate() ;
		virtual void OnUpdate() ;
		virtual void OnDestroy();
		virtual void OnFocus() = 0;
		virtual void OnKillFocus() =0;
	protected:
		HWND hwnd;
		EngineTime engineTime;
		bool isRunning;
};

