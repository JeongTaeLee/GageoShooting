#include "DXUT.h"
#include "MonserBullet.h"


MonserBullet::MonserBullet()
{
	tag = "MonsterBullet";
}


MonserBullet::~MonserBullet()
{
}

void MonserBullet::Init()
{
	Bullet::Init();
	lpCollider->SetCollider(Vector2(15, 15), true);
	lpAnimater = AC(Animater);
}

void MonserBullet::OnCollision(Collider * lpCollider)
{
	if (lpCollider->gameObject->tag == "Player")
	{
		AddObj(Effect)->SetEffect(transform->pos, 1.f, "PlayerHitEffect%d", 1, 7);
		SetDestroy();
	}
}
