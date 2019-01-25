#include "DXUT.h"
#include "Monster01.h"
#include "MonsterBullet01.h"
#include "Player.h"
#include "HpBar.h"

Monster01::Monster01()
{
}


Monster01::~Monster01()
{
}

void Monster01::Init()
{
	Monster::Init();

	lpAnimater->Add("D", "MonsterA_Idle%d" , " ", 1, 10);
	lpAnimater->Add("DL", "MonsterA_Idle%d", " ", 11, 20);
	lpAnimater->Add("L", "MonsterA_Idle%d" , " ", 21, 30);
	lpAnimater->Add("UL", "MonsterA_Idle%d", " ", 31, 40);
	lpAnimater->Add("U", "MonsterA_Idle%d" , " ", 41, 50);
	lpAnimater->Add("UR", "MonsterA_Idle%d", " ", 51, 60);
	lpAnimater->Add("R", "MonsterA_Idle%d" , " ", 61, 70);
	lpAnimater->Add("DR", "MonsterA_Idle%d", " ", 71, 80);
	lpAnimater->Play("D");

	lpAnimater->Add("DIE_D", "MonsterA_Die%d", " ", 1, 10);
	lpAnimater->Add("DIE_DL", "MonsterA_Die%d", " ", 11, 20);
	lpAnimater->Add("DIE_L", "MonsterA_Die%d", " ", 21, 30);
	lpAnimater->Add("DIE_UL", "MonsterA_Die%d", " ", 31, 40);
	lpAnimater->Add("DIE_U", "MonsterA_Die%d", " ", 41, 50);
	lpAnimater->Add("DIE_UR", "MonsterA_Die%d", " ", 51, 60);
	lpAnimater->Add("DIE_R", "MonsterA_Die%d", " ", 61, 70);
	lpAnimater->Add("DIE_DR", "MonsterA_Die%d", " ", 71, 80);
	
	lpAnimater->SetDelay(0.05f);
	lpRenderer->SetMiddleCenter();
	lpCollider->SetCollider(Vector2(200, 200), true);
	
	fHp = 100.f;
	fRgn = 500.f;
	fSpeed = 100.f;

	fAttackDelay = 1.f;
	fAttackAccrue = 0.f;

	iGiveGold = 100;
	iGiveScore = 5;
}

void Monster01::Behavior()
{
	SetDir();

	if (bTargeting)
	{
		fAttackAccrue += Et;
		if (fAttackDelay <= fAttackAccrue)
		{
			fAttackAccrue = 0.f;
			fAttackDelay = RandomNum(0.5f, 1.5f);

			MonsterBullet01 * bullet = AddObj(MonsterBullet01);
			bullet->transform->pos = transform->worldPos;

			vDir = lpPlayer->transform->worldPos - transform->worldPos;
			D3DXVec2Normalize(&vDir, &vDir);

			bullet->SetBullet(lpMiniMapTex, vDir, 5.f, 1000.f, 500.f);
		}
	}
}
