#pragma once
#include "Windows.h"
#include "InputListener.h"
#include "Vector2D.h"
#include "iostream"
#include "unordered_set"
class InputSystem
{
private:
private:
	std::unordered_set<InputListener*> setListeners;
	unsigned char keysState[256] = {};
	unsigned char oldKeysState[256] = {};
	Vector2D oldMousePos;
	bool firstTime = true;
	
public:
	static InputSystem* GetInstance();
	static void Initialize();
	static void Destroy();
	void Update();
	void AddListener(InputListener* listener);
	void RemoveListener(InputListener* listener);

	static Vector2D GetCursorPosition();
	static void SetCursorPosition(const float& x, const float& y);
	static void SetCursorPosition(const Vector2D& position);

	bool IsKey(int key);
	bool IsKeyDown(int key);
	bool IsKeyUp(int key);
private:
	InputSystem();;
	InputSystem(InputSystem const&);
	InputSystem& operator = (InputSystem const&) {};
	static InputSystem* sharedInstance;
	~InputSystem();
};

