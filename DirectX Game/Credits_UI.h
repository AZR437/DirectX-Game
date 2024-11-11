#pragma once
#include "AUIScreen.h"
#include "IMGUI/imgui.h"
#include "d3d11.h"
#include "GraphicsEngine.h"
class UIManager;
class MenuBar;
class Credits_UI :public AUIScreen
{
public:
	bool GetActive();
	void SetActive(bool value);
	virtual void DrawUI() override;
private:
	Credits_UI(String name);
	~Credits_UI();
	bool LoadTextureFromFile(const char* file_name, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);
	bool LoadTextureFromMemory(const void* data, size_t data_size, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);

	friend class UIManager;
	friend class MenuBar;

	ID3D11ShaderResourceView* my_texture = NULL;
	int my_image_width = 0;
	int my_image_height = 0;
	bool isActive;
	bool open;
};

