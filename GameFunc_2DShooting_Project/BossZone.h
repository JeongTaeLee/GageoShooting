#pragma once
#include "GameObject.h"
class BossZone :
	public GameObject
{
private:
	Renderer * lpRenderer;

	float fDelay;
	float fAccrue;

	float fColorDelay;
	float fColorAccrue;
public:
	BossZone();
	virtual ~BossZone();

	virtual void Init()	override;
	virtual void Update() override;

	void SetZone(Vector2 vPos, float Delay);

};

