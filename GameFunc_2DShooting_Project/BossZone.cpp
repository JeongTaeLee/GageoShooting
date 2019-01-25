#include "DXUT.h"
#include "BossZone.h"


BossZone::BossZone()
	:fDelay(0.f), fAccrue(0.f), fColorAccrue(0.f), fColorDelay(0.05f)
{
}


BossZone::~BossZone()
{
}

void BossZone::Init()
{
	lpRenderer = AC(Renderer);
	lpRenderer->SetTex(LOADTEX("BossAttackZone", " "));
}

void BossZone::Update()
{
	fColorAccrue += Et;

	if (fColorDelay <= fColorAccrue)
	{
		fColorAccrue = 0.f;

		if (lpRenderer->GetColor() == D3DXCOLOR(1.f, 1.f, 1.f, 1.f))
			lpRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, 0.f));
		else
			lpRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, 1.f));
	}

	fAccrue += Et;
	if (fAccrue > fDelay)
		SetDestroy();
}

void BossZone::SetZone(Vector2 vPos, float Delay)
{
	transform->pos = vPos;

	fDelay = Delay;
	fAccrue = 0.f;
}
