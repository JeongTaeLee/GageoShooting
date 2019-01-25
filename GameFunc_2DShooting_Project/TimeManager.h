#pragma once
#include "singleton.h"
class TimeManager :
	public singleton<TimeManager>
{
private:
	float	fElapsed;
	bool	bTwo;
public:
	TimeManager();
	virtual ~TimeManager();

	float GetElapsed();
	void SetTwo(bool _bTwo);
};

#define TIME TimeManager::GetInst()
#define Et TIME.GetElapsed()
