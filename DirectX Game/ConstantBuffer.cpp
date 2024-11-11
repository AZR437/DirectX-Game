#include "ConstantBuffer.h"

ConstantBuffer::ConstantBuffer(RenderSystem* renderSystem,void* buffer, UINT sizeBuffer):buffer(0),renderSystem(renderSystem)
{

	D3D11_BUFFER_DESC buffDesc = {};
	buffDesc.Usage = D3D11_USAGE_DEFAULT;
	buffDesc.ByteWidth = sizeBuffer;
	buffDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	buffDesc.CPUAccessFlags = 0;
	buffDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = buffer;



	if (FAILED(renderSystem->d3dDevice->CreateBuffer(&buffDesc, &initData, &this->buffer)))
	{
		throw std::exception("Constant Buffer not created successfully.");
	}

}


void ConstantBuffer::Update(DeviceContextPtr context, void* buffer)
{
	context->deviceContext->UpdateSubresource(this->buffer, NULL, NULL, buffer, NULL, NULL);
}



ConstantBuffer::~ConstantBuffer()
{
	if (this->buffer)
	{
		this->buffer->Release();
	}
}


