#include "DXUT.h"
#include "InfoImage.h"


InfoImage::InfoImage()
	:lpUiRenderer(nullptr), fAlpha(0.f)
{
}


InfoImage::~InfoImage()
{
}

void InfoImage::Init()
{
	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, 1.f));
}

void InfoImage::OnActive()
{
	fAlpha = 0.f;
	lpUiRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, fAlpha));
}

void InfoImage::Update()
{
	fAlpha = LinerInterpolation(fAlpha, 1.f, 0.02f);
	lpUiRenderer->SetColor(D3DXCOLOR(1.f, 1.f, 1.f, fAlpha));
}
