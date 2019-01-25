#include "DXUT.h"
#include "Effect.h"


Effect::Effect()
:lpRenderer(nullptr), lpAnimater(nullptr)
{
}



Effect::~Effect()
{
}

void Effect::SetEffect(const Vector2 & pos, float size, const string & keys, int mn, int mx)
{
	transform->pos = pos;
	transform->scale = Vector2(size, size);

	lpRenderer = AC(Renderer);
	lpAnimater = AC(Animater);
	lpAnimater->SetDelay(0.05);

	lpAnimater->Add("Effect", keys, " ", mn, mx);
	lpAnimater->Play("Effect");

	lpRenderer->SetMiddleCenter();

	lpRenderer->SetYSortEnable(false);
}

void Effect::Receive(const string & msg)
{
	if (msg == "EndAnimation")
	{
		bActive = false;
		SetDestroy();
	}
}
