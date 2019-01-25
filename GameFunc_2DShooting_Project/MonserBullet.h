#pragma once
#include "Bullet.h"
class MonserBullet :
	public Bullet
{
protected:
	Animater * lpAnimater;
public:
	MonserBullet();
	virtual ~MonserBullet();

	virtual void Init()	override;
	virtual void OnCollision(Collider * lpCollider) override;
};

