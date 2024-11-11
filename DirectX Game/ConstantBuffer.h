#pragma once
#include "RenderSystem.h"
#include "DeviceContext.h"
#include "Prerequisite.h"
#include "exception"

class ConstantBuffer
{
public:
	ConstantBuffer(RenderSystem* renderSystem, void* buffer, UINT sizeBuffer);
	void Update(DeviceContext* context, void* buffer);
	~ConstantBuffer();
private:
	ID3D11Buffer* buffer;
	RenderSystem* renderSystem = nullptr;
private:
	friend class DeviceContext;
};

