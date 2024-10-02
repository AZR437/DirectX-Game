#pragma once
#include "GraphicsEngine.h"
#include "iostream"
class DeviceContext;

class VertexBuffer
{
	public:
		VertexBuffer();
		bool Load(void* listVertices, UINT sizeVertex, UINT sizeList, void* shaderByteCode, UINT sizeByteShader);
		bool Release();
		~VertexBuffer();
	public:
		UINT GetVertexSizelist();
	private:
		UINT sizeVertex;
		UINT sizeList;
	private:
		ID3D11Buffer* buffer;
		ID3D11InputLayout* layout;
	private:
		friend class DeviceContext;
};

