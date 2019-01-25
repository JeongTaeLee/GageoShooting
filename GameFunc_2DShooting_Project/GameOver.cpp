#include "DXUT.h"
#include "GameOver.h"


GameOver::GameOver()
{
}


GameOver::~GameOver()
{
}

void GameOver::Init()
{
	GameObject * object = AddObj(GameObject);
	object->transform->pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	object->AddComponent<UIRenderer>()->SetTex(LOADTEX("GameOverScreen", " "));

}

void GameOver::Release()
{
	OBJECT.Reset();
	IMAGE.DeleteImages();
}

void GameOver::Update()
{
	if (KEYUP(VK_RETURN))
		SCENE.ChanScene("Ingame01");

	CAMERA.Update();
	OBJECT.Update();
}

void GameOver::Render(LPD3DXSPRITE sprite)
{
	OBJECT.Render(sprite);
	CAMERA.SetTransform();
}

void GameOver::ResourceLoading()
{
	LOADTEX("GameOverScreen", "./rs/GameOver.png");

	bLoadingComplete = true;
}
