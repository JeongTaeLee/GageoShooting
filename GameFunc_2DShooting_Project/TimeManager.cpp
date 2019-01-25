#include "DXUT.h"
#include "TimeManager.h"


TimeManager::TimeManager()
	:fElapsed(0.f), bTwo(false)
{
}


TimeManager::~TimeManager()
{
}

float TimeManager::GetElapsed()
{
	if (bTwo)
		return DXUTGetElapsedTime() * 2.f;

	return DXUTGetElapsedTime();
}

void TimeManager::SetTwo(bool _bTwo)
{
	bTwo = _bTwo;
}
