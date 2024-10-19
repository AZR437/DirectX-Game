#pragma once
#include "Vector2D.h"
class InputListener
{
public:
	InputListener()
	{}
	~InputListener()
	{}

	//Keyboard
	virtual void OnKeyDown(int key) = 0;
	virtual void OnKeyRelease(int key) = 0;
	// mouse
	virtual void OnMouseMove(const Vector2D& deltaMousePos) = 0;
	virtual void OnLeftMouseDown(const Vector2D& mousePos) = 0;
	virtual void OnLeftMouseRelease(const Vector2D& mousePos) = 0;
	virtual void OnRightMouseDown(const Vector2D& mousePos) = 0;
	virtual void OnRightMouseRelease(const Vector2D& mousePos) = 0;
};