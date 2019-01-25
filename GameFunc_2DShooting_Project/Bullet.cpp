#include "DXUT.h"
#include "Bullet.h"


Bullet::Bullet()
	:lpRenderer(nullptr), lpPixelCollider(nullptr), vDir(0.f, 0.f), 
	fDamage(0.f), fSpeed(0.f), fMaxDistance(0.f), fAccrueDistance(0.f)
{
}


Bullet::~Bullet()
{
}

void Bullet::Init()
{
	lpRenderer = AC(Renderer);
	lpCollider = AC(Collider);
}

void Bullet::Update()
{
	if (!lpPixelCollider->GetCollision())
	{
		fAccrueDistance += (fSpeed * Et);

		if (fAccrueDistance >= fMaxDistance)
		{
			SetDestroy();
			return;
		}

		transform->pos += vDir * (fSpeed * Et);
		lpPixelCollider->PixelCollision(transform->worldPos / PIXELCOLLISION, vDir, fSpeed);
	}
}

void Bullet::Receive(const string & msg)
{
	if (msg == "PixelCollision")
		SetDestroy();
}

void Bullet::SetBullet(texture * miniMap, const Vector2 & _vDir, float damage, float speed, float _fDistance)
{
	lpPixelCollider = AC(PixelCollider);
	lpPixelCollider->SetCollisionTex(miniMap, WallColliderColor);

	fDamage = damage;
	fSpeed = speed;
	fMaxDistance = _fDistance;

	vDir = _vDir;
}
