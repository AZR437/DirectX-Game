#include "EngineTime.h"

EngineTime* EngineTime::sharedInstance = NULL;

void EngineTime::Initialize()
{
	sharedInstance = new EngineTime();
}

double EngineTime::GetDeltaTime()
{
	return sharedInstance->deltaTime;
}

EngineTime::EngineTime()
{
}

EngineTime::~EngineTime()
{
}

void EngineTime::LogFrameStart()
{
	sharedInstance->start = std::chrono::system_clock::now();
}

void EngineTime::LogFrameEnd()
{
	sharedInstance->end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsedSeconds = sharedInstance->end - sharedInstance->start;

	sharedInstance->deltaTime = elapsedSeconds.count();

	//std::cout << "Frame Update finished" << sharedInstance->deltaTime << std::endl;
}
