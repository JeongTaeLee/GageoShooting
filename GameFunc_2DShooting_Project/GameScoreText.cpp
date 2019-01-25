#include "DXUT.h"
#include "GameScoreText.h"


GameScoreText::GameScoreText()
{
}


GameScoreText::~GameScoreText()
{
}

void GameScoreText::Init()
{
	lpUiText = AC(UIText);
	lpUiText->SetStr("03290");
	lpUiText->SetSize(60);
}
