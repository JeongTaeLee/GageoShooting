#pragma once
#include "GameObject.h"

class Bar;

class HpBar :
	public GameObject
{
private:
	Bar * lpInBar;
	Bar * lpOutBar;
public:
	HpBar();
	virtual ~HpBar();

	void UpdateHpBar(float fNowHp);

	void SetHpBar(const Vector2 & pos, texture * inTex, texture * outTex, float fMaxHp, float fNowHp);
};

