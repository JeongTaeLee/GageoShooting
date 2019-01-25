#include "DXUT.h"
#include "GunCenterPop.h"
#include "Player.h"

#include "PlayerUpBody.h"
#include "PlayerPinkUpBody.h"
#include "PlayerBrownUpBody.h"

GunCenterPop::GunCenterPop()
	:lpUiRenderer(nullptr), lpButton01(nullptr), lpButton02(nullptr), lpButton03(nullptr)
{
	tag = "GunCenterPopUp";
}


GunCenterPop::~GunCenterPop()
{
}

void GunCenterPop::Init()
{
	transform->pos = Vector2(WINSIZEX / 2 - 375 / 2, WINSIZEY / 2 - 244 / 2);

	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetTex(LOADTEX("GunCenterPopUp", " "), false);

	GameObject * button;

	button = OBJECT.AddObject<GameObject>(nullptr, this);
	button->AC(Button)->SetButton(LOADTEX("Button01", " "), [&]() {Click01Button(); }, Vector2(80.f, 145.f), Vector2(71, 71));

	button = OBJECT.AddObject<GameObject>(nullptr, this);
	button->AC(Button)->SetButton(LOADTEX("Button02", " "), [&]() {Click02Button(); }, Vector2(194, 145.f), Vector2(71, 71));

	button = OBJECT.AddObject<GameObject>(nullptr, this);
	button->AC(Button)->SetButton(LOADTEX("Button03", " "), [&]() {Click03Button(); }, Vector2(309.f, 145.f), Vector2(71, 71));

	button = OBJECT.AddObject<GameObject>(nullptr, this);
	button->AC(Button)->SetButton(LOADTEX("XButton", " "), [&]() { ClickXButton(); }, Vector2(331, 22), Vector2(33, 33));
}

void GunCenterPop::Click01Button()
{
	Player * player = OBJECT.FindObject<Player>("Player");
	
	if (player->GetGold() < 200)
		return;
	
	player->ChangeGun(OBJECT.AddObject<PlayerUpBody>(nullptr, player));
	player->UsingGold(200);
	SetDestroy();
}

void GunCenterPop::Click02Button()
{
	Player * player = OBJECT.FindObject<Player>("Player");

	if (player->GetGold() < 300)
		return;

	player->ChangeGun(OBJECT.AddObject<PlayerPinkUpBody>(nullptr, player));
	player->UsingGold(300);
	SetDestroy();
}

void GunCenterPop::Click03Button()
{ 
	Player * player = OBJECT.FindObject<Player>("Player");

	if (player->GetGold() < 500)
		return;

	player->ChangeGun(OBJECT.AddObject<PlayerBrownUpBody>(nullptr, player));
	player->UsingGold(500);
	SetDestroy();
}

void GunCenterPop::ClickXButton()
{
	SetDestroy();
}
