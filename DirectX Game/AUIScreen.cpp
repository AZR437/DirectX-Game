#include "AUIScreen.h"
#include "iostream"
AUIScreen::AUIScreen(String name)
{
    this->name = name;
}

AUIScreen::~AUIScreen()
{
}

String AUIScreen::GetName()
{
    return this->name;
}


