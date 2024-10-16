#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(): layout(0), buffer(0)
{
}

bool VertexBuffer::Load(void* listVertices, UINT sizeVertex, UINT sizeList, void* shaderByteCode, UINT sizeByteShader)
{
	if (this->buffer)
	{
		this->buffer->Release();
	}
	if (this->layout)
	{
		this->layout->Release();
	}
	D3D11_BUFFER_DESC buffDesc = {};
	buffDesc.Usage = D3D11_USAGE_DEFAULT;
	buffDesc.ByteWidth = sizeVertex * sizeList;
	buffDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	buffDesc.CPUAccessFlags = 0;
	buffDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = listVertices;

	this->sizeVertex = sizeVertex;
	this->sizeList = sizeList;

	if (FAILED(GraphicsEngine::GetInstance()->d3dDevice->CreateBuffer(&buffDesc, &initData, &this->buffer)))
	{
		return false;
	}
	

	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		//Semantic Name - Semantic Format - Input Slot - Aligned Byte Offset - Input Slot Class - Instance Step Rate
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA,0},
		{"COLOUR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA,0},
		{"COLOUR", 1, DXGI_FORMAT_R32G32B32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA,0}
	};
	UINT sizeLayout = ARRAYSIZE(layout);
	if (FAILED(GraphicsEngine::GetInstance()->d3dDevice->CreateInputLayout(layout, sizeLayout, shaderByteCode, sizeByteShader, &this->layout)))
	{
		return false;
	}
	return true;
}



bool VertexBuffer::Release()
{
	this->layout->Release();
	this->buffer->Release();
	delete this;
	return true;
}

VertexBuffer::~VertexBuffer()
{
}

UINT VertexBuffer::GetVertexSizelist()
{
	return this->sizeList;
}