#include "DXUT.h"
#include "GameVictory.h"
#include "VictoryEnding.h"
GameVictory::GameVictory()
{
}


GameVictory::~GameVictory()
{
}

void GameVictory::Init()
{
	SOUND.Play("ManuBGM", 1);
	AddObj(VictoryEnding);
}

void GameVictory::Release()
{
	SOUND.Stop("ManuBGM");
	OBJECT.Reset();
	IMAGE.DeleteImages();
}

void GameVictory::Update()
{
	if (KEYUP(VK_RETURN))
		SCENE.ChanScene("MainManu");

	CAMERA.Update();
	OBJECT.Update();
}

void GameVictory::Render(LPD3DXSPRITE sprite)
{
	CAMERA.SetTransform();
	OBJECT.Render(sprite);
}

void GameVictory::ResourceLoading()
{
	LOADTEXS("Ending%d", "./rs/Ending/(%d).png", 1, 50);

	bLoadingComplete = true;
}
