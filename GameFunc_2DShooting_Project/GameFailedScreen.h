#pragma once
#include "GameObject.h"

class GameScoreText;

class GameFailedScreen :
	public GameObject
{
private:
	UIRenderer * lpUiRenderer;
	GameScoreText * lpScoreText;
public:
	GameFailedScreen();
	virtual ~GameFailedScreen();
	
	virtual void Init()	override;
};

