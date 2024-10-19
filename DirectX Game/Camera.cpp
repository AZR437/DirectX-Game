#include "Camera.h"
Camera::Camera()
{
	this->pos = Vector3D(0, 0, -1);
}

void Camera::Update()
{
	this->deltaTime = EngineTime::GetDeltaTime();
	if (InputSystem::GetInstance()->IsKeyDown(VK_LBUTTON))
	{

		
	}
	if (InputSystem::GetInstance()->IsKey(VK_LBUTTON))
	{
		Vector2D mousePos = InputSystem::GetCursorPosition();
		InputSystem::SetCursorPosition(this->width / 2.0f, this->height / 2.0f);

		if (mousePos != this->oldMousePos)
		{
			this->rotationX += (mousePos.y - (this->height / 2.0f)) * this->deltaTime * 0.1f;
			this->rotationY += (mousePos.x - (this->width / 2.0f)) * this->deltaTime * 0.1f;
			this->oldMousePos = mousePos;
		}
	}
	if (InputSystem::GetInstance()->IsKey('W'))
	{
		std::cout << "W" << "\n";
		this->pos += this->transforms.GetForward() * this->moveSpeed * this->deltaTime ;
	}
	if (InputSystem::GetInstance()->IsKey('S'))
	{
		std::cout << "S" << "\n";
		this->pos -= this->transforms.GetForward() * this->moveSpeed * this->deltaTime;
	}
	if (InputSystem::GetInstance()->IsKey('D'))
	{
		std::cout << "D" << "\n";
		this->pos += this->transforms.GetRight() * this->moveSpeed * this->deltaTime;
	}
	if (InputSystem::GetInstance()->IsKey('A'))
	{
		std::cout << "A" << "\n";
		this->pos -= this->transforms.GetRight() * this->moveSpeed * this->deltaTime;
	}
	if (InputSystem::GetInstance()->IsKey('Q'))
	{
		std::cout << "Q" << "\n";
		this->pos.y +=  this->moveSpeed * this->deltaTime;
	}
	if (InputSystem::GetInstance()->IsKey('E'))
	{
		std::cout << "E" << "\n";
		this->pos.y -=  this->moveSpeed * this->deltaTime;
	}
	Matrix4x4 temp;
	this->transforms.SetIdentity();
	
	temp.SetIdentity();
	temp.SetRotationX(this->rotationX);
	this->transforms *= temp;

	temp.SetIdentity();
	temp.SetRotationY(this->rotationY);
	this->transforms *= temp;

	temp.SetTranslate(this->pos);
	this->transforms *= temp;
	
	this->transforms.Inverse();
}
void Camera::Release()
{
}
Camera::~Camera()
{
}

Matrix4x4 Camera::GetView()
{
	return this->transforms;
}

Matrix4x4 Camera::GetProj()
{
	return this->projection;
}

void Camera::SetWidthAndHeight(float width, float height)
{
	this->width = width;
	this->height = height;
}

void Camera::SetPers(float fov, float aspect, float znear, float zfar)
{
	this->projection.SetPerspectiveFovLH(fov, aspect, znear, zfar);
}

void Camera::SetOrtho(float width, float height, float nearPlane, float farPlane)
{
	this->projection.SetOrthoPM(width, height, nearPlane, farPlane);
}
