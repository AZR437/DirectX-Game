#include "AppWindow.h"
#include "Credits_UI.h"

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