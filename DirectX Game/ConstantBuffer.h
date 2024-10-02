#pragma once
#include "GraphicsEngine.h"
#include "DeviceContext.h"

class DeviceContext;

class ConstantBuffer
{
public:
	ConstantBuffer();
	bool Load(void* buffer, UINT sizeBuffer);
	void Update(DeviceContext* context, void* buffer);
	bool Release();
	~ConstantBuffer();
private:
	ID3D11Buffer* buffer;
private:
	friend class DeviceContext;
};

