#include "DeviceContext.h"
DeviceContext::DeviceContext(ID3D11DeviceContext* deviceContext)
{
	this->deviceContext = deviceContext;
}
void DeviceContext::ClearRenderTargetColor(SwapChain* swapChain, float r, float g, float b, float a)
{
	FLOAT clearColor[] = { r,g,b,a };
	this->deviceContext->ClearRenderTargetView(swapChain->renderTargetView ,clearColor);
	this->deviceContext->OMSetRenderTargets(1,&swapChain->renderTargetView, NULL);
	
}
void DeviceContext::SetVertexBuffer(VertexBuffer* vertexBuffer)
{
	UINT stride = vertexBuffer->sizeVertex;
	UINT offset = 0;
	this->deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer->buffer, &stride, &offset);

	this->deviceContext->IASetInputLayout(vertexBuffer->layout);
	
}
void DeviceContext::SetConstantBuffer(VertexShader* vertexShader, ConstantBuffer* constantBuffer)
{
	this->deviceContext->VSSetConstantBuffers(0, 1, &constantBuffer->buffer);

}
void DeviceContext::SetConstantBuffer(PixelShader* pixelShader, ConstantBuffer* constantBuffer)
{
	this->deviceContext->PSSetConstantBuffers(0, 1, &constantBuffer->buffer);
}
void DeviceContext::DrawTriangleList(UINT vertexCount, UINT vertexIndexStart)
{
	this->deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	this->deviceContext->Draw(vertexCount, vertexIndexStart);
}
void DeviceContext::DrawTriangleStrip(UINT vertexCount, UINT vertexIndexStart)
{
	this->deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	this->deviceContext->Draw(vertexCount, vertexIndexStart);
}
void DeviceContext::SetViewPortSize(UINT width, UINT height)
{
	D3D11_VIEWPORT vp = {};
	vp.Width = width;
	vp.Height = height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	this->deviceContext->RSSetViewports(1, &vp);
}
void DeviceContext::SetVertexShader(VertexShader* vertexShader)
{
	this->deviceContext->VSSetShader(vertexShader->vertexShader, nullptr, 0);
}
void DeviceContext::SetPixelShader(PixelShader* pixelShader)
{
	this->deviceContext->PSSetShader(pixelShader->pixelShader, nullptr, 0);
}
bool DeviceContext::Release()
{
	this->deviceContext->Release();
	delete this;
	return true;
}
DeviceContext::~DeviceContext()
{

}