#include "DXUT.h"
#include "InputManager.h"


InputManager::InputManager()
{
	memset(bNowKey, false, sizeof(bool) * 256);
	memset(bOldKey, false, sizeof(bool) * 256);
}


InputManager::~InputManager()
{
}

void InputManager::Update()
{
	memcpy(bOldKey, bNowKey, sizeof(bool) * 256);
	memset(bNowKey, false, sizeof(bool) * 256);

	for (int i = 0; i < 256; ++i)
		bNowKey[i] = GetAsyncKeyState(i);

}

Vector2 InputManager::GetMousePos()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	POINT pt = { 0 };
	GetCursorPos(&pt);
	ScreenToClient(DXUTGetHWND(), &pt);
	Vector2 vMousePos = Vector2((float)pt.x, (float)pt.y);

	return vMousePos;
}

Vector2 InputManager::GetScrollPos()
{
	Vector2 vScrollPos = GetMousePos() + CAMERA.GetScroll();

	return GetMousePos() + CAMERA.GetScroll();
}
