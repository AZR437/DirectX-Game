#pragma once
#include "RenderSystem.h"
#include "iostream"
#include "Prerequisite.h"

class VertexBuffer
{
	public:
		VertexBuffer(RenderSystem* renderSystem, void* listVertices, UINT sizeVertex, UINT sizeList, void* shaderByteCode, UINT sizeByteShader);
		~VertexBuffer();
	public:
		UINT GetVertexSizelist();
	private:
		UINT sizeVertex;
		UINT sizeList;
	private:
		ID3D11Buffer* buffer;
		ID3D11InputLayout* layout;
		RenderSystem* renderSystem = nullptr;
	private:
		friend class DeviceContext;
};

