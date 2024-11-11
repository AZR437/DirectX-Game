#pragma once
#include "RenderSystem.h"
#include "iostream"
#include "Prerequisite.h"
#include "exception"

class IndexBuffer
{
public:
	IndexBuffer(RenderSystem* renderSystem, void* listIndices, UINT sizeList);

	~IndexBuffer();
public:
	UINT GetIndexSizelist();
private:
	UINT sizeList;
private:
	ID3D11Buffer* buffer;
	RenderSystem* renderSystem = nullptr;
private:
	friend class DeviceContext;
};

