#include "DXUT.h"
#include "Monster02.h"
#include "Player.h"
#include "MonsterBullet02.h"
#include "HpBar.h"

Monster02::Monster02()
{
}


Monster02::~Monster02()
{
}

void Monster02::Init()
{
	Monster::Init();

	lpAnimater->Add("D", "MonsterB_Idle%d", " ", 1, 15);
	lpAnimater->Add("DL", "MonsterB_Idle%d", " ", 16, 30);
	lpAnimater->Add("L", "MonsterB_Idle%d", " ", 31, 45);
	lpAnimater->Add("UL", "MonsterB_Idle%d", " ", 46, 60);
	lpAnimater->Add("U", "MonsterB_Idle%d", " ", 61, 75);
	lpAnimater->Add("UR", "MonsterB_Idle%d", " ", 76, 90);
	lpAnimater->Add("R", "MonsterB_Idle%d", " ", 91, 105);
	lpAnimater->Add("DR", "MonsterB_Idle%d", " ", 106, 120);
	lpAnimater->Play("D");

	lpAnimater->Add("DIE_D", "MonsterB_Die%d", " ", 1, 10);
	lpAnimater->Add("DIE_DL", "MonsterB_Die%d", " ", 11, 20);
	lpAnimater->Add("DIE_L", "MonsterB_Die%d", " ", 21, 30);
	lpAnimater->Add("DIE_UL", "MonsterB_Die%d", " ", 31, 40);
	lpAnimater->Add("DIE_U", "MonsterB_Die%d", " ", 41, 50);
	lpAnimater->Add("DIE_UR", "MonsterB_Die%d", " ", 51, 60);
	lpAnimater->Add("DIE_R", "MonsterB_Die%d", " ", 61, 70);
	lpAnimater->Add("DIE_DR", "MonsterB_Die%d", " ", 71, 80);

	lpAnimater->SetDelay(0.1f);
	lpRenderer->SetMiddleCenter();
	lpCollider->SetCollider(Vector2(150, 150), true);

	fHp = 200.f;
	fRgn = 500.f;
	fSpeed = 70.f;

	fAttackDelay = 1.f;
	fAttackAccrue = 0.f;

	iGiveGold = 150;
	iGiveScore = 80;
}

void Monster02::Behavior()
{
	SetDir();

	if (bTargeting)
	{
		fAttackAccrue += Et;
		if (fAttackDelay <= fAttackAccrue)
		{
			fAttackAccrue = 0.f;
			fAttackDelay = RandomNum(0.5f, 1.5f);

#pragma region SETFIREPOS
			string str = lpAnimater->GetString();

			float fAngle01 = 0.f;
			float fAngle02 = 0.f;

			if (str == "R")
			{
				fAngle01 = 90;
				fAngle02 = 270;
			}
			else if (str == "DR")
			{
				fAngle01 = 45;
				fAngle02 = 225;
			}
			else if (str == "D")
			{
				fAngle01 = 0;
				fAngle02 = 180;
			}
			else if (str == "DL")
			{
				fAngle01 = 135;
				fAngle02 = 315;
			}
			else if (str == "L")
			{
				fAngle01 = 90;
				fAngle02 = 270;
			}
			else if (str == "L")
			{
				fAngle01 = 90;
				fAngle02 = 270;
			}
			else if (str == "UL")
			{
				fAngle01 = 45;
				fAngle02 = 225;
			}
			else if (str == "U")
			{
				fAngle01 = 0;
				fAngle02 = 180;
			}
			else if (str == "UR")
			{
				fAngle01 = 135;
				fAngle02 = 315;
			}
			else if (str == "R")
			{
				fAngle01 = 90;
				fAngle02 = 270;
			}
#pragma endregion SETFIREPOS

			Vector2 FirePos01;
			FirePos01.x = transform->pos.x + (cosf(D3DXToRadian(fAngle01)) * 100);
			FirePos01.y = transform->pos.y + (sinf(-D3DXToRadian(fAngle01)) * 100);

			Vector2 FirePos02;
			FirePos02.x = transform->pos.x + (cosf(D3DXToRadian(fAngle02)) * 100);
			FirePos02.y = transform->pos.y + (sinf(-D3DXToRadian(fAngle02)) * 100);


			MonsterBullet02 * bullet = AddObj(MonsterBullet02);
			bullet->transform->pos = FirePos01;

			vDir = lpPlayer->transform->worldPos - FirePos01;
			D3DXVec2Normalize(&vDir, &vDir);
			bullet->SetBullet(lpMiniMapTex, vDir, 5.f, 1000.f, 600.f);

			bullet = AddObj(MonsterBullet02);
			bullet->transform->pos = FirePos02;

			vDir = lpPlayer->transform->worldPos - FirePos02;
			D3DXVec2Normalize(&vDir, &vDir);
			bullet->SetBullet(lpMiniMapTex, vDir, 5.f, 1000.f, 600.f);
		}
	}
}
