#include "DXUT.h"
#include "GameVictroyScreen.h"
#include "GameScoreText.h"

GameVictroyScreen::GameVictroyScreen()
{
}


GameVictroyScreen::~GameVictroyScreen()
{
}

void GameVictroyScreen::Init()
{
	transform->pos = Vector2(0.f, 0.f);

	lpUiRenderer = AC(UIRenderer);
	lpUiRenderer->SetTex(LOADTEX("GameVictroy", "./rs/MainManu/게임클리어.png"), false);

	text = OBJECT.AddObject<GameScoreText>(nullptr, this);
	text->transform -> pos = Vector2(720, 375);
}
