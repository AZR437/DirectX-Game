#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(RenderSystem* renderSystem, void* listIndices, UINT sizeList):buffer(0), renderSystem(renderSystem)
{
	if (this->buffer)
	{
		this->buffer->Release();
	}

	D3D11_BUFFER_DESC buffDesc = {};
	buffDesc.Usage = D3D11_USAGE_DEFAULT;
	buffDesc.ByteWidth = 4 * sizeList;
	buffDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	buffDesc.CPUAccessFlags = 0;
	buffDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = listIndices;

	this->sizeList = sizeList;

	if (FAILED(renderSystem->d3dDevice->CreateBuffer(&buffDesc, &initData, &this->buffer)))
	{
		throw std::exception("Index buffer not created successfully.");
	}
}


IndexBuffer::~IndexBuffer()
{
	this->buffer->Release();
}

UINT IndexBuffer::GetIndexSizelist()
{
	return this->sizeList;
}
