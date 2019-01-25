#pragma once
#include "singleton.h"
class InputManager :
	public singleton<InputManager>
{
private:
	bool bNowKey[256];
	bool bOldKey[256];
public:
	InputManager();
	virtual ~InputManager();

	void Update();

	bool GetKeyDown(int i) { return (bNowKey[i] && !bOldKey[i]); }
	bool GetKeyUp(int i) { return (!bNowKey[i] && bOldKey[i]); }
	bool GetKeyPress(int i) { return (bNowKey[i] && bOldKey[i]); }

	Vector2 GetMousePos();
	Vector2 GetScrollPos();

};

#define INPUT InputManager::GetInst()

#define MOUSEPOS INPUT.GetMousePos();
#define KEYDOWN(i) INPUT.GetKeyDown(i)
#define KEYUP(i) INPUT.GetKeyUp(i)
#define KEYPRESS(i) INPUT.GetKeyPress(i)