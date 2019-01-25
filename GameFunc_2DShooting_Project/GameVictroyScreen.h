#pragma once
#include "GameObject.h"

class GameScoreText;

class GameVictroyScreen :
	public GameObject
{
private:
	UIRenderer * lpUiRenderer;
	GameScoreText * text;
public:
	GameVictroyScreen();
	virtual ~GameVictroyScreen();

	virtual void Init()	override;
};

