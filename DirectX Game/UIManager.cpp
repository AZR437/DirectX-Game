#include "UIManager.h"
UIManager* UIManager::sharedInstance = NULL;
UIManager* UIManager::GetInstance()
{
    return sharedInstance;
}

void UIManager::Initialize(HWND windowHandle)
{
    sharedInstance = new UIManager(windowHandle);
}

void UIManager::DrawAllUI()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	for (int i = 0; i < this->uiList.size(); i++)
	{
		this->uiList[i]->DrawUI();
	}
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void UIManager::Destroy()
{
}

std::unordered_map<String, AUIScreen*> UIManager::GetUITable()
{
	return this->uiTable;
}

UIManager::UIManager(HWND windowHandle)
{
	ImGui::CreateContext();
	ImGui_ImplWin32_Init(windowHandle);
	ImGui_ImplDX11_Init(GraphicsEngine::GetInstance()->GetRenderSystem()->GetDirectXDevice(), GraphicsEngine::GetInstance()->GetRenderSystem()->GetImmediateDeviceContext()->GetDeviceContext());

	UINames uiNames;
	Menu_Bar* menuBar = new Menu_Bar(uiNames.MENU_SCREEN);
	this->uiTable[uiNames.MENU_SCREEN] = menuBar;
	uiList.push_back(menuBar);

	Credits_UI* credits = new Credits_UI(uiNames.CREDITS_SCREEN);
	this->uiTable[uiNames.CREDITS_SCREEN] = credits;
	uiList.push_back(credits);

	ColorPicker* colorPicker = new ColorPicker(uiNames.COLOR_PICKER);
	this->uiTable[uiNames.COLOR_PICKER] = colorPicker;
	uiList.push_back(colorPicker);
}

UIManager::~UIManager()
{
}
