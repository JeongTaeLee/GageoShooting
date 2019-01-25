#include "DXUT.h"
#include "Boss.h"
#include "Player.h"
#include "MonsterBullet02.h"
#include "BossZone.h"
#include "PlayerBullet.h"

Boss::Boss()
	:bAttacking(false), bJumpStart(false),  fAttackingDelay(0.f), fAttackingAccrue(0.f), eJumpState(NONE),
	vJumpStartPos(0.f, 0.f), vJumpEndPos(0.f, 0.f), fJumpingAccrue(0.f), fJumpingDelay(3.f), fDownAccrue(0.f), fDownDelay(1.5f),
	fStartAccrue(0.f), fStartDelay(2.f)	, fDieAccrue(0.f), fDieDelay(3.f), bDie(false)
{
}


Boss::~Boss()
{
}

void Boss::Init()
{
	transform->pos = Vector2(1480, 800);

	Monster::Init();

	lpAnimater->Add("D", "Boss%d", " ", 1, 15);
	lpAnimater->Add("DL", "Boss%d", " ", 16, 30);
	lpAnimater->Add("L", "Boss%d", " ", 31, 45);
	lpAnimater->Add("UL", "Boss%d", " ", 46, 60);
	lpAnimater->Add("U", "Boss%d", " ", 61, 75);
	lpAnimater->Add("UR", "Boss%d", " ", 76, 90);
	lpAnimater->Add("R", "Boss%d", " ", 91, 105);
	lpAnimater->Add("DR", "Boss%d", " ", 106, 120);
	lpAnimater->Play("D");

	lpAnimater->Add("JUMP_D", "Boss_Die%d", " ", 1, 10);


	lpAnimater->SetDelay(0.05f);
	lpRenderer->SetMiddleCenter();
	lpCollider->SetCollider(Vector2(100, 100), true);

	fHp = 1000.f;
	fRgn = 600.f;
	fSpeed = 100.f;

	iGiveGold = 100;
	iGiveScore = 50;

	fAttackingDelay = 1.f;
	fAttackingAccrue = 1.f;
}

void Boss::Update()
{
	if (KEYUP(VK_F6))
		bDie = true;

	if (bDie)
	{
		fDieAccrue += Et;

		if (fDieAccrue <= fDieDelay)
		{
			Vector2 StartPos = Vector2(transform->pos.x - 200, transform->pos.y - 200);
			Vector2 EndPos = Vector2(transform->pos.x + 200, transform->pos.y + 200);
		
			Vector2 RandomPos = Vector2(RandomNum(StartPos.x, EndPos.x), RandomNum(StartPos.y, EndPos.y));

			AddObj(Effect)->SetEffect(RandomPos, 1.f, "MonsterHitEffect%d", 1, 6);
			SOUND.DuplicatePlay("Explosion");
			return;
		}
		else
		{
			SCENE.ChanScene("GameVictory");
			SetDestroy();
		}
		
	}


	fStartAccrue += Et;

	if (fStartAccrue <= fStartDelay)
	{
		CAMERA.SetTarget(transform->pos, 0.5f);
	}
	else 
	{
		if (!bTargeting)
			Targeting();

		Behavior();
	}
}



void Boss::Behavior()
{
	if (!bTargeting)
		return;

	if (bHit)
	{
		fHitEffectAcrrue += Et;

		if (fHitEffectAcrrue > fHitEffectDelay)
		{
			lpRenderer->SetColor(D3DCOLOR_XRGB(255, 255, 255));
			bHit = false;
		}
	}

	if (bAttacking)
		OnAttacking();
	else
		UnAttacking();
}

