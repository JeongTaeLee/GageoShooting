#include "DXUT.h"
#include "ScoreText.h"


ScoreText::ScoreText()
	:lpUiText(nullptr)
{
}


ScoreText::~ScoreText()
{
}

void ScoreText::Init()
{
	lpUiText = AC(UIText);
	lpUiText->SetSize(50);
}
