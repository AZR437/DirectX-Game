#pragma onc
#include "Matrix4x4.h"
#include "InputSystem.h"
#include "Constants.h"
#include "EngineTime.h"
class Camera
{
public:
	Camera();
	void Update();
	void Release();
	~Camera();
public:
	Matrix4x4 GetView();
	Matrix4x4 GetProj();
	void SetWidthAndHeight(float width, float height);
	void SetPers(float fov, float aspect, float znear, float zfar);
	void SetOrtho(float width, float height, float nearPlane, float farPlane);
private:
	Matrix4x4 projection;
	Matrix4x4 transforms;
	float width = 0.f;
	float height = 0.f;
	float deltaTime = 0.f;
	float moveSpeed = 1.0f;
	float rotationX = 0.0f;
	float rotationY = 0.0f;
	Vector3D pos;
	Vector2D oldMousePos;


};

