#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
}

bool IndexBuffer::Load(void* listIndices, UINT sizeList)
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

	if (FAILED(GraphicsEngine::GetInstance()->d3dDevice->CreateBuffer(&buffDesc, &initData, &this->buffer)))
	{
		return false;
	}

	return true;
}

bool IndexBuffer::Release()
{
	this->buffer->Release();
	delete this;
	return true;
}

IndexBuffer::~IndexBuffer()
{
}

UINT IndexBuffer::GetIndexSizelist()
{
	return this->sizeList;
}
