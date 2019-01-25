#include "DXUT.h"
#include "IntroScene.h"
#include "Intro.h"

IntroScene::IntroScene()
{
}


IntroScene::~IntroScene()
{
}

void IntroScene::Init()
{
	SOUND.Play("Intro", 1);

	AddObj(Intro);
}

void IntroScene::Release()
{
	SOUND.Stop("Intro");
	CAMERA.Reset();
	IMAGE.DeleteImages();
	OBJECT.Reset();
}

void IntroScene::Update()
{
	CAMERA.Update();
	OBJECT.Update();
}

void IntroScene::Render(LPD3DXSPRITE sprite)
{
	CAMERA.SetTransform();
	OBJECT.Render(sprite);
}

void IntroScene::ResourceLoading()
{
	LOADTEXS("Intro%d", "./rs/Intro/(%d).png", 1, 51);

	bLoadingComplete = true;
}
