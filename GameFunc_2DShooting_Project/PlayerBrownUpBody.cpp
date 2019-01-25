#include "DXUT.h"
#include "PlayerBrownUpBody.h"
#include "BulletInfo.h"
#include "PlayerBullet.h"

PlayerBrownUpBody::PlayerBrownUpBody()
{
	fDistance = 400.f;
	

	iTotalBullet = 45;
	iNowTanchang = 7;
	iMaxTanchang = 7;
}


PlayerBrownUpBody::~PlayerBrownUpBody()
{
}

void PlayerBrownUpBody::Init()
{
	transform->pos = Vector2(0.f, 0.f);
	renderer = AC(Renderer);
	animater = AC(Animater);

	animater->Add("WD", "PU03%d", "", 17, 17);
	animater->Add("WDL", "PU03%d", "", 18, 18);
	animater->Add("WL", "PU03%d", "", 19, 19);
	animater->Add("WUL", "PU03%d", "", 20, 20);
	animater->Add("WU", "PU03%d", "", 21, 21);
	animater->Add("WUR", "PU03%d", "", 22, 22);
	animater->Add("WR", "PU03%d", "", 23, 23);
	animater->Add("WDR", "PU03%d", "", 24, 24);
	animater->Play("WD");
	animater->SetDelay(0.01f);

	//renderer->SetMiddleCenter(Vector3(0.f, 35.f, 0.f)0);
	renderer->SetMiddleCenter();

	InitBulletInfo();
}

void PlayerBrownUpBody::Attack(const Vector2 & dir)
{
	if(KEYDOWN(VK_LBUTTON))
	{
		Vector2 vDir = INPUT.GetScrollPos() - transform->worldPos;
		D3DXVec2Normalize(&vDir, &vDir);	
			
		float fDirAngle = atan2f(vDir.y, vDir.x);
		fDirAngle -= D3DXToRadian(5);

		for (int i = 0; i < 10; ++i)
		{
			float fRandomAngle = RandomNum(fDirAngle, fDirAngle + D3DXToRadian(10));
			float fCos = cosf(fRandomAngle), fSin = sinf(fRandomAngle);
			
			vDir = Vector2(fCos, fSin);

			PlayerBullet * player = AddObj(PlayerBullet);
			player->transform->pos = transform->worldPos;

			player->SetBullet(lpMiniMapTex, vDir, 2.f, RandomNum(700.f, 1000.f), fDistance);
		}

		--iNowTanchang;
		lpBulletInfo->SetNowBulletInfo(iNowTanchang);
	}
}
