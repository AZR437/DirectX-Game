#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(RenderSystem* renderSystem, void* listVertices,
	UINT sizeVertex, UINT sizeList, void* shaderByteCode, UINT sizeByteShader) : 
	layout(0), buffer(0), renderSystem(renderSystem), sizeList(0), sizeVertex(0)
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

	if (FAILED(renderSystem->d3dDevice->CreateBuffer(&buffDesc, &initData, &this->buffer)))
	{
		throw std::exception("Vertex buffer was not created successfully.");
	}


	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		//Semantic Name - Semantic Format - Input Slot - Aligned Byte Offset - Input Slot Class - Instance Step Rate
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA,0},
		{"COLOUR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA,0},
		{"COLOUR", 1, DXGI_FORMAT_R32G32B32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA,0}
	};
	UINT sizeLayout = ARRAYSIZE(layout);
	if (FAILED(renderSystem->d3dDevice->CreateInputLayout(layout, sizeLayout, shaderByteCode, sizeByteShader, &this->layout)))
	{
		throw std::exception("Input Layout was not created successfully.");
	}
}

VertexBuffer::~VertexBuffer()
{
	this->layout->Release();
	this->buffer->Release();
}

UINT VertexBuffer::GetVertexSizelist()
{
	return this->sizeList;
}