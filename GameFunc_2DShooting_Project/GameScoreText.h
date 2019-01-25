#pragma once
#include "GameObject.h"
class GameScoreText :
	public GameObject
{
private:
	UIText * lpUiText;
public:
	GameScoreText();
	virtual ~GameScoreText();

	virtual void Init()	override;
};

