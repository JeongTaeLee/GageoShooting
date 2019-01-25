#include "DXUT.h"
#include "HpBar.h"
#include "Bar.h"

HpBar::HpBar()
{
}


HpBar::~HpBar()
{
}

void HpBar::UpdateHpBar(float fNowHp)
{
	lpInBar->UpdateBar(fNowHp);
}

void HpBar::SetHpBar(const Vector2 & pos, texture * inTex, texture * outTex, float fMaxHp, float fNowHp)
{
	transform->pos = pos;

	lpOutBar = OBJECT.AddObject<Bar>(nullptr, this);
	lpInBar = OBJECT.AddObject<Bar>(nullptr, this);
	
	lpOutBar->transform->pos = pos;
	lpInBar->transform->pos = pos;

	lpOutBar->SetBar(Vector2(0.f, 0.f), outTex, 100, 100);
	lpInBar->SetBar(Vector2(0.f, 0.f), inTex, fMaxHp, fNowHp);
}