void Boss::UnAttacking()
{
	SetDir();
	if (bAttacking)
		return;

	if (!lpPixelCollider->GetCollision())
	{
		Vector2 vLength = lpPlayer->transform->worldPos - transform->worldPos;
		float fLength = D3DXVec2Length(&vLength);

		if (fLength > fRgn - 300)
		{
			vDir = lpPlayer->transform->worldPos - transform->worldPos;
			D3DXVec2Normalize(&vDir, &vDir);

			transform->pos += vDir * (fSpeed * Et);
			lpPixelCollider->PixelCollision(Vector2(transform->pos.x / PIXELCOLLISION, transform->pos.y / PIXELCOLLISION), vDir, fSpeed);
		}
	}

	fAttackAccrue += Et;

	if (fAttackDelay <= fAttackAccrue)
	{
		eJumpState = NONE;
		bAttacking = true;
	}
}

void Boss::OnAttacking()
{
	Vector2 vJumpEndDir = Vector2(0, 1.f);

	if (eJumpState == NONE)
	{
		eJumpState = JUMPSTART;
		lpAnimater->Play("JUMP_D");
	}
	else if (eJumpState == JUMPSTART)
	{
		if (lpAnimater->GetCount() == 5)
			eJumpState = JUMPING;

		vJumpStartPos = transform->pos;
	}

	else if (eJumpState == JUMPING)
	{
		if (transform->pos.y > vJumpStartPos.y - 1000)
			transform->pos.y -= 2000 * Et;
		else
		{
			transform->pos.x = lpPlayer->transform->pos.x;

			fJumpingAccrue += Et;

			if (fJumpingAccrue >= fJumpingDelay)
			{
				fJumpingAccrue	= 0.f;
				eJumpState	= JUMPEND;
				
				vJumpEndPos = lpPlayer->transform->pos;

				AddObj(BossZone)->SetZone(vJumpEndPos, fDownDelay);

				vJumpEndDir = vJumpEndPos - transform->pos;
				D3DXVec2Normalize(&vJumpEndDir, &vJumpEndDir);
			}
		}
	}

	else if (eJumpState == JUMPEND)
	{
		fDownAccrue += Et;

		if (fDownAccrue <= fDownDelay)
			return;

		transform->pos += vJumpEndDir * (2000 * Et);

		Vector2 vLength = vJumpEndPos - transform->pos;
		float fLenght = D3DXVec2Length(&vLength);
	
		if (fLenght < 50.f)
		{
			fDownAccrue = 0.f;

			lpAnimater->Play("D");
			eJumpState = BACKATTACK;	
		}
		
	}
	
	else if (eJumpState == BACKATTACK)
	{
		Vector2 vDir = lpPlayer->transform->pos - transform->worldPos;
		D3DXVec2Normalize(&vDir, &vDir);

		float fDirAngle = atan2f(vDir.y, vDir.x);
		fDirAngle -= D3DXToRadian(10);

		for (int i = 0; i < 20; ++i)
		{
			float fRandomAngle = RandomNum(fDirAngle, fDirAngle + D3DXToRadian(20));
			float fCos = cosf(fRandomAngle), fSin = sinf(fRandomAngle);

			vDir = Vector2(fCos, fSin);

			MonsterBullet02 * player = AddObj(MonsterBullet02);
			player->transform->pos = transform->worldPos;

			player->SetBullet(lpMiniMapTex, vDir, 2.f, RandomNum(700.f, 1000.f), 800.f);
		}



		bAttacking = false;

		fAttackDelay = 5.f;
		fAttackAccrue = 0.f;
	}
	
	
}

void Boss::OnCollision(Collider * collider)
{
	if (collider->gameObject->tag == "PlayerBullet")
	{
		PlayerBullet * bullet = dynamic_cast<PlayerBullet*>(collider->gameObject);
		fHp -= bullet->GetDamage();

		if (fHp <= 0.f)
		{
			lpPlayer->AddScore(iGiveScore);
			lpPlayer->AddGold(iGiveGold);

			lpCollider->bEnable = false;
			bDie = true;
		}
		else
		{
			lpRenderer->SetColor(D3DCOLOR_XRGB(255, 0, 0));

			fHitEffectAcrrue = 0.f;
			fHitEffectDelay = 0.05f;
			bHit = true;
		}
	}
}
