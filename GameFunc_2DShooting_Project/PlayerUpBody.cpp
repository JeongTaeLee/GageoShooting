#include "DXUT.h"
#include "PlayerUpBody.h"
#include "PlayerBullet.h"
#include "BulletInfo.h"

PlayerUpBody::PlayerUpBody()
	:bReLoad(false), iTotalBullet(0), iNowTanchang(0), iMaxTanchang(0), 
	fReloadDelay(1.f), fReloadAccrue(0.f), fAttackAccrue(0.f), fAttackDelay(0.f)
{
	tag = "PlayerUpBody";

	fDistance = 600.f;

	iTotalBullet = 45;
	iNowTanchang = 7;
	iMaxTanchang = 7;
}


PlayerUpBody::~PlayerUpBody()
{
}

void PlayerUpBody::Init()
{
	transform->pos = Vector2(0.f, 0.f);
	renderer = AC(Renderer);
	animater = AC(Animater);

	animater->Add("WD" ,"PU01%d" , "", 1, 1);
	animater->Add("WDL","PU01%d", "", 2, 2);
	animater->Add("WL" ,"PU01%d" , "", 3, 3);
	animater->Add("WUL","PU01%d", "", 4, 4);
	animater->Add("WU" ,"PU01%d" , "", 5, 5);
	animater->Add("WUR","PU01%d", "", 6, 6);
	animater->Add("WR" ,"PU01%d" , "", 7, 7);
	animater->Add("WDR","PU01%d", "", 8, 8);
	animater->Play("WD");
	animater->SetDelay(0.01f);

	//renderer->SetMiddleCenter(Vector3(0.f, 35.f, 0.f));
	renderer->SetMiddleCenter();

	InitBulletInfo();
}

void PlayerUpBody::Release()
{
	lpBulletInfo->SetDestroy();
}

void PlayerUpBody::Update()
{
	Input();

	if (bReLoad)
	{
		fReloadAccrue += Et;

		if (fReloadAccrue >= fReloadDelay && iTotalBullet > 0)
		{
			if (iTotalBullet > (iMaxTanchang - iNowTanchang))
			{
				iTotalBullet -= (iMaxTanchang - iNowTanchang);
				iNowTanchang = iMaxTanchang;
			}
			else
			{
				iNowTanchang = iTotalBullet;
				iTotalBullet = 0;
			}
			lpBulletInfo->SetBulletInfo(iTotalBullet, iNowTanchang);
			lpBulletInfo->SetNowBulletInfo(iNowTanchang);bReLoad = false;
		}
	}
}

void PlayerUpBody::Input()
{
	Vector2 vDir = INPUT.GetScrollPos() - transform->worldPos;
	D3DXVec2Normalize(&vDir, &vDir);

	float angle = D3DXToDegree(atan2f(vDir.y, vDir.x));

	string str = "None";

	if (0.f < angle && angle <= 22.5f)
		str = "WR";
	else if (22.5f < angle && angle <= 67.5f)
		str = "WDR";
	else if (67.5f < angle && angle <= 112.5f)
		str = "WD";
	else if (112.5f < angle && angle <= 157.5f)
		str = "WDL";
	else if (157.5f < angle && angle <= 180.f)
		str = "WL";
	else if (-180 < angle && angle <= -157.5f)
		str = "WL";
	else if (-157.5f < angle && angle <= -112.5f)
		str = "WUL";
	else if (-112.5f < angle && angle <= -67.5f)
		str = "WU";
	else if (-67.5f < angle && angle <= -22.5f)
		str = "WUR";
	else if (-22.5f < angle && angle <= 0.f)
		str = "WR";

	if (str != animater->GetString())
		animater->Play(str);

	fAttackAccrue += Et;

	if (fAttackDelay <= fAttackAccrue)
	{
		if (bReLoad)
			return;

		Attack(vDir);

		if (!bReLoad && iNowTanchang <= 0)
		{
			bReLoad = true;
			fReloadAccrue = 0.f;
			fReloadDelay = 1.f;
		}
	}

}

void PlayerUpBody::Attack(const Vector2 & vDir)
{
	if (KEYDOWN(VK_LBUTTON))
	{
		fAttackAccrue = 0.f;

		PlayerBullet * player = AddObj(PlayerBullet);
		player->transform->pos = transform->worldPos;
		player->SetBullet(lpMiniMapTex, vDir, 15.f, 1000.f, fDistance);

		CAMERA.StartShake(10.f, 15.f);
	
		--iNowTanchang;
		lpBulletInfo->SetNowBulletInfo(iNowTanchang);
	}
}

void PlayerUpBody::SetMiniMap(texture * tex)
{
	lpMiniMapTex = tex;
}

void PlayerUpBody::InitBulletInfo()
{
	lpBulletInfo = AddObj(BulletInfo);
	lpBulletInfo->SetBulletInfo(iTotalBullet,iNowTanchang);
	lpBulletInfo->transform->pos = Vector2(1184.f, 643.f);
}
