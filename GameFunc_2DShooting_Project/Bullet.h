#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
protected:
	Renderer * lpRenderer;
	PixelCollider * lpPixelCollider;
	Collider * lpCollider;

	Vector2 vDir;

	float fMaxDistance;
	float fAccrueDistance;

	float fDamage;
	float fSpeed;
public:
	Bullet();
	virtual ~Bullet();

	virtual void Init()	override;
	virtual void Update()	override;
	virtual void Receive(const string & msg) override;

	void SetBullet(texture * miniMap, const Vector2 & vDir, float damage, float speed, float fDistance);

	float GetDamage() { return fDamage; }
};

