#pragma once
#include "iostream"
#include "chrono"
#include "ctime"

class Window;
class EngineTime
{
private:
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	double deltaTime = 0.0;
	friend class Window;

public:
	static void Initialize();
	static double GetDeltaTime();
private:

	static void LogFrameStart();
	static void LogFrameEnd();
private:
	EngineTime();
	EngineTime(EngineTime const&) {};
	EngineTime& operator = (EngineTime const&) {}
	~EngineTime();
	static EngineTime* sharedInstance;

	



};

