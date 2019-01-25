#include "DXUT.h"
#include "PlayerBullet.h"


PlayerBullet::PlayerBullet()
{
	tag = "PlayerBullet";
}


PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Init()
{
	SOUND.DuplicatePlay("Fire");

	Bullet::Init();

	lpRenderer->SetTex(LOADTEX("PlayerBullet01", " "));
	lpCollider->SetCollider(Vector2(15, 15), true);
}

void PlayerBullet::OnCollision(Collider * lpCollider)
{
	if (lpCollider->gameObject->tag == "Monster")
	{
		AddObj(Effect)->SetEffect(transform->pos, 1.f, "MonsterHitEffect%d", 1, 6);
		SetDestroy();
	}
}
