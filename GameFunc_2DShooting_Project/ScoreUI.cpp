#include "DXUT.h"
#include "ScoreUI.h"
#include "ScoreText.h"

ScoreUI::ScoreUI()
	:lpScoreText(nullptr), lpUiRenderer(nullptr)
{
}


ScoreUI::~ScoreUI()
{
}

void ScoreUI::Init()
{
	lpScoreText = OBJECT.AddObject<ScoreText>(nullptr, this);
	lpScoreText->transform->pos = Vector2(110, -27);

	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetTex(LOADTEX("ScoreUI", " "));
}

void ScoreUI::SetScore(int _iScore)
{
	char str[256];
	sprintf(str, "%05d", _iScore);

	lpScoreText->lpUiText->SetStr(str);
}
