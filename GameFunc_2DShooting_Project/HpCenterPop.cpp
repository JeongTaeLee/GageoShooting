#include "DXUT.h"
#include "HpCenterPop.h"
#include "Player.h"

HpCenterPop::HpCenterPop()
	:lpUiRenderer(nullptr), lpXButton(nullptr), lpOkButton(nullptr)
{
	tag = "HpCenterPopUp";
}


HpCenterPop::~HpCenterPop()
{
}

void HpCenterPop::Init()
{
	transform->pos = Vector2(WINSIZEX / 2 - 171, WINSIZEY / 2 - 83);

	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetTex(LOADTEX("HpCenterPopup", " "), false);	

	lpOkButton = OBJECT.AddObject<GameObject>(nullptr, this);
	lpOkButton->AC(Button)->SetButton(LOADTEX("OkButton", " "), [&]() {ClickOkButton(); }, Vector2(170, 126), Vector2(81, 35));

	lpXButton = OBJECT.AddObject<GameObject>(nullptr, this);
	lpXButton->AC(Button)->SetButton(LOADTEX("XButton", " "), [&]() { ClickXButton(); }, Vector2(331, 22), Vector2(33, 33));
}

void HpCenterPop::ClickXButton()
{
	SetDestroy();
}

void HpCenterPop::ClickOkButton()
{
	Player * player = OBJECT.FindObject<Player>("Player");

	if (player->GetGold() < 200)
		return;

	player->UsingGold(200);

	player->ReHp();

	SetDestroy();
}
