#pragma once
#include "GameObject.h"
class GunCenterZone :
	public GameObject
{
private:
	Renderer * lpRenderer;
	Collider * lpCollider;
public:
	GunCenterZone();
	virtual ~GunCenterZone();

	virtual void Init()	override;

	virtual void OnCollision(Collider * collision) override;
};

