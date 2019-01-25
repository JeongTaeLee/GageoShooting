#include "DXUT.h"
#include "MissionImage.h"


MissionImage::MissionImage()
	:fAccrue(0.f), fDelay(0.f), fAlpha(0.f)
{
}


MissionImage::~MissionImage()
{
}

void MissionImage::Init()
{
	transform->pos = Vector2(WINSIZEX / 2, WINSIZEY / 2 - 200);

	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, 0.f));

	fDelay = 2.0f;
}

void MissionImage::Update()
{
	fAccrue += Et;

	if (fDelay <= fAccrue)
	{
		fAlpha = LinerInterpolation(fAlpha, 0.f, 0.1f);
		lpUiRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, fAlpha));

		if ((fDelay * 1.3f) <= fAccrue)
		{
			SetDestroy();
		}
	}
	else
	{
		fAlpha = LinerInterpolation(fAlpha, 1.f, 0.02f);
		lpUiRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, fAlpha));
	}
}
