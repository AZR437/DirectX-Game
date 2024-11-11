#pragma once
#include "string"
#include "vector"
#include "unordered_map"
#include "AUIScreen.h"
#include "Windows.h"
#include "GraphicsEngine.h"
#include "IMGUI/imgui.h"
#include "IMGUI/imgui_impl_dx11.h"
#include "IMGUI/imgui_impl_win32.h"
#include "Menu_Bar.h"
#include "Credits_UI.h"
#include "Color_Picker.h"

class UINames 
{
public:
	const String PROFILE_SCREEN = "PROFILE_SCREEN";
	const String MENU_SCREEN = "MENU_SCREEN";
	const String CREDITS_SCREEN = "CREDITS_SCREEN";
	const String COLOR_PICKER = "COLOR_PICKER";
};
class UIManager
{
public:
	typedef std::string String;
	typedef std::vector<AUIScreen*> UIList;
	typedef std::unordered_map<String, AUIScreen*> UITable;

	static UIManager* GetInstance();
	static void Initialize(HWND windowHandle);
	void DrawAllUI();
	static void Destroy();
	std::unordered_map<String, AUIScreen*> GetUITable();
	
	static const int WINDOW_WIDTH = 1440;
	static const int WINDOW_HEIGHT = 900;
private:
	UIManager(HWND windowHandle);
	UIManager(UIManager const&) {};
	UIManager& operator=(UIManager const&) {};
	static UIManager* sharedInstance;
	~UIManager();

	UIList uiList;
	UITable uiTable;

};

