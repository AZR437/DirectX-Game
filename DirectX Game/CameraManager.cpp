#include "CameraManager.h"
CameraManager* CameraManager::sharedInstance = NULL;
CameraManager::CameraManager()
{
}

CameraManager* CameraManager::GetInstance()
{
    return sharedInstance;
}

void CameraManager::Initialize()
{
    sharedInstance = new CameraManager();
    sharedInstance->CreateCamera();
    //sharedInstance->selectedCamera = sharedInstance->cameras[0];
}
void CameraManager::CreateCamera()
{
    //this->cameras.push_back(new Camera());
    this->selectedCamera = new Camera();
}
void CameraManager::IncrementCameras()
{
   /* this->currCameraNumber++;
    if (currCameraNumber >= this->cameras.size())
    {
        this->currCameraNumber = 0;
    }
    this->selectedCamera = this->cameras[this->currCameraNumber];*/
}
Camera* CameraManager::GetSelectedCamera()
{
    return this->selectedCamera;
}
void CameraManager::Update()
{
    this->selectedCamera->Update();
}

void CameraManager::Release()
{
    //this->selectedCamera = NULL;
   /* for (int i = 0; i < this->cameras.size(); i++)
    {
        this->cameras[i]->Release();
    }*/
    this->selectedCamera->Release();
}

CameraManager::~CameraManager()
{
}
