#include "InputSystem.h"
InputSystem* InputSystem::sharedInstance = NULL;

InputSystem* InputSystem::GetInstance()
{
	return sharedInstance;
}

void InputSystem::Initialize()
{
	sharedInstance = new InputSystem();
}

void InputSystem::Destroy()
{

}

void InputSystem::Update()
{
	POINT currMousePos = {};
	::GetCursorPos(&currMousePos);
	if (this->firstTime)
	{
		this->oldMousePos = Vector2D(currMousePos.x, currMousePos.y);
		this->firstTime = false;
	}
	if (currMousePos.x != this->oldMousePos.x || currMousePos.y != this->oldMousePos.y)
	{
		float deltaX = currMousePos.x - this->oldMousePos.x;
		float deltaY = currMousePos.y != this->oldMousePos.y;
		// Mouse has moved
		std::unordered_set<InputListener*>::iterator it = this->setListeners.begin();
		while (it != this->setListeners.end()) {
			(*it)->OnMouseMove(Vector2D(deltaX, deltaY));
			++it;
		}
	}
	this->oldMousePos = Vector2D(currMousePos.x, currMousePos.y);

	if (::GetKeyboardState(this->keysState))
	{
		for (unsigned int i = 0; i < 256; i++)
		{
			//Down
			if (this->keysState[i] & 0x80)
			{
				std::unordered_set<InputListener*>::iterator it = this->setListeners.begin();
				while (it != this->setListeners.end()) 
				{
					if (i == VK_LBUTTON)
					{
						if (this->keysState[i] != this->oldKeysState[i])
							(*it)->OnLeftMouseDown(Vector2D(currMousePos.x, currMousePos.y));
					}
					else if (i == VK_RBUTTON)
					{
						if (this->keysState[i] != this->oldKeysState[i])
							(*it)->OnRightMouseDown(Vector2D(currMousePos.x, currMousePos.y));
					}
					else
						(*it)->OnKeyDown(i);

					++it;
				}

			}
			//UP
			else
			{
				if (this->keysState[i] != this->oldKeysState[i])
				{
					std::unordered_set<InputListener*>::iterator it = this->setListeners.begin();

					while (it != this->setListeners.end())
					{
						if (i == VK_LBUTTON)
							(*it)->OnLeftMouseRelease(Vector2D(currMousePos.x, currMousePos.y));
						else if (i == VK_RBUTTON)
							(*it)->OnRightMouseRelease(Vector2D(currMousePos.x, currMousePos.y));
						else
							(*it)->OnKeyRelease(i);

						++it;
					}
				}
			}
		}
		::memcpy(this->oldKeysState, this->keysState, sizeof(unsigned char));
	}
}

void InputSystem::AddListener(InputListener* listener)
{
	this->setListeners.insert(listener);
}

void InputSystem::RemoveListener(InputListener* listener)
{
	this->setListeners.erase(listener);
}

Vector2D InputSystem::GetCursorPosition()
{

	POINT currentCursorPos = {};
	::GetCursorPos(&currentCursorPos);
	Vector2D cursorPos = Vector2D(currentCursorPos.x, currentCursorPos.y);

	return cursorPos;
}

void InputSystem::SetCursorPosition(const float& x, const float& y)
{
	::SetCursorPos(x, y);
}

void InputSystem::SetCursorPosition(const Vector2D& position)
{
	::SetCursorPos(position.x, position.y);
}

bool InputSystem::IsKey(int key)
{
	bool isKey = false;
	if (this->keysState[key] & 0x80)
		isKey = true;

	return isKey;
}
bool InputSystem::IsKeyDown(int key)
{
	bool isKeyDown = false;
	if ((this->keysState[key] & 0x80) &&
		this->keysState[key] != this->oldKeysState[key])
		isKeyDown = true;

	return isKeyDown;
}

bool InputSystem::IsKeyUp(int key)
{
	bool isKeyDown = false;
	if (!(this->keysState[key] & 0x80) &&
		this->keysState[key] != this->oldKeysState[key])
		isKeyDown = true;

	return isKeyDown;
}

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}
