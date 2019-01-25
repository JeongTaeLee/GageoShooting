#include "DXUT.h"
#include "GoldUI.h"
#include "GoldText.h"

GoldUI::GoldUI()
	:lpUiRenderer(nullptr)
{
}


GoldUI::~GoldUI()
{
}

void GoldUI::Init()
{
	lpGoldText = OBJECT.AddObject<GoldText>(nullptr, this);
	lpGoldText->transform->pos = Vector2(110, -27);

	lpUiRenderer	= AC(UIRenderer);
	lpUiRenderer->SetTex(LOADTEX("GoldUI", " "));
}

void GoldUI::SetGold(int iGold)
{
	char str[256];
	sprintf(str, "%05d", iGold);

	lpGoldText->lpUiText->SetStr(str);
}
