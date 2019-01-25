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
	lpBackGround->AC(UIRenderer)->SetTex(LOADTEX("���ι�׶���", "./rs/MainManu/A2.png"), false);

	lpStartButton = AddObj(GameObject);
	lpAdviceButton01 = AddObj(GameObject);
	lpAdviceButton02 = AddObj(GameObject);
	lpGameExit = AddObj(GameObject);

	lpStartButton->AC(Button)->SetButton(LOADTEX("���ӽ���", "./rs/MainManu/���ӽ��۹�ư.png"), []() {SCENE.ChanScene("Ingame01"); }, Vector2(197, 335),
		Vector2(184, 48));
	lpAdviceButton01->AC(Button)->SetButton(LOADTEX("���ӹ��", "./rs/MainManu/���ӹ����ư.png"), []() {AddObj(PopUpScreen)->SetPopUp(LOADTEX("���ӹ����ũ��", "./rs/MainManu/���ӹ��.png")); }, Vector2(197, 415),
		Vector2(184, 48));
	lpAdviceButton02->AC(Button)->SetButton(LOADTEX("���Ӽ���", "./rs/MainManu/���Ӽ����ư.png"), []() {AddObj(PopUpScreen)->SetPopUp(LOADTEX("���Ӽ���ũ��", "./rs/MainManu/���Ӽ���.png")); }, Vector2(197, 494),
		Vector2(184, 48));
	lpGameExit->AC(Button)->SetButton(LOADTEX("��������", "./rs/MainManu/���������ư.png"), []() {PostQuitMessage(0); }, Vector2(197, 568),
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
