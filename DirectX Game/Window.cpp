#include "Window.h"
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
Window::Window()
{

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//Imgui Inputs
	if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam))
	{
		return true;
	}

	switch (msg)
	{
		case WM_CREATE:
		{
			//event fired when window is created
			//collect here
			Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
			//store for later
			SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
			window->SetHWND(hwnd);
			window->OnCreate();
			break;
		}
		case WM_SETFOCUS:
		{
			// event fired when window is focused
			Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
			window->OnFocus();
			break;
		}

		case WM_KILLFOCUS:
		{
			// event fired when window is focused
			Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
			window->OnKillFocus();
			break;
		}
			
		case WM_DESTROY:
		{
			// event fired when window is destroyed
			Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
			window->OnDestroy();
			::PostQuitMessage(0);
			break;
		}
		
			
		default:
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return NULL;
}
bool Window::Init()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"MyWindowClass";
	wc.lpszMenuName = L"";
	wc.style = NULL;
	wc.lpfnWndProc = WndProc;
	if (!::RegisterClassEx(&wc))
	{
		return false;
	}


	// create window
	hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"DirectX Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, UIManager::WINDOW_WIDTH, UIManager::WINDOW_HEIGHT,
		NULL, NULL, NULL, this);
	// creation fail catch
	if(!hwnd)
	{
		return false;
	}

	// show the window
	::ShowWindow(hwnd, SW_SHOW);
	::UpdateWindow(hwnd);

	//initialize EngineTime
	EngineTime::Initialize();

	//setting running flag to true
	this->isRunning = true;
	return true;
}

bool Window::Broadcast()
{
	EngineTime::LogFrameStart();
	this->OnUpdate();
	MSG msg;
	while(::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	Sleep(1);
	EngineTime::LogFrameEnd();

	return true;
}
bool Window::Release()
{
	//Window destruction
	if (!::DestroyWindow(hwnd))
	{
		return false;
	}
	return true;
}






void Window::OnCreate()
{
}

void Window::OnUpdate()
{
}

void Window::OnDestroy()
{
	this->isRunning = false;
}

Window::~Window()
{

}

#pragma region getters & setters
bool Window::IsRunning()
{
	return isRunning;
}
RECT Window::GetClientWindowRect()
{
	RECT rc;
	::GetClientRect(this->hwnd, &rc);
	return rc;
}
void Window::SetHWND(HWND hwnd)
{
	this->hwnd = hwnd;
}
#pragma endregion



