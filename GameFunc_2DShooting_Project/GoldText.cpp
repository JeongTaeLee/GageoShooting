#include "DXUT.h"
#include "GoldText.h"


GoldText::GoldText()
	:lpUiText(nullptr)
{
}


GoldText::~GoldText()
{
}

void GoldText::Init()
{
	lpUiText = AC(UIText);
	lpUiText->SetSize(50);
}
