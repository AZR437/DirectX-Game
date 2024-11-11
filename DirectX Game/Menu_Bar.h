#pragma once
#include "AUIScreen.h"
#include "IMGUI/imgui.h"
#include "UIManager.h"
class UIManager;
class Menu_Bar:public AUIScreen
{
private:
	Menu_Bar(String name);
	~Menu_Bar();

	virtual void DrawUI() override;
	friend class UIManager;

};

