#pragma once
#include "AUIScreen.h"
#include "IMGUI/imgui.h"
class UIManager;
class MenuBar;
class ColorPicker :public AUIScreen
{
public:
	bool GetActive();
	void SetActive(bool value);
	virtual void DrawUI() override;
private:
	ColorPicker(String name);
	~ColorPicker();


	friend class UIManager;
	friend class MenuBar;
	bool isActive;
	bool open;
	float colors[4] = {1,1,1,1};
};
