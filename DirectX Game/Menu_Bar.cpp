#include "Menu_Bar.h"
#include "iostream"
Menu_Bar::Menu_Bar(String name):AUIScreen(name)
{

}

Menu_Bar::~Menu_Bar()
{
}

void Menu_Bar::DrawUI()
{
    if (ImGui::BeginMainMenuBar()) 
    {
        if (ImGui::BeginMenu("File")) 
        {
            if (ImGui::MenuItem("Create")) 
            {
              
            }
            if (ImGui::MenuItem("Open", "Ctrl+O")) 
            {
            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) 
            {
            }
            if (ImGui::MenuItem("Save as..")) 
            {
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("About"))
        {
            if (ImGui::MenuItem("Credits"))
            {
                std::cout << UIManager::GetInstance()->GetUITable().at("CREDITS_SCREEN")->GetName() << std::endl;
                if (!((Credits_UI*)UIManager::GetInstance()->GetUITable().at("CREDITS_SCREEN"))->GetActive())
                {
                    ((Credits_UI*)UIManager::GetInstance()->GetUITable().at("CREDITS_SCREEN"))->SetActive(true);
                    ((Credits_UI*)UIManager::GetInstance()->GetUITable().at("CREDITS_SCREEN"))->DrawUI();
                }
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Additional UI"))
        {
            if (ImGui::MenuItem("Color Picker"))
            {
                std::cout << UIManager::GetInstance()->GetUITable().at("COLOR_PICKER")->GetName() << std::endl;
                if (!((Credits_UI*)UIManager::GetInstance()->GetUITable().at("COLOR_PICKER"))->GetActive())
                {
                    ((Credits_UI*)UIManager::GetInstance()->GetUITable().at("COLOR_PICKER"))->SetActive(true);
                    ((Credits_UI*)UIManager::GetInstance()->GetUITable().at("COLOR_PICKER"))->DrawUI();
                }
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
   
    }
    //ImGui::ShowDemoWindow();
}
