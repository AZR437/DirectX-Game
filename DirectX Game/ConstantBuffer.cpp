#include "ConstantBuffer.h"

ConstantBuffer::ConstantBuffer():buffer(0)
{
}

bool ConstantBuffer::Load(void* buffer, UINT sizeBuffer)
{
	if (this->buffer)
	{
		this->buffer->Release();
	}

	D3D11_BUFFER_DESC buffDesc = {};
	buffDesc.Usage = D3D11_USAGE_DEFAULT;
	buffDesc.ByteWidth = sizeBuffer;
	buffDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	buffDesc.CPUAccessFlags = 0;
	buffDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = buffer;

	

	if (FAILED(GraphicsEngine::GetInstance()->d3dDevice->CreateBuffer(&buffDesc, &initData, &this->buffer)))
	{
		return false;
	}


	
    return true;
}

void ConstantBuffer::Update(DeviceContext* context, void* buffer)
{
	context->deviceContext->UpdateSubresource(this->buffer, NULL, NULL, buffer, NULL, NULL);
}

bool ConstantBuffer::Release()
{
	if (this->buffer)
	{
		this->buffer->Release();
	}
	delete this;
    return true;
}

ConstantBuffer::~ConstantBuffer()
{
}


