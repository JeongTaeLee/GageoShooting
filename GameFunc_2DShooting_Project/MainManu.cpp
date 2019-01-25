#include "DXUT.h"
#include "MainManu.h"
#include "PopUpScreen.h"

MainManu::MainManu()
	:lpBackGround(nullptr), lp01(nullptr), lpStartButton(nullptr), lpAdviceButton01(nullptr), lpAdviceButton02(nullptr), lpGameExit(nullptr)
{
}


MainManu::~MainManu()
{
}

void MainManu::Init()
{

	SOUND.Play("ManuBGM", 1);


	lpBackGround = AddObj(GameObject);
	lpBackGround->transform->pos = Vector2(0, 0);
	lpBackGround->AC(UIRenderer)->SetTex(LOADTEX("메인백그라운드", "./rs/MainManu/A2.png"), false);

	lpStartButton = AddObj(GameObject);
	lpAdviceButton01 = AddObj(GameObject);
	lpAdviceButton02 = AddObj(GameObject);
	lpGameExit = AddObj(GameObject);

	lpStartButton->AC(Button)->SetButton(LOADTEX("게임시작", "./rs/MainManu/게임시작버튼.png"), []() {SCENE.ChanScene("Ingame01"); }, Vector2(197, 335),
		Vector2(184, 48));
	lpAdviceButton01->AC(Button)->SetButton(LOADTEX("게임방법", "./rs/MainManu/게임방법버튼.png"), []() {AddObj(PopUpScreen)->SetPopUp(LOADTEX("게임방법스크린", "./rs/MainManu/게임방법.png")); }, Vector2(197, 415),
		Vector2(184, 48));
	lpAdviceButton02->AC(Button)->SetButton(LOADTEX("게임설명", "./rs/MainManu/게임설명버튼.png"), []() {AddObj(PopUpScreen)->SetPopUp(LOADTEX("게임설명스크린", "./rs/MainManu/게임설명.png")); }, Vector2(197, 494),
		Vector2(184, 48));
	lpGameExit->AC(Button)->SetButton(LOADTEX("게임종료", "./rs/MainManu/게임종료버튼.png"), []() {PostQuitMessage(0); }, Vector2(197, 568),
		Vector2(184, 48));
}

void MainManu::Release()
{
	SOUND.Stop("ManuBGM");
	IMAGE.DeleteImages();
	OBJECT.Reset();
}

void MainManu::Update()
{
	CAMERA.Update();
	OBJECT.Update();
}

void MainManu::Render(LPD3DXSPRITE sprite)
{
	CAMERA.SetTransform();
	OBJECT.Render(sprite);
}
