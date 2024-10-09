#include "AppWindow.h"

int main()
{
	AppWindow::Initialize();
	AppWindow* appWindow = (AppWindow*)AppWindow::GetInstance();
	appWindow->Init();
	
	while (appWindow->IsRunning())
	{
		appWindow->Broadcast();
	}
	
	
	return 0;
}