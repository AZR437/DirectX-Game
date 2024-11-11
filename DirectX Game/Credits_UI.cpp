#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#include "Credits_UI.h"
#include "iostream"
#include "stb_image.h"
Credits_UI::Credits_UI(String name):AUIScreen(name)
{
	this->isActive = false;
	this->open = false;

  
    bool ret = LoadTextureFromFile("../Image/Snek.png", &this->my_texture, &this->my_image_width, &this->my_image_height);
    std::cout << ret << std::endl;
}

Credits_UI::~Credits_UI()
{
}

bool Credits_UI::LoadTextureFromFile(const char* file_name, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height)
{
	FILE* f = fopen(file_name, "rb");
	if (f == NULL)
		return false;
	fseek(f, 0, SEEK_END);
	size_t file_size = (size_t)ftell(f);
	if (file_size == -1)
		return false;
	fseek(f, 0, SEEK_SET);
	void* file_data = IM_ALLOC(file_size);
	fread(file_data, 1, file_size, f);
	bool ret = LoadTextureFromMemory(file_data, file_size, out_srv, out_width, out_height);
	IM_FREE(file_data);
	return ret;
}

bool Credits_UI::LoadTextureFromMemory(const void* data, size_t data_size, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height)
{
    // Load from disk into a raw RGBA buffer
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load_from_memory((const unsigned char*)data, (int)data_size, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create texture
    D3D11_TEXTURE2D_DESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.Width = image_width;
    desc.Height = image_height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;

    ID3D11Texture2D* pTexture = NULL;
    D3D11_SUBRESOURCE_DATA subResource;
    subResource.pSysMem = image_data;
    subResource.SysMemPitch = desc.Width * 4;
    subResource.SysMemSlicePitch = 0;
    GraphicsEngine::GetInstance()->GetRenderSystem()->GetDirectXDevice()->CreateTexture2D(&desc, &subResource, &pTexture);

    // Create texture view
    D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
    ZeroMemory(&srvDesc, sizeof(srvDesc));
    srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels = desc.MipLevels;
    srvDesc.Texture2D.MostDetailedMip = 0;
    GraphicsEngine::GetInstance()->GetRenderSystem()->GetDirectXDevice()->CreateShaderResourceView(pTexture, &srvDesc, out_srv);
    pTexture->Release();

    *out_width = image_width;
    *out_height = image_height;
    stbi_image_free(image_data);

    return true;
}


void Credits_UI::DrawUI()
{
	if (this->isActive)
	{
		ImGui::Begin("Credits", &this->isActive);
		ImGui::SetWindowSize(ImVec2(1440 - 1140, 400));
		ImGui::SetNextWindowPos(ImVec2(200, 400));
        ImGui::Image((ImTextureID)(intptr_t)this->my_texture, ImVec2(this->my_image_width, this->my_image_height));
		ImGui::TextColored(ImVec4(1, 0, 0, 1), "About:");
		ImGui::TextColored(ImVec4(1, 1, 1, 1), "Developed by: Carlos Miguel M. Arquillo");
		ImGui::TextColored(ImVec4(1, 1, 1, 1), "Version Number: 0.47");
		ImGui::TextColored(ImVec4(1, 0, 0, 1), "Acknowledgements:");
		ImGui::TextColored(ImVec4(1, 1, 1, 1), "PardCode Youtube Tutorials");
		ImGui::TextColored(ImVec4(1, 1, 1, 1), "AMD for the Processing power");
		ImGui::TextColored(ImVec4(1, 1, 1, 1), "Lenovo for the laptop");
		ImGui::TextColored(ImVec4(1, 1, 1, 1), "My Parents for paying for my education");
		ImGui::End();
	}
}
bool Credits_UI::GetActive()
{
	return this->isActive;
}
void Credits_UI::SetActive(bool value)
{
	std::cout << "enter" << std::endl;
	this->isActive = value;
}
