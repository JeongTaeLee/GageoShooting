#include "DXUT.h"
#include "Bar.h"


Bar::Bar()
	:lpUIRenderer(nullptr), fLength(0.f), fMaxLength(0.f), uiTexWidth(0), uiTexHeight(0)
{
}


Bar::~Bar()
{
}

void Bar::UpdateBar(float fNowValue)
{
	lpUIRenderer->SetSrc({ 0, 0, (LONG)(fLength * fNowValue), (LONG)uiTexHeight });
}

void Bar::SetBar(const Vector2 & vPos, texture * tex, float fMaxValue, float fNowValue)
{
	lpUIRenderer = AC(UIRenderer);

	transform->pos = vPos;

	lpUIRenderer->SetTex(tex, true);
	
	fLength		= tex->info.Width / fMaxValue;
	fMaxLength	= tex->info.Width;
	
	uiTexWidth = tex->info.Width;
	uiTexHeight = tex->info.Height;

	lpUIRenderer->SetSrc({ 0, 0, (LONG)(fLength * fNowValue), (LONG)uiTexHeight });

	lpUIRenderer->SetRenderingSort(1);

}
