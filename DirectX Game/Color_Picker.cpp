#include "Color_Picker.h"

ColorPicker::ColorPicker(String name):AUIScreen(name)
{
	this->isActive = false;
	this->open = false;
	
}

ColorPicker::~ColorPicker()
{
}
bool ColorPicker::GetActive()
{
	return this->isActive;
}

void ColorPicker::SetActive(bool value)
{
	this->isActive = value;
}

void ColorPicker::DrawUI()
{
	if (this->isActive)
	{
		ImGui::Begin("Color Picker", &this->isActive);
		ImGui::SetNextWindowPos(ImVec2(1440 -400, 500));
		ImGui::SetWindowSize(ImVec2(1440 - 1140, 250));
		ImGui::ColorPicker4("###ColorWheel", this->colors, ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_PickerHueWheel);

		ImGui::End();

	}
}


