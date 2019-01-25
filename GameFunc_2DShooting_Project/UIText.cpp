#include "DXUT.h"
#include "UIText.h"


UIText::UIText()
	:str("None"), color(D3DXCOLOR(1.f, 1.f, 1.f, 1.f)), size(0.f)
{
}


UIText::~UIText()
{
}

void UIText::Render(LPD3DXSPRITE sprite)
{
	IMAGE.drawText(sprite, str, transform->worldPos, size, color);
}

