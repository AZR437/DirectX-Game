#pragma once
#include "GraphicsEngine.h"
#include "iostream"
class DeviceContext;

class IndexBuffer
{
public:
	IndexBuffer();
	bool Load(void* listIndices, UINT sizeList);
	bool Release();
	~IndexBuffer();
public:
	UINT GetIndexSizelist();
private:
	UINT sizeList;
private:
	ID3D11Buffer* buffer;
private:
	friend class DeviceContext;
};

