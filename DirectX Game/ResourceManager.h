#pragma once
#include "unordered_map"
#include "string"
#include "Resource.h"
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
private:
	std::unordered_map<std::wstring, Resource*> mapResources;
};

