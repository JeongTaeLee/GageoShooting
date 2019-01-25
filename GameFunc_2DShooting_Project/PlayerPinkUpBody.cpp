#include "DXUT.h"
#include "PlayerPinkUpBody.h"
#include "PlayerBullet.h"
#include "BulletInfo.h"

PlayerPinkUpBody::PlayerPinkUpBody()
{
	fDistance = 550.f;
	
	fAttackAccrue = 0.f;
	fAttackDelay = 0.1f;

	iTotalBullet = 90;
	iMaxTanchang = 30;
	iNowTanchang = 30;
}


PlayerPinkUpBody::~PlayerPinkUpBody()
{
}

void PlayerPinkUpBody::Init()
{
	transform->pos = Vector2(0.f, 0.f);
	renderer = AC(Renderer);
	animater = AC(Animater);

	animater->Add("WD", "PU02%d", "", 9, 9);
	animater->Add("WDL", "PU02%d", "", 10, 10);
	animater->Add("WL", "PU02%d", "", 11, 11);
	animater->Add("WUL", "PU02%d", "", 12, 12);
	animater->Add("WU", "PU02%d", "", 13, 13);
	animater->Add("WUR", "PU02%d", "", 14, 14);
	animater->Add("WR", "PU02%d", "", 15, 15);
	animater->Add("WDR", "PU02%d", "", 16, 16);
	animater->Play("WD");
	animater->SetDelay(0.01f);

	//renderer->SetMiddleCenter(Vector3(0.f, 35.f, 0.f));
	renderer->SetMiddleCenter();


	InitBulletInfo();
}

void PlayerPinkUpBody::Attack(const Vector2 & dir)
{
	if (KEYPRESS(VK_LBUTTON))
	{
		fAttackAccrue = 0.f;
	
		PlayerBullet * player = AddObj(PlayerBullet);
		player->transform->pos = transform->worldPos;
		player->SetBullet(lpMiniMapTex, dir, 5.f, 1000.f, fDistance);

		CAMERA.StartShake(5.f, 15.f);

		--iNowTanchang;
		lpBulletInfo->SetNowBulletInfo(iNowTanchang);
	}	
}
