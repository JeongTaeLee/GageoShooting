#include "DXUT.h"
#include "GameFailed.h"
#include "GameFailedScreen.h"

GameFailed::GameFailed()
{
}


GameFailed::~GameFailed()
{
}

void GameFailed::Init()
{
	SOUND.Play("Failed",1);
	AddObj(GameFailedScreen);
}

void GameFailed::Release()
{
	SOUND.Stop("Failed");
	CAMERA.Reset();
	OBJECT.Reset();
	IMAGE.DeleteImages();
}

void GameFailed::Update()
{
	if (KEYUP(VK_RETURN))
		SCENE.ChanScene("MainManu");
	CAMERA.Update();
	OBJECT.Update();
}

void GameFailed::Render(LPD3DXSPRITE sprite)
{
	CAMERA.SetTransform();
	OBJECT.Render(sprite);
}

void GameFailed::ResourceLoading()
{

	bLoadingComplete = true;
}
