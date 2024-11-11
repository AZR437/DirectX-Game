#include "DeviceContext.h"
DeviceContext::DeviceContext(ID3D11DeviceContext* deviceContext, RenderSystem* renderSystem)
{
	this->deviceContext = deviceContext;
	this->renderSystem = renderSystem;
}
void DeviceContext::ClearRenderTargetColor(SwapChainPtr swapChain, float r, float g, float b, float a)
{
	FLOAT clearColor[] = { r,g,b,a };
	this->deviceContext->ClearRenderTargetView(swapChain->renderTargetView ,clearColor);
	this->deviceContext->ClearDepthStencilView(swapChain->depthView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1, 0);
	this->deviceContext->OMSetRenderTargets(1,&swapChain->renderTargetView, swapChain->depthView);
	//std::cout << "Bazinga" << std::endl;
	
}
void DeviceContext::SetVertexBuffer(VertexBufferPtr vertexBuffer)
{
	UINT stride = vertexBuffer->sizeVertex;
	UINT offset = 0;
	this->deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer->buffer, &stride, &offset);

	this->deviceContext->IASetInputLayout(vertexBuffer->layout);
	
}
void DeviceContext::SetIndexBuffer(IndexBufferPtr indexBuffer)
{
	this->deviceContext->IASetIndexBuffer(indexBuffer->buffer, DXGI_FORMAT_R32_UINT, 0);
}
void DeviceContext::SetConstantBuffer(VertexShaderPtr vertexShader, ConstantBufferPtr constantBuffer)
{
	this->deviceContext->VSSetConstantBuffers(0, 1, &constantBuffer->buffer);

}
void DeviceContext::SetConstantBuffer(PixelShaderPtr pixelShader, ConstantBufferPtr constantBuffer)
{
	this->deviceContext->PSSetConstantBuffers(0, 1, &constantBuffer->buffer);
}
void DeviceContext::DrawTriangleList(UINT vertexCount, UINT vertexIndexStart)
{
	this->deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	this->deviceContext->Draw(vertexCount, vertexIndexStart);
}
void DeviceContext::DrawIndexedTriangleList(UINT indexCount, UINT vertexIndexStart, UINT indexStartLocation)
{
	this->deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	this->deviceContext->DrawIndexed(indexCount, indexStartLocation, vertexIndexStart);
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
void DeviceContext::SetVertexShader(VertexShaderPtr vertexShader)
{
	this->deviceContext->VSSetShader(vertexShader->vertexShader, nullptr, 0);
}
void DeviceContext::SetPixelShader(PixelShaderPtr pixelShader)
{
	this->deviceContext->PSSetShader(pixelShader->pixelShader, nullptr, 0);
}
ID3D11DeviceContext* DeviceContext::GetDeviceContext()
{
	return this->deviceContext;
}
DeviceContext::~DeviceContext()
{
	this->deviceContext->Release();
}