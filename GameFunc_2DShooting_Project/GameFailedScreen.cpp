#include "DXUT.h"
#include "GameFailedScreen.h"
#include "GameScoreText.h"

GameFailedScreen::GameFailedScreen()
{
}


GameFailedScreen::~GameFailedScreen()
{
}

void GameFailedScreen::Init()
{
	transform->pos = Vector2(0.f, 0.f);

	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetTex(LOADTEX("GameFailedScreen", "./rs/MainManu/게임오버.png"), false);

	lpScoreText = OBJECT.AddObject<GameScoreText>(nullptr, this);
	lpScoreText->transform->pos = Vector2(720, 375);
}
