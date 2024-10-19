#pragma once
#include "Camera.h"
#include "vector"
class CameraManager
{
private:
	//std::vector<Camera*> cameras = {};
	Camera* selectedCamera = NULL;
	int currCameraNumber = 0;
public:
	static CameraManager* GetInstance();
	static void Initialize();
	void Update();
	void Release();

public:
	void CreateCamera();
	void IncrementCameras();
public:
	Camera* GetSelectedCamera();
private:
	CameraManager();
	CameraManager(CameraManager const&) {};
	CameraManager& operator=(CameraManager const&) {};
	static CameraManager* sharedInstance;
	~CameraManager();
};

