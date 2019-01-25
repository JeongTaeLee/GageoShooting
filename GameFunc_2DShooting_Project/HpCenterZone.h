#pragma once
#include "GameObject.h"

class InfoImage;

class HpCenterZone :
	public GameObject
{
private:
	Renderer * lpRenderer;
	Collider * lpCollider;
public:
	HpCenterZone();
	virtual ~HpCenterZone();

	virtual void Init() override;
	virtual void Update() override;

	virtual void OnCollision(Collider * collider) override;
};

