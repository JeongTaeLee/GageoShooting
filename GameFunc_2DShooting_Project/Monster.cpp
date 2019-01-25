#include "DXUT.h"
#include "Monster.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Map.h"

Monster::Monster()
	:lpRenderer(nullptr), lpAnimater(nullptr), lpCollider(nullptr), lpPixelCollider(nullptr),
	lpPlayer(nullptr), lpMiniMapTex(nullptr), vDir(0.f, 0.f), fHp(0.f), fRgn(0.f), fSpeed(0.f),
	bTargeting(false), bHit(false), fHitEffectAcrrue(0.f), fHitEffectDelay(0.f), fAttackAccrue(0.f), 
	fAttackDelay(0.f), iGiveGold(0), iGiveScore(0)
{
	tag = "Monster";
}


Monster::~Monster()
{
	SOUND.DuplicatePlay("Explosion");

	lpMap->MinusMonsterCount();
}

void Monster::Init()
{
	lpPlayer = OBJECT.FindObject<Player>("Player");

	lpRenderer = AC(Renderer);
	lpAnimater = AC(Animater);
	lpCollider = AC(Collider);
	AC(MiniMapUnit)->SetTex(LOADTEX("MiniMap_Monster", " "));
}

void Monster::Release()
{
}

void Monster::Update()
{
	if (KEYDOWN(VK_F1))
		SetDestroy();

	if (!bTargeting)
		Targeting();
	else
	{
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
	}

	if (bHit)
	{
		fHitEffectAcrrue += Et;

		if (fHitEffectAcrrue > fHitEffectDelay)
		{
			lpRenderer->SetColor(D3DCOLOR_XRGB(255, 255, 255));
			bHit = false;
		}
	}


	Behavior();
}

void Monster::Targeting()
{
	if (!lpPlayer)
	{
		lpPlayer = OBJECT.FindObject<Player>("Player");
		return;
	}

	Vector2 vLength = lpPlayer->transform->worldPos - transform->worldPos;
	float fLength = D3DXVec2Length(&vLength);

	if (fRgn > fLength)
		bTargeting = true;
}

void Monster::SetDir()
{
	float angle = D3DXToDegree(atan2f(vDir.y, vDir.x));

	string str = "None";

	if (0.f < angle && angle <= 22.5f)
		str = "R";
	else if (22.5f < angle && angle <= 67.5f)
		str = "DR";
	else if (67.5f < angle && angle <= 112.5f)
		str = "D";
	else if (112.5f < angle && angle <= 157.5f)
		str = "DL";
	else if (157.5f < angle && angle <= 180.f)
		str = "L";
	else if (-180 < angle && angle <= -157.5f)
		str = "L";
	else if (-157.5f < angle && angle <= -112.5f)
		str = "UL";
	else if (-112.5f < angle && angle <= -67.5f)
		str = "U";
	else if (-67.5f < angle && angle <= -22.5f)
		str = "UR";
	else if (-22.5f < angle && angle <= 0.f)
		str = "R";

	if (str != lpAnimater->GetString())
		lpAnimater->Play(str);
}

void Monster::SetMiniMap(texture * tex)
{
	lpPixelCollider = AC(PixelCollider);
	lpPixelCollider->SetCollisionTex(tex, WallColliderColor);
	lpMiniMapTex = tex;
}

void Monster::SetMap(Map * map)
{
	lpMap = map;
}

void Monster::OnCollision(Collider * collider)
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
			SetDestroy();


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

